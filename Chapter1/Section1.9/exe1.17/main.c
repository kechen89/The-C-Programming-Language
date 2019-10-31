#include <stdio.h>
/* Exercise 1-17. Write a program to print all input lines that are longer that 80 characters.
 */

#define MAXLINE 1000
#define LENGTH 80

int get_line(char line[], int MAX);
void print_line(char line[], int length);

int main()
{
    int len;
    char line[MAXLINE];
    
    while ( (len = get_line(line, MAXLINE)) > 0)
    {
        if (len > LENGTH)
        {
            printf("Print input line longer than %d: \n", LENGTH);
            print_line(line, len);
        }
    }
    return 0;
}

int get_line(char line[], int MAX)
{
    int i = 0, c;
    while ( i < MAX - 1 && (c = getchar()) != EOF && c != '\n' )
    {
        line[i] = c;
        ++i;
    }
    
    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';  //null terminated
    return i;
}

void print_line(char line[], int length)
{
    int i;
    for (i = 0; i < length; ++i)
        putchar(line[i]);
}
