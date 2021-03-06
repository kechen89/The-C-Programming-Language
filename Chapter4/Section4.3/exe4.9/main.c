#include <stdio.h>
#include <stdlib.h>    /* for atof() */
#include <ctype.h>
#include <math.h>
#include <string.h>

/*
 * Exercise 4.9. Our getch and ungetch do not handle a pushed-back EOF correctly. Decide what their properties
 * ought to be if an EOF is pushed back, then implement your design.
 */

#define MAXOP 100        /* max size of operand or operator */
#define NUMBER '0'       /* signal that a number was found */
#define NAME 'n'         /* signal that a name was found */

int getop(char []);
void push(double);
double pop(void);
void print(void);
void duplicate(void);
void swap(void);
void clear(void);
void mathfnc(char s[]);
void ungets(char s[]);

/* reverse Polish calculator */
int main()
{
    int type, var;
    double op2, prev;
    char s[MAXOP];
    double variable[26];
    
    for (int i = 0; i < 26; ++i)
        variable[i] = 0.0;
    
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
            case NAME:
                mathfnc(s);
                break;
            case '=':
                pop();
                if (var >= 'A' && var <= 'Z')
                    variable[ var - 'A'] = pop();
                else
                    printf("error: no variable name\n");
                break;
            case '\n':
                prev = pop();
                printf("\t%.8g\n",prev);
                break;
            default:
                if (type >= 'A' && type <= 'Z')
                {
                    push(variable[type - 'A']);
                    var = type;
                }
                else if (type == '#')
                    push(prev);
                else
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
    //if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

int buf[BUFSIZE];      /* buffer for ungetch */
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

void ungets(char s[])
{
    int len = strlen(s);
    
    for (int i = len - 1; i >= 0 ; --i)
        ungetch(s[i]);
}
