#include <stdio.h>
/*Exercise 1-13. Write a program to print a histogram of the lengths of words
 * in its input. It is easy to draw the histogram with the bars horizontal;
 * a vertical orientation is more challenging.
 */

#define MAXL 20  // maximum length of word
#define IN 1
#define OUT 0

int main()
{
    int i, j, c, wl, state;
    int len[MAXL];
    
    for (i = 0; i < MAXL; ++i)
        len[i] = 0;
    
    state = OUT;
    wl = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            if (state == IN)
            {
                state = OUT;
                if (wl <= MAXL)
                    ++len[wl - 1];
                else
                    printf("The length of the word is larger than the MAXIMUM\n");
                wl = 0;
            }
        }
        else
        {
            if (state == OUT)
                state = IN;
            ++wl;
        }
    }
    
    //print the histogram with horizontal bar
    printf("The horizontal histogram:\n");
    for (i = 0; i < MAXL; ++i)
    {
        printf("|%d|",i + 1);
        for (j = 0; j < len[i]; ++j)
        {
            putchar('*');
        }
        putchar('\n');
    }
    
    //print the histogram with vertical bar
    printf("The vertical histogram:\n");
    for (i = MAXL; i >= 1; --i)  // vertical axis MAXL, ..., 1
    {
        for (j = 0; j < MAXL; ++j)
        {
            if (len[j] >= i)
                putchar('*');
            else
                putchar(' ');
            putchar(' '); 
        }
        putchar('\n');
    }
    for (i = 0; i < MAXL; ++i)
        printf("%d|",i + 1);
    putchar('\n');
}
