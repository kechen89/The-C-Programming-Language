#include <stdio.h>
#include <ctype.h>

/* Exercise 5.2. Write getfloat, the floating-point analog of getint. What type does
 * getfloat return as its function value?
*/

#define SIZE 10

int getch(void);
void ungetch(int);
int getfloat(float *pn);


#define BUFSIZE 100

char buf[BUFSIZE];   /* buffer for ungetch */
int bufp = 0;        /* next free position in buf */

int main()
{
    int n, c;
    float array[SIZE];
    
    n = 0;
    while (n < SIZE && (c = getfloat(&array[n])) != EOF)
    {
        for (;bufp>0;)
            getch();
        if (c != 0 && c != '+' && c != '-')
            ++n;
    }
    printf("\n%d\n",n);
    for (int i = 0; i <= n; i++)
        printf("%f\n",array[i]);

    return 0;
}

/* getfloat: get next floating-point number from input into *pn */
int getfloat(float *pn)
{
    int c, d, sign, scale = 1;
    
    while (isspace(c = getch()))  /* skip white space */
        ;
    
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);  /* it's not a number */
        return 0;
    }
    
    sign = (c == '-') ? -1 : 1;
    
    if (c == '+' || c == '-')
    {
        d = c;               /* remember the sign */
        c = getch();
        if (!isdigit(c))
        {
            if (c != EOF)
                ungetch(c);    /* push back non-digit */
            ungetch(d);        /* push back sign char */
            return d;
        }
    }
    
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10.0 * *pn + (c - '0');
    
    if (c == '.')
    {
        c = getch();
    
        for (; isdigit(c); c = getch())
        {
            *pn = 10.0 * *pn + (c - '0');
            scale *= 10.0;
        }
    }
    
    *pn /= scale;
    
    *pn *= sign;
    
    if (c != EOF)
        ungetch(c);
    return c;
}


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
