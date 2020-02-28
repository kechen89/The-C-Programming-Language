#include <stdio.h>
/* Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number of
 * blanks to space to the next tab step. Assume a fixed set of tab stops, say every n columns.
 * Should n be a variable or a symbolic parameter?
 --------|--------|--------|--------|--------|
 */

#define N 8

int main()
{
    int column, tab, j, c;
    
    column = 0;
    
    while ( (c = getchar()) != EOF )
    {
        ++column;
        
        if (c == '\n')
        {
            putchar(c);
            column = 0;
        }
        else if (c == '\t')
        {
            tab = N - column % N;
            
            for (j = 0; j < tab; ++j)
            {
                putchar(' ');
            }
            column += tab;
        }
        else
            putchar(c);
    }
    return 0;
}

