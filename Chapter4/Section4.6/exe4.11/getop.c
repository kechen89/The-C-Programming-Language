#include "calc.h"

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;
    
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    i = 0;
    
    if (islower(c)) {      /* if sin, exp, and pow*/
        while (islower(s[++i] = c = getch()))
            ;
        s[i] = '\0';
        if (c != EOF)
            ungetch(c);
        if (strlen(s) > 1)
            return NAME;
        else
            return c;
    }
    
    if (!isdigit(c) && c != '.' && c != '-')
        return c;          /* not a number */
    
    if (c == '-')
    {
        if ( !isdigit(c = getch()) )
        {
            if (c != EOF)
                ungetch(c);
            return '-';
        }
        else
            s[++i] = c;
    }
    
    if (isdigit(c))    /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')    /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}
