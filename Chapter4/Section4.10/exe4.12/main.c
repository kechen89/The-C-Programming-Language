#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Exercise 4.12. Adapt the ideas of printd to write a recursive version of itoa; that is, convert an integer into a string by
 * calling a recursive routine.
 */

#define MAXLINE 1000

void my_itoa(int n, char s[]);

int i = 0;

int main()
{
    int n;
    char s[MAXLINE];
    printf ("Input an integer\n");
    scanf("%d", &n);
    
    my_itoa(n, s);
    
    printf("The converted string is:\n%s\n",s);
    return 0;
}

/* my_itoa: convert an integer into a string by recursion */
void my_itoa(int n, char s[])
{
    
    if (n < 0)
    {
        s[0] = '-';
        n = -n;
        ++i;
    }
    
    if (n / 10)
        my_itoa(n/10, s);
    
    s[i++] = n % 10 + '0';
    
    s[i] = '\0';
}
