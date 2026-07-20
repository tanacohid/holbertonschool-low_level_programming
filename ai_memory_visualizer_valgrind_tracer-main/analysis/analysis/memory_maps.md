# Memory Maps and Low-Level Runtime Analysis

## Project Overview
This document presents the detailed memory analysis for Task 0 (**AI Memory Visualizer**). It details step-by-step stack frame allocations, heap memory management, pointer aliasing, object lifetimes, and a critical analysis of AI-generated memory models based on actual runtime behavior.

---

## 1. Stack Memory Analysis (`stack_example.c`)

### 1.1 Execution Walkthrough & Stack Frame Layout
`stack_example.c` demonstrates recursive function calls and local variable allocation on the stack. Below is the concrete address tracking obtained from execution:

| Depth | Function / Marker Address | `local_int` Address (`p_local`) | `local_int` Value | `local_buf` Address | `local_buf[0]` | Stack Direction |
| :---: | :-----------------------: | :-----------------------------: | :---------------: | :-----------------: | :------------: | :-------------: |
| **0** | `&marker`: `0x7fffd27ea734` | `0x7fffd27ea6e4` | `100` | `0x7fffd27ea6f0` | `'A'` | Higher memory |
| **1** | `&marker`: `0x7fffd27ea704` | `0x7fffd27ea6b4` | `101` | `0x7fffd27ea6c0` | `'B'` | $\downarrow$ |
| **2** | `&marker`: `0x7fffd27ea6d4` | `0x7fffd27ea684` | `102` | `0x7fffd27ea690` | `'C'` | $\downarrow$ |
| **3** | `&marker`: `0x7fffd27ea6a4` | `0x7fffd27ea654` | `103` | `0x7fffd27ea660` | `'D'` | Lower memory |

### 1.2 Low-Level Mechanics & Lifetime Breakdown
- **Stack Growth Direction:** Addresses decrease as depth increases (`0x7fffd27ea734` $
ightarrow$ `0x7fffd27ea6a4`). This confirms that the stack grows **downward** toward lower memory addresses on x86_64 Linux.
- **Stack Frame Creation:**
  1. `main()` calls `walk_stack(0, 3)`.
  2. For each recursive call `walk_stack(depth, max_depth)`:
     - A new frame is pushed onto the stack containing `depth`, `max_depth`, and local variable `marker`.
     - `walk_stack` calls `dump_frame()`, which pushes another frame containing `local_int`, `local_buf[16]`, and pointer `p_local`.
- **Pointer Behavior:** `p_local` stores `&local_int`, which is local to `dump_frame()`. Because `p_local` points directly to an address inside `dump_frame`'s stack frame, its target is valid **only while `dump_frame()` is executing**.
- **Frame Destruction & Unwinding:**
  - Upon returning from `dump_frame()`, its stack frame is popped (deallocated automatically by moving the stack pointer).
  - When `depth == 3` is reached, recursion terminates and `walk_stack()` unwinds. As each recursive frame returns, its local variables (`marker`, `depth`) reach the end of their lifetime.

---

## 2. Heap Memory & Leak Analysis (`heap_example.c`)

### 2.1 Heap Allocation Map & Address Tracking
Execution output from `./heap_example`:
- `alice` struct address: `0x58e7c228e420` | `alice->name` buffer: `0x58e7c228e440` | `age`: `30`
- `bob` struct address: `0x58e7c228e460` | `bob->name` buffer: `0x58e7c228e480` | `age`: `41`

```
  STACK (main)                         HEAP MEMORY
+--------------+               +--------------------------+
| alice        | ------------> | Struct Person (alice)    |
| (0x58e...420)|               | - name: 0x58e7c228e440 --|----> [ "Alice " ] (Heap Block)
+--------------+               | - age: 30                |
| bob          |               +--------------------------+
| (0x58e...460)| --+--------------+    \          +--------------------------+
                     `-------> | Struct Person (bob)      |
                               | - name: 0x58e7c228e480 --|----> [ "Bob " ] (Heap Block)
                               | - age: 41                |
                               +--------------------------+
```

### 2.2 Ownership & Memory Leak Breakdown
- **`bob` Deallocation (Correct):**
  - Line 66: `free(bob->name);` frees the dynamic string buffer (`"Bob "`).
  - Line 67: `free(bob);` frees the `Person` struct block.
  - **Result:** Complete memory release.
- **`alice` Deallocation (Bug / Memory Leak):**
  - Line 69: Calls `person_free_partial(alice);`.
  - Inside `person_free_partial()`:
    ```c
    void person_free_partial(Person *p) {
        if (!p) return;
        free(p); // FREES THE STRUCT, BUT NOT p->name!
    }
    ```
  - **Defect:** `free(p)` frees the `Person` struct containing the pointer `name`. However, the dynamically allocated memory block at `0x58e7c228e440` storing `"Alice "` was never freed.
  - **Result:** The memory address `0x58e7c228e440` becomes **orphaned**. There are no longer any pointers storing its address, making it impossible to free later. Valgrind flags this as a **Definitely Lost** memory leak.

---

## 3. Pointer Aliasing & Use-After-Free (`aliasing_example.c`)

### 3.1 Aliasing & Lifecycle Mechanics
1. **Allocation:** `a = make_numbers(5);` allocates an array of 5 integers on the heap (`5 * sizeof(int) = 20 bytes`). `a` holds the address of this block.
2. **Aliasing:** `b = a;` copies the address stored in `a` into pointer variable `b`.
   - Both `a` and `b` now point to the exact same memory address on the heap.
3. **Deallocation:** `free(a);`
   - The memory block allocated on the heap is marked as free/available by the memory manager.
   - **Crucial Note:** `a` and `b` still store the old address. They are now both **dangling pointers**.
4. **Invalid Access (Use-After-Free):**
   - Line 42: `printf("reading b[2]=%d
", b[2]);` $
ightarrow$ **Invalid Read** of size 4.
   - Line 44: `b[3] = 1234;` $
ightarrow$ **Invalid Write** of size 4.

---

## 4. Crash Analysis (`crash_example.c`)

### 4.1 Causal Chain to Segmentation Fault
1. **Invocation:** `main()` calls `allocate_numbers(0)` with `n = 0`.
2. **Condition Check:** Inside `allocate_numbers()`:
   ```c
   if (n <= 0) return NULL;
   ```
   Because `n = 0`, the function immediately returns `NULL` (`(void*)0`).
3. **Assignment:** `nums` in `main()` is assigned `NULL`.
4. **Dereference:** Line 32 executes `nums[0] = 42;` which is equivalent to `*(NULL + 0) = 42`.
5. **Hardware/OS Fault:**
   - Address `0x0` lies in a restricted/unmapped page of virtual address space.
   - The CPU Memory Management Unit (MMU) detects an invalid page table translation and triggers a hardware trap.
   - The OS kernel catches the trap and sends a `SIGSEGV` signal to the process, terminating execution with a **Segmentation Fault**.

---

## 5. AI Explanation Evaluation & Correction

### 5.1 Misleading AI Hypothesis
> **AI Explanation:**  
> *"In `aliasing_example.c`, when `free(a)` is called, C automatically deletes the heap block and resets the pointer `a` to `NULL`. Because `b` was set equal to `a`, `b` also becomes `NULL`. The program then crashes with a segmentation fault when trying to execute `b[3] = 1234` because you cannot write to `NULL`."*

### 5.2 Technical Evaluation & Correction
The AI explanation contains **three fundamental misconceptions** regarding low-level C memory management:

1. **Incorrect Assumption 1: `free()` resets pointers to `NULL`.**
   - **Correction:** In C, parameters are passed by value. `free(a)` receives a copy of the address stored in `a`. The function `free()` deallocates the heap memory region but **does not and cannot modify the pointer variable `a` itself**. `a` continues to hold the original memory address.

2. **Incorrect Assumption 2: Assigning `b = a` links the pointers dynamically.**
   - **Correction:** Pointer assignment `b = a` copies the bit pattern (the numerical memory address) stored in `a` into variable `b`. They are two independent stack variables. Even if `a` were set to `NULL`, `b` would retain its previous memory address value.

3. **Incorrect Assumption 3: Accessing freed memory (`b[3] = 1234`) always causes an immediate Segmentation Fault.**
   - **Correction:** Accessing freed heap memory is **Undefined Behavior (UB)**, not an automatic crash. In many runtimes, writing through a dangling pointer succeeds silently, corrupting heap metadata or other data structures, and only crashes later when `malloc` or `free` is called again. Valgrind detects this via shadow memory tracking (`Invalid write of size 4`), even when the program does not crash outright.