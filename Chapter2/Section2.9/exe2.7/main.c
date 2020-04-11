#include <stdio.h>
/*
 * Exercise 2.7. Write a function invert(x, p, n) that returns x with the n bits that begin at position p inverted
 * (i.e. 1 changed into 0 and vice versa), leaving the others unchanged.
 */

unsigned invert(unsigned x, int p, int n);

int main()
{
    unsigned x, y;
    
    printf("Enter an unsigned integers:\n");
    scanf("%u", &x);
    printf("The entered unsigned integer is:\n%u\n", x);
    
    y = invert(x, 4, 3);
    
    printf("The unsigned integer x with the n bits that begin at p inverted is:\n%u\n", y);
    
    return 0;
}

unsigned invert(unsigned x, int p, int n)
{
    return ( x ^ ~(~0 << n) << (p + 1 - n)  );
}
