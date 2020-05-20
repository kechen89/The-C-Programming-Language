#include "calc.h"

extern int sp;
extern double val[];

/* print: print the top element of the stack */
void print()
{
    if (sp > 0)
        printf("\t%.8g\n",val[sp - 1]);
    else
        printf("error: stack empty\n");
}

/* duplicate: duplicate the top element of the stack*/
void duplicate()
{
    if (sp < MAXVAL)
    {
        val[sp] = val[sp - 1];
        ++sp;
    }
    else
        printf("error: stack full, can't duplicate the top element\n");
}

/* swap: swap the top two elements of the stack */
void swap()
{
    double tmp;
    if (sp < MAXVAL - 1)
    {
        tmp = val[sp - 2];
        val[sp - 2] = val[sp - 1];
        val[sp - 1] = tmp;
    }
    else
        printf("error: the stack has less than two elements\n");
}

/* clear: clear the stack */
void clear()
{
    for (; sp > 0; --sp)
        val[sp] = 0.0;
}

/* mathfnc: check string s for supported math functions */
void mathfnc(char s[])
{
    double op2;
    if (strcmp(s, "sin") == 0)
        push(sin(pop()));
    else if (strcmp(s,"cos") == 0)
        push(cos(pop()));
    else if (strcmp(s,"exp") == 0)
        push(exp(pop()));
    else if (strcmp(s,"pow") == 0) {
        op2 = pop();
        push(pow(pop(),op2));
    }
    else
        printf("error: %s not supported\n", s);
}
