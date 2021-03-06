#include <stdio.h>
#include <ctype.h>

#define SIZE 10

int getch(void);
void ungetch(int);
int getint(int *pn);


int main()
{
    int n, c, array[SIZE];
    
    n = 0;
    while (n < SIZE && (c = getint(&array[n])) != EOF)
    {
        if (c == 0)
        {
            getch();   /* remove pushed back characte to avoid infinite loop */
        }
        else
            n++;
    }
    printf("\n%d\n",n);
    for (int i = 0; i <= n; i++)
        printf("%d\n",array[i]);

    return 0;
}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign;
    
    while (isspace(c = getch()))  /* skip white space */
        ;
    
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);  /* it's not a number */
        return 0;
    }
    
    sign = (c == '-') ? -1 : 1;
    
    if (c == '+' || c == '-')
        c = getch();
    
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    
    *pn *= sign;
    
    if (c != EOF)
        ungetch(c);
    return c;
}


#define BUFSIZE 100

char buf[BUFSIZE];   /* buffer for ungetch */
int bufp = 0;        /* next free position in buf */

/* get a (possibly pushed back) character */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}







