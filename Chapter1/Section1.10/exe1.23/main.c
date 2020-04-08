#include <stdio.h>
/* Exercise 1-23. Write a program to remove all comments from a C program. Don't forget to
 * handle quoted strings and character constants properly. C comments do not nest.
 */

#define IN 1                  /* inside comment */
#define OUT 0                 /* outside comment */

void remove_comments(char c);

int main()      // main function
{
    int c, d;
    int state = OUT;
    
    while ((c = getchar()) != EOF)
    {
        if (c == '/' && (d = getchar()) == '*')
            state = IN;
        else if (c == '/' && state  == OUT)
        {
            putchar(c);
            putchar(d);
            continue;
        }
            
        if (c == '*' && (d = getchar()) == '/')
        {
            state = OUT;
            continue;
        }
        else if (c == '*' && state == OUT)
        {
            putchar(c);
            putchar(d);
            continue;
        }
            
        if (state == OUT)
            putchar(c);
    }
    return 0;
}
