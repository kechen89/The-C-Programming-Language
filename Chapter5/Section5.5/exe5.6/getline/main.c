#include <stdio.h>
#include <ctype.h>
#include <string.h>
/* Exercise 5.6. Rewrite appropriate programs from earlier chapters and exercises
 * with pointers instead of array indexing. Good possibilities include getline (Chapter 1 and 4),
 * atoi, itoa, and their variants (Chapters 2, 3, and 4), reverse (Chapter 3), and strindex and
 * getop (Chapter 4).
*/

#define MAXLINE 1000          /* maximum input line size */

int getline_ptr(char *s, int lim);

int getline_kr(char s[], int lim);

int main()
{
    int len, n;
    char line[MAXLINE];
    
    printf("Enter text line by line \n");
    while ( (len = getline_ptr(line, MAXLINE)) > 0 )
        printf("The input line is %s  its length is %d \n", line, len);
    
    return 0;
}

/* getline_ptr: pointer version of read a line into s, return length */
int getline_ptr(char *s, int lim)
{
    int c;
    char *sbeg = s;
    
    while (lim-- > 1 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - sbeg;
}

/* getline_kr: read a line into s, return length */
int getline_kr(char s[], int lim)
{
    int i, c;
    
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    
    if (c == '\n')
    {
        s[i] = c;
        i++;
    }
        
    s[i] = '\0';
    
    return i;
}
