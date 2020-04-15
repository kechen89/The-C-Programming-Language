#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Exercise 3.6. Write a version of itoa that accepts three arguments instead of two. The third argument is a minimum field width;
 * the converted number must be padded with blanks on the left if necessary to make it wide enough.
 */

#define MAXLINE 1000

void itoa3(int n, char s[], int w);
void reverse(char s[]);

int main()
{
    int n, w;
    char s[MAXLINE];
    printf ("Input an integer\n");
    scanf("%d", &n);
    
    printf ("Input the minimum field width\n");
    scanf("%d", &w);
    
    itoa3(n, s, w);
    
    printf("The converted string is:\n%s\n",s);
    return 0;
}

void itoa3(int n, char s[], int w)
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
    
    for (; i < w; ++i)
    {
        s[i] = ' ';
    }
    
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
