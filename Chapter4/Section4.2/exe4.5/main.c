#include <stdio.h>
#include <stdlib.h>    /* for atof() */
#include <ctype.h>
#include <math.h>
#include <string.h>

/*
 * Exercise 4.5. Add access to library functions like sin, exp, and pow. See <math.h> in Appendix B, Section 4.
 */

#define MAXOP 100        /* max size of operand or operator */
#define NUMBER '0'       /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);
void print(void);
void duplicate(void);
void swap(void);
void clear(void);

/* reverse Polish calculator */
int main()
{
    int type;
    double op2;
    char s[MAXOP];
    
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push((int)pop() % (int)op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '?':               /* print top element of the stack */
                print();
                break;
            case 'd':
                duplicate();
                break;
            case 's':
                swap();
                break;
            case 'c':
                clear();
                break;
            case 'sin':
                push(sin(pop()));
                break;
            case '\n':
                printf("\t%.8g\n",pop());
                break;
            default:
                printf("error: unknown command %s\n",s);
                break;
        }
    }
    return 0;
}

#define MAXVAL 100      /* maximum depth of val stack */

int sp = 0;             /* next free stack position */
double val[MAXVAL];     /* value stack */

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n",f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

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

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;
    
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    i = 0;
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

#define BUFSIZE 100

char buf[BUFSIZE];      /* buffer for ungetch */
int bufp = 0;           /* next free position in buf */

int getch(void)         /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)   /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
