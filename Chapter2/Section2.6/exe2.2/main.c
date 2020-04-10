#include <stdio.h>
/*
 * Exercise 2.2. Write a loop equivalent to the for loop above without using && or ||.
 * for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
 *     s[i] = c;
 */

#define MAXLINE 1000                         /* maximum input line size */

int get_line(char line[], int lim);
void copy(char to[], char from[]);

/* print longest input line */

int main()
{
    int len;                           /* current line length */
    int max;                           /* maximum length seen so far */
    char line[MAXLINE];                /* current input line */
    char longest[MAXLINE];             /* longest line saved here */
    
    max = 0;
    
    while ( (len = get_line(line, MAXLINE)) > 0)
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    if (max > 0)    /* there was a line */
        printf("%s", longest);
    return 0;
}

/* get_line: read a line into s, return length */

int get_line(char line[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1; ++i)
    {
        if ( (c = getchar()) != EOF )
        {
            if ( c != '\n')
                line[i] = c;
            else
                break;
        }
        else
            break;
    }
    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
