#include <stdio.h>

/* program to print a histogram of the lengths
 * of words in its input.
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
    
    //print the histogram
    printf("The histogram:\n");
    for (i = 0; i < MAXL; ++i)
    {
        printf("|%d|",i+1);
        for (j = 0; j < len[i]; ++j)
        {
            printf("*");
        }
        printf("\n");
    }
}

