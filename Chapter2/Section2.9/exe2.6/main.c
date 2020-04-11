#include <stdio.h>
/*
 * Exercise 2.6. Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position p set to the rightmost n bits of y,
 * leaving the other bits unchanged.
 */

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
    unsigned x, y, z;
    
    printf("Enter two unsigned integers:\n");
    scanf("%u %u", &x, &y);
    printf("The entered unsigned integer is:\n%u %u\n", x, y);
    
    z = setbits(x, 4, 3, y);
    
    printf("The unsigned number x with the n bits that begin at position p set to the rightmost n bits of y is:\n%u\n", z);
    
    return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return ( (x & ~(07 << (p + 1 - n))) | (y & ~(~0 << n)) << (p + 1 - n));
}
