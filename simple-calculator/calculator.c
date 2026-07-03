#include <stdio.h>
int main (void)
{
	int choice = 1;
	
	int a = 0;
	int b = 0;
	int result = 0;
	
	printf ("simple Calculator\n");

	while (choice != 0)
	{
		if (choice > -1 && choice < 5)
		{
			printf ("1) add\n2) Substact\n3) Multiply\n4) Divide\n0) Quit\n");
		}
		printf ("choice ?\n");
		scanf ("%d", &choice);
		if (choice < 0 || choice > 4)
		{
			printf ("Invalid choice");
		}
		if (choice == 0)
		{
			printf ("bye!\n");
		}
		else if (choice == 1)
		{
			printf ("A: ");
			scanf("%d", &a);
			printf ("B: ");
			scanf("%d", &b);
			result = a + b;
			printf("Result = %d\n", result);
		}
		else if (choice == 2)
		{
			printf ("A: ");
			scanf("%d", &a);
			printf ("B: ");
			scanf("%d", &b);
			result = a - b;
			printf("Result = %d\n", result);
		}
		else if (choice == 3)
		{
			printf ("A: ");
			scanf("%d", &a);
			printf ("B: ");
			scanf("%d", &b);
			result = a * b;
			printf("Result = %d\n", result);
		}
		else if (choice == 4)
		{
			printf ("A: ");
			scanf("%d", &a);
			printf ("B: ");
			scanf("%d", &b);
			if (b == 0)
			{
				printf("Error: division by zero");
			}
			result = a / b;
			printf("Result = %d\n", result);
		}
	}
	return (0);
}
