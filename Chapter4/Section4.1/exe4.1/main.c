#include <stdio.h>
/*
 * Exercise 4.1. Write the function strrindex(s,t), which returns the position of the rightmost occurence of t in s, or -1 if there is none.
 */

#define MAXLINE 1000               /* maximum input line length */

int get_line(char s[], int lim);
int strindex(char s[], char t[]);
int strrindex(char s[], char t[]);

char pattern[] = "ould";       /* pattern to search for */

/* find all lines matching pattern */

int main()
{
    char line[MAXLINE];
    int pos, found = 0;
    
    while (get_line(line, MAXLINE) > 0)
        if ((pos = strrindex(line, pattern)) >= 0)
        {
            printf("%s", line);
            printf("\nThe position of rightmost occurrence is %d\n",pos);
            found++;
        }
    return 0;
}

/* get_line: get line into s, return length */
int get_line(char s[], int lim)
{
    int c, i;
    
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n' )
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
    int i, j, k;
    
    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

/* strrindex: return the position of the rightmost occurrence of t in s, -1 if none */
int strrindex(char s[], char t[])
{
    int i, j, k, pos = -1;
    
    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            pos = i;
    }
    return pos;
}
