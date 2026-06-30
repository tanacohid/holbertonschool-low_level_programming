#include <stdio.h>
#include <time.h>

#define DATASET_SIZE 50000
#define SEED_VALUE 42u

static int dataset[DATASET_SIZE];

static unsigned int next_value(unsigned int *state)
{
    *state = (*state * 1103515245u) + 12345u;
    return *state;
}

static void build_dataset(void)
{
    unsigned int state;
    int i;

    state = SEED_VALUE;

    for (i = 0; i < DATASET_SIZE; i++)
        dataset[i] = (int)(next_value(&state) % 100000);
}

static void process_dataset(void)
{
    int i;
    int v;

    for (i = 0; i < DATASET_SIZE; i++)
    {
        v = dataset[i];
        v = (v * 3) + (v / 7) - (v % 11);
        if (v < 0)
            v = -v;
        dataset[i] = v;
    }
}

static unsigned long reduce_checksum(void)
{
    unsigned long sum;
    int i;

    sum = 0;
    for (i = 0; i < DATASET_SIZE; i++)
        sum = (sum * 131ul) + (unsigned long)dataset[i];

    return sum;
}

int main(void)
{
	clock_t tms;
	clock_t tps2;
	clock_t tps1;
	clock_t tps;
	clock_t total_start;
	clock_t total_end;
    unsigned long checksum;

    /* Students must add clock-based timing and print required lines. */
	total_start = clock();
	tps = clock();
	build_dataset();
	tps = clock() - tps;
	tps1 = clock();
    process_dataset();
	tps1 = clock() - tps1;
	tps2 = clock();
    checksum = reduce_checksum();
	tps2 = clock() - tps2;
    if (checksum == 0ul)
        printf("impossible\n");

    /* Required output (exact format, no extra lines):
     * TOTAL seconds: <float>
     * BUILD_DATA seconds: <float>
     * PROCESS seconds: <float>
     * REDUCE seconds: <float>
     */
	total_end = clock();
	tms = total_end - total_start;
	printf("TOTAL seconds: %.6f\n", (float)tms / CLOCKS_PER_SEC);
	printf("BUILD_DATA seconds: %.6f\n", (float)tps / CLOCKS_PER_SEC);
	printf("PROCESS seconds: %.6f\n", (float)tps1 / CLOCKS_PER_SEC);
	printf("REDUCE seconds: %.6f\n", (float)tps2 / CLOCKS_PER_SEC);
    return 0;
}