#include <stdio.h>
2	
3	int sum_to_n(int n)
4	{
5	    int i;
6	    int sum = 0;
7	
8	    for (i = 1; i <= n; i++)
9	        sum += i;
10	
11	    return (sum);
12	}
13	
14	/* -- DO NOT Modify the code below this line -- */
15	
16	int main(void)
17	{
18	    printf("%d\n", sum_to_n(10));
19	    return 0;
20	}