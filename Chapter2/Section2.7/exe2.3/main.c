#include <stdio.h>
/*
 * Exercise 2.3. Write the function htoi(s), which converts a string of hexadecimal digits (including an optional 0x or 0X)
 * into its equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F.
 */

#define MAXLINE 1000

int htoi(char s[]);

int main()
{
    char s[MAXLINE];
    int c, i = 0, j;
    
    while ((c = getchar()) != EOF)
    {
        s[i]  = c;
        ++i;
    }
    
    j = htoi(s);
    
    printf("The converted integer value is %d\n", j);
    return 0;
}

int htoi(char s[])
{
    int i, j, n;
    
    n = 0;
    for (i = 2; (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'f') || (s[i] >= 'A' && s[i] <= 'F'); ++i)
    {
        if (s[i] >= '0' && s[i] <= '9')
            j = s[i] - '0';
        else if (s[i] >= 'a' && s[i] <= 'f')
            j = s[i] - 'a' + 10;
        else if (s[i] >= 'A' && s[i] <= 'F')
            j = s[i] - 'A' + 10;
        n = 16 * n + j;
    }
    return n;
}
