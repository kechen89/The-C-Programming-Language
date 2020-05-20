#include "calc.h"

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;
    static int lastc = 0;
    
    if (lastc == 0)
        c = getch();
    else
    {
        c = lastc;
        lastc = 0;
    }
    
    if ((s[0] = c) == ' ' || c == '\t')
        while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    
    s[1] = '\0';
    i = 0;
    
    if (islower(c)) {      /* if sin, exp, and pow*/
        while (islower(s[++i] = c = getch()))
            ;
        s[i] = '\0';
        lastc = c;
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
            lastc = c;
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
        lastc = c;
    return NUMBER;
}
