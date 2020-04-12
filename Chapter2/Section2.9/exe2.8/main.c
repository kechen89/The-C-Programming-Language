#include <stdio.h>
/*
 * Exercise 2.8. Write a function rightrot(x, n) that returns the value of the integer x rotated to the right by n bit positions.
 */

/* The C Answer Book, Second Edition, 1989 */

unsigned rightrot(unsigned x, int n);
int wordlength();

int main()
{
    unsigned x, y, n;
    
    printf("Enter an unsigned integers:\n");
    scanf("%u", &x);
    printf("Enter an integer n as bit positions:\n");
    scanf("%u", &n);
    printf("The entered unsigned integer and bit positions are:\n%u %u\n", x, n);
    
    y = rightrot(x, n);
    
    printf("The value of usigned x rotated to the right by n bit positions is:\n%u\n", y);
    
    return 0;
}

/* rightrot: rotate x to the right by n positions */
unsigned rightrot(unsigned x, int n)
{
    int rbit;                   /* rightmost bit */
    
    while (n-- > 0)
    {
        rbit = (x & 1) << (wordlength() - 1);
        x = x >> 1;            /* shift x one position right */
        x = x | rbit;          /* complete one rotation */
    }
    return x;
}

/* wordlength: computes word length of the machine */
int wordlength()
{
    int i;
    unsigned v = (unsigned) ~0;
    
    for (i = 1; (v = v >> 1) > 0; i++)
        ;
    return i;
}
