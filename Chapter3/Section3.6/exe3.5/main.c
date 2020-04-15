#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Exercise 3.5. Write the function itob(n,s,b) that converts the integer n into a base b character representation in the string s.
 * In particular, itob(n,s,16) formats n as a hexadecimal integer in s.
 */

#define MAXLINE 1000

void itob(int n, char s[], int b);
void reverse(char s[]);

int main()
{
    int n, b;
    char s[MAXLINE];
    printf("Size of int is %lu bytes\n",sizeof(int));
    printf ("Input an integer\n");
    scanf("%d", &n);
    
    printf ("Input an base character\n");
    scanf("%d", &b);
    
    itob(n, s, b);
    
    printf("The converted string is %s\n",s);
    return 0;
}

void itob(int n, char s[], int b)
{
    int i, sign = 1;
    
    if (n < 0)                        /* record sign */
        sign = -1;                    /* make n positive */
    
    i = 0;
    do {                               /* generate digits in reverse order */
        if (abs(n % b) >= 0 && abs(n % b) <= 9)
            s[i++] = abs(n % b) + '0';     /* get next digit */
        else if (abs(n % b) >= 10 && abs(n % b) <= 15)
            s[i++] = abs(n % b) - 10 + 'a';
    } while (abs(n /= b) > 0);         /* delete it */
    
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
