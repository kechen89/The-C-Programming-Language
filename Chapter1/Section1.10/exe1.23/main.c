#include <stdio.h>
/* Exercise 1-23. Write a program to remove all comments from a C program. Don't forget to
 * handle quoted strings and character constants properly. C comments do not nest.
 */

#define IN 1                   /* inside comment */
#define IND 2                  /* inside double slash comment */
#define OUT 0                  /* outside comment */
#define INQUATE 1              /* inside quoted strings */
#define OUTQUATE 0

int main()      // main function
{
    int c, d;
    int state = OUT;
    int stateq = OUTQUATE;
    
    while ((c = getchar()) != EOF)
    {
        if (c == '\n' && state == IND)
        {
            state = OUT;
            putchar(c);
        }
        else if (c == '/' && (d = getchar()) == '*' && stateq == OUTQUATE)
            state = IN;
        else if (c == '/' && d == '/' && stateq == OUTQUATE)
            state = IND;
        else if (c == '*' && (d = getchar()) == '/' && stateq == OUTQUATE)
        {
            state = OUT;
        }
        else if (c == '"' && state == OUT)
        {
            if (stateq == OUTQUATE)
            {
                stateq = INQUATE;
                putchar(c);
            }
            else if (stateq == INQUATE)
            {
                stateq = OUTQUATE;
                putchar(c);
            }
        }
        else if (state == OUT || stateq == INQUATE)
        {
            putchar(c);
            if (c == '/' || c == '*')
                putchar(d);
            if (d == '"')
                stateq = OUTQUATE;
        }
    }
    return 0;
}
