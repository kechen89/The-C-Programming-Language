#include <stdio.h>
/*Exercise 1-9. Write a program to copy its input to its output, replacing each string
 * of one or more blanks by a single blank.
 */

int main(void)
{
    int c;
    int inspace;
    
    inspace = 0;
    while((c = getchar()) != EOF)
    {
        if(c == ' ')
        {
            if(inspace == 0)
            {
                inspace = 1;
                putchar(c);
            }
        }
        else
        {
            inspace = 0;
            putchar(c);
        }
    }
    
    return 0;
}
