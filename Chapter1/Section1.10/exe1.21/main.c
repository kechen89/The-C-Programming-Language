#include <stdio.h>
/* Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum number of
 * tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. When either
 * a tab or a single blank would suffice to reach a tab stop, which should be given preference?
 * --------|--------|--------|--------|--------|
 */

#define N 8
#define IN 1    /* inside blank */
#define OUT 0   /* outside blank */

int main()
{
    int column, c, nb, state;
    
    column = 0;
    
    state = OUT;
    
    nb = 0;
    
    while ( (c = getchar()) != EOF )
    {
        ++column;
        
        if ( c == '\n')
        {
            putchar(c);
            column = 0;
            state = OUT;
            nb = 0;
        }
        else if (c == ' ')
        {
            ++nb;
            state = IN;
            if ( (column + 1) % N == 1)
            {
                putchar('\t');
                nb = 0;
            }
        }
        else
        {
            if (state == IN)
            {
                if (nb > 0)
                {
                    for (; nb > 0; nb--)
                    putchar(' ');
                }
                state = OUT;
                nb = 0;
            }
            putchar(c);
        }
    }
}
