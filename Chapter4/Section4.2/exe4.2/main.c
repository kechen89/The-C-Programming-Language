#include <stdio.h>
#include <ctype.h>
/*
 * Exercise 4.2. Extend atof to handle scientific notation of the form 123.45e-6, where a floating-point number may be followed by e or E and an
 * optionally signed exponent.
 */

#define MAXLINE 1000               /* maximum input line length */

int get_line(char s[], int lim);

double atof_kr(char s[]);

int main()
{
    double sum;
    char line[MAXLINE];
    
    sum = 0;
    while (get_line(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof_kr(line));
    return 0;
}

/* get_line: get line into s, return length */
int get_line(char s[], int lim)
{
    int c, i;
    
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n' )
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* atof_kr: convert string s to double */
double atof_kr(char s[])
{
    double val, power;
    int i, sign;
    
    for (i = 0; isspace(s[i]); i++)     /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] -'0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    
    return sign * val / power;
}
