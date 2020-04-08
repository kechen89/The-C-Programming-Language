#include <stdio.h>
/* Exercise 1-23. Write a program to remove all comments from a C program. Don't forget to
 * handle quoted strings and character constants properly. C comments do not nest.
 */

void remove_comments(char c);

int main()
{
    int c;
    while ((c = getchar()) != EOF)
        remove_comments(c);
    return 0;
}

void remove_comments(char c)
{
    if (c == '\' && getchar() == '*')
        state = IN;
        
    if (state == OUT)
        putchar(c);
}


