#include <stdio.h>
/* Exercise 1-22. Write a program to "fold" long input lines into two or more shorter
 * lines after the last non-blank character that occurs before the n-th column of input.
 * Make sure your program does something intelligent with very long lines, and if there are
 * no blanks or tabs before the specified column.
 */

#define NCOL 10                      /* folded line length*/
#define NTABL 8                      /* tab size */

int find_foldpos(char *line, int N);
void print_line(char *line, int pos);
int rearrange_line(char *line, int pos);
int expand_tab(char *line, int i);

int main()
{
    int c, i, pos;
    char line[NCOL];                 /* folded line */
    
    i = 0;
    
    while ((c = getchar()) != EOF)   /* read character */
    {
        line[i] = c;
        ++i;
        
        if ( c == '\t')
            i = expand_tab(line, i);
        else if ( c == '\n')
        {
            print_line(line, i);
            i = 0;
        }
        else if (i >= NCOL)
        {
            pos = find_foldpos(line, i);
           // printf("pos is : %d\n", pos);
            print_line(line, pos);
            i = rearrange_line(line, pos);;
        }
    }
    
    return 0;
}

int expand_tab(char *line, int i)
{
    int nb, j;
    
    nb = NTABL - (i - 1) % NTABL;
    
    for (j = 0; j < nb; ++j)
        line[i - 1 + j] = ' ';
        
    i += nb;
    return i - 1;
}

int find_foldpos(char *line, int i)
{
    /*find the fold position in the line*/
    int pos;
    
    while (i > 0 && line[i - 1] != ' ')
        --i;
    
    if (i == 0) return NCOL-1;

    return i - 1;
}

void print_line(char *line, int pos)
{
    /*print the line until the fold position*/
    int i;
    i = 0;
    while (i <= pos && line[i] != '\n')
    {
        printf("%c", line[i]);
        ++i;
    }
    printf("%c", '\n');
}

int rearrange_line(char *line, int pos)
{
    int i;
    if (pos >= NCOL - 1)
        return 0;
    else
    {
        for (i = pos; i < NCOL - 1; ++i)
            line[i - pos] = line[i + 1];
        return NCOL - 1 - pos;
    }
}
