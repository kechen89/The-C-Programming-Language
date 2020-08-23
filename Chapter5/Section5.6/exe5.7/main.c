#include <stdio.h>
#include <string.h>
#include <stdlib.h> /* for malloc */
/* Exercise 5.7. Rewrite readlines to store lines in an array supplied by main, rather than calling alloc to
 * maintain storage. How much faster is the program?
*/

#define MAXLINES 5000      /* max number of lines to be sorted */
#define MAXLEN 1000    /* max length of any input line */

char *lineptr[MAXLINES];   /* pointers to text lines */

int readlines(char *lineptr[], char *p, int nlines);

void writelines(char *lineptr[], int nlines);

void qsort_kr(char *lineptr[], int left, int right);

/* sort input lines */
int main()
{
    int nlines;              /* number of input lines read */
    char p[MAXLINES * MAXLEN];
    if ( (nlines = readlines(lineptr, p, MAXLINES)) >= 0)
    {
        qsort_kr(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
}

int get_line(char *, int);

/* readlines: read input lines */
int readlines(char *lineptr[], char *p, int maxlines)
{
    int len, nlines;
    char line[MAXLEN];
    
    nlines = 0;
    while ( (len = get_line(line, MAXLEN)) > 0 )
        if (nlines >= maxlines)
            return -1;
        else
        {
            line[len - 1] = '\0';   /* delete newline */
            strcpy(&p[nlines * MAXLEN], line);
            lineptr[nlines] = &p[nlines * MAXLEN];
            nlines++;
        }
    return nlines;
}

/* getline: read a line into s, return length */
int get_line(char *s, int lim)
{
    int c, i;
    
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;
    
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

/* qsort_kr: sort v[left] ... v[right] into increasing order */
void qsort_kr(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);
    if (left >= right)      /* do nothing if array contains fewer than two elements*/
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort_kr(v, left, last - 1);
    qsort_kr(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;
    
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

