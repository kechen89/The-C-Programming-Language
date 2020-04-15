#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Exercise 3.4. In a two's complement number representation, our version of itoa does not handle the largest negative number,
 * that is, the value of n equal to -(2^(wordsize-1)). Explain why not. Modify it to print that value correctly, regardless of
 * the machine on which it runs.
 */

#define MAXLINE 1000

void itoa_kr(int n, char s[]);
void myitoa(int n, char s[]);
void reverse(char s[]);

int main()
{
    int n;
    char s[MAXLINE];
    printf("Size of int is %lu bytes\n",sizeof(int));
    printf ("Input an integer\n");
    scanf("%d", &n);
    myitoa(n, s);
    
    printf("The converted string is %s\n",s);
    return 0;
}

/* itoa_kr: convert n to characters in s (The C programming language, Second Edition) */
/* does not handle the largest negative integer number (-2147483648) in two's complement number machine */
void itoa_kr(int n, char s[])
{
    int i, sign;
    
    if ((sign = n) < 0)            /* record sign */
        n = -n;                    /* make n positive (the number in memory will overflow if n = -2147483648), -(-2147483648) = -2147483648 */
    i = 0;
    
    do {                           /* generate digits in reverse order */
        s[i++] = n % 10 + '0';     /* get next digit */
    } while ((n /= 10) > 0);         /* delete it */

    
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

/* myitoa: convert n to characters in s */
/* can handle the largest negative integer number (-2147483648) in two's complemet number machine */
void myitoa(int n, char s[])
{
    int i, sign = 1;
    
    if (n < 0)                     /* record sign */
        sign = -1;                    /* make n positive */
    i = 0;
    
    do {                           /* generate digits in reverse order */
        s[i++] = abs(n % 10) + '0';     /* get next digit */
    } while (abs(n /= 10) > 0);         /* delete it */

    
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;
    
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
