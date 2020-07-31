#include <stdio.h>
#include <ctype.h>
#include <string.h>
/* Exercise 5.6. Rewrite appropriate programs from earlier chapters and exercises
 * with pointers instead of array indexing. Good possibilities include getline (Chapter 1 and 4),
 * atoi, itoa, and their variants (Chapters 2, 3, and 4), reverse (Chapter 3), and strindex and
 * getop (Chapter 4).
*/

#define MAXLINE 1000          /* maximum input line size */

void reverse_ptr(char *s);

void reverse_kr(char s[]);

int main()
{
    int len, n;
    
    char s[MAXLINE];
    printf("Enter a string \n");
    scanf("%s", s);
    
    reverse_ptr(s);
    printf("The reversed string is %s\n", s);
    
    return 0;
}


/* reverse_kr: reverse string s in place */
void reverse_kr(char s[])
{
    int i, j;
    int c;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* reverse_ptr: pointer version of reverse string s in place */
void reverse_ptr(char *s)
{
    int c;
    char *t;

    for (t = s + strlen(s) - 1; s < t; s++, t--)
    {
        c = *s;
        *s = *t;
        *t = c;
    }
}



