#include <stdio.h>
/* Exercise 1-19. Write a function reverse(s) that reverses the character string s. Use it
 * to write a program that reverses its input a line at a time.
 */

#define MAXLINE 1000

int get_line(char line[], int lim);
void reverse(char line[], int length);

int main()
{
    int len;
    char line[MAXLINE];
    
    while ((len = get_line(line, MAXLINE)) > 0)
    {
        reverse(line, len);
        printf("Reverse the input line:\n");
        printf("%s",line);
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

void reverse(char line[], int length)
{
    int i, c;
    for (i = 0; i < (length - 1)/2; ++i)
    {
        c = line[i];
        line[i] = line[length - 2 - i];
        line[length - 2 - i] = c;
    }
}
