#include <stdio.h>
/* Exercise 5.6. Rewrite appropriate programs from earlier chapters and exercises
 * with pointers instead of array indexing. Good possibilities include getline (Chapter 1 and 4),
 * atoi, itoa, and their variants (Chapters 2, 3, and 4), reverse (Chapter 3), and strindex and
 * getop (Chapter 4).
*/

#define MAXLINE 1000               /* maximum input line length */

int get_line(char s[], int lim);
int strindex(char s[], char t[]);
int strindex_ptr(char *s, char *t);

char pattern[] = "ould";       /* pattern to search for */

/* find all lines matching pattern */

int main()
{
    char line[MAXLINE];
    int found = 0;
    
    while (get_line(line, MAXLINE) > 0)
        //if (strindex(line, pattern) >= 0)
        if (strindex_ptr(line, pattern) >= 0)
        {
            printf("%s\n", line);
            found++;
        }
    return found;
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

/* strindex_ptr: pointer version of return index of t in s, -1 if none */
int strindex_ptr(char *s, char *t)
{
    char *q;
    char *s_beg = s;
    char *t_beg = t;
    
    for (; *s != '\0'; s++)
    {
        for (q = s, t = t_beg; *t != '\0' && *q == *t; q++, t++)
            ;
        if (t != t_beg && *t == '\0')
            return s - s_beg;
    }
    return -1;
}
