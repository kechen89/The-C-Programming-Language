#include <stdio.h>
/*
 * Exercise 2.9. In a two's complement number system, x &= (x - 1) deletes the rightmost 1-bit in x. Explain why. Use this observation
 * to write a faster version of bitcount.
 */

/* The C Answer Book, Second Edition, 1989 */

int bitcount(unsigned x);

int main()
{
    unsigned x, n;
    
    printf("Enter an unsigned integers:\n");
    scanf("%u", &x);
    
    printf("The entered unsigned integer is:\n%u\n", x);
    
    n = bitcount(x);
    
    printf("The number of 1-bit in the unsigned integer is:\n%u\n", n);
    
    return 0;
}

/* bitcount: count 1 bits in x - faster version */
int bitcount(unsigned x)
{
    int b;
    
    for (b = 0; x != 0; x &= x - 1)
        ++b;
    return b;
}
