#include <stdio.h>
/* Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input,
 * and to delete entirely blank lines.
 */

#define MAXLINE 1000

int get_line(char line[], int lim);
void edit_line(char line[], int length);

int main()
{
    int len;
    char line[MAXLINE];
    
    while ((len = get_line(line, MAXLINE)) > 0)
    {
        edit_line(line, len);
        printf("Remove trailing blanks and tabs, delete entirely blank lines\n");
        printf("%s/end",line);
    }
    return 0;
}

int get_line(char line[], int lim)
{
    int i, c;
    
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    
    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }
    
    line[i] = '\0';
    
    return i;
}

void edit_line(char line[], int length)
{
    int i, c;

    if ( (c = line[length - 2]) == ' ' || c == '\t')
    {
        line[length - 2] = '\0';
        --length;
        edit_line(line, length);
    }
}
