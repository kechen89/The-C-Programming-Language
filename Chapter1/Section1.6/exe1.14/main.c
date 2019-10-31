#include <stdio.h>
/* Exercise 1-14. Write a program to print a histogram of the frequencies
 * of different characters in its input.
 */

 /* Use ASCII values*/

#define MAX 95

int main()
{
    int i, j, c;
    int freqc[MAX];
    
    for (i = 0; i < MAX; ++i)
        freqc[i] = 0;
    
    while ( (c = getchar()) != EOF )
    {
        if (c >= ' ' && c <= '~')
        ++freqc[c - ' '];
    }
    
    //print a histogram of the frequencies of different characters
    printf("The horizontal histogram:\n");
    for (i = 0; i < MAX; ++i)
    {
        printf("|%c|",(char) (i + 32));
        for (j = 0; j < freqc[i]; ++j)
        {
            putchar('*');
        }
        putchar('\n');
    }
}
