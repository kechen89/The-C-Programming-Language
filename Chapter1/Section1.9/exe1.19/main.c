#include <stdio.h>
/* Exercise 1-19. Write a function reverse(s) that reverses the character string s. Use it
 * to write a program that reverses its input a line at a time.
 */

#define MAXLINE 1000

int get_line(char line[], int lim);
void remove_newline(char *line, int *length);
void reverse(char line[], int length);

int main()
{
    int len;
    char line[MAXLINE];
    
    while ((len = get_line(line, MAXLINE)) > 0)
    {
        remove_newline(line, &len);
        reverse(line, len);
        printf("Reverse the input line:\n");
        printf("%s\n",line);
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

void remove_newline(char *line, int *length)
{
    int i;
    for (i = 0; line[i] != '\0'; ++i)
    {
        if (line[i] == '\n')
        {
            line[i] = '\0';
            (*length) -= 1;
        }
    }
}

void reverse(char line[], int length)
{
    int i, c;
    for (i = 0; i < length/2; ++i)
    {
        c = line[i];
        line[i] = line[length - 1 - i];
        line[length - 1 - i] = c;
    }
}
