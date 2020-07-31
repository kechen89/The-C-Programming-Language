#include <stdio.h>
#include <ctype.h>
#include <string.h>
/* Exercise 5.6. Rewrite appropriate programs from earlier chapters and exercises
 * with pointers instead of array indexing. Good possibilities include getline (Chapter 1 and 4),
 * atoi, itoa, and their variants (Chapters 2, 3, and 4), reverse (Chapter 3), and strindex and
 * getop (Chapter 4).
*/

#define MAXLINE 1000          /* maximum input line size */

int atoi_ptr(char *s);

int atoi_kr(char s[]);

int main()
{
    int len, n;
    
    char s[MAXLINE];
    printf("Enter a string of integers \n");
    scanf("%s", s);
    printf("Convert to integer %d \n", atoi_ptr(s));
    
    return 0;
}

/* atoi_ptr: pointer version of convert s to integer; version 2 */
int atoi_ptr(char *s)
{
    int sign, i, n;
    
    for ( ; isspace(*s); s++)    /* skip white space */
        ;
    
    sign = (*s == '-') ? -1 : 1;
    
    if (*s == '+' || *s == '-')    /* skip sign */
        s++;
    
    for (n = 0; isdigit(*s); s++)
        n = 10 * n + (*s - '0');
    
    return sign * n;
}

/* atoi_kr: convert s to integer; version 2 */
int atoi_kr(char s[])
{
    int sign, i, n;
    
    for (i = 0; isspace(s[i]); i++)    /* skip white space */
        ;
    
    sign = (s[i] == '-') ? -1 : 1;
    
    if (s[i] == '+' || s[i] == '-')    /* skip sign */
        i++;
    
    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');
    
    return sign * n;
}


