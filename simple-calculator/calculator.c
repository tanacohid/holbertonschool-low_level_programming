#include <stdio.h>
int main (void)
{
    int choice = 1;
    /**
    * int - a; b
    *
     */
    int a = 0;
    int b = 0;
    int result = 0;

    printf ("simple Calculator\n");

    while (choice != 0)
    {
        printf ("1) add\n2) Substact\n3) Multiply\n4) Divide\n0) Quit\n")
        printf ("choice ?\n")
        scanf ("%d", &choice);
        if (choice == 0)
        {
            printf ("bye!");
        }
    }
    return (0);
}