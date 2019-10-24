#include <stdio.h>

#define IN 1    /* inside a word */
#define OUT 0   /* outside a word */

/* print input one word per line */

int main( )
{
    int c;
    int STATE = OUT;
    
    while ( (c = getchar()) != EOF )
    {
        if (c == '\n' || c == ' ' || c == '\t')
        {
            if (STATE == IN)
            {
                putchar('\n');
                STATE = OUT;
            }
        }
        else
        {
            putchar(c);
            STATE = IN;
        }
    }
    return 0;
}
