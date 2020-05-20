#include <stdio.h>
#include <stdlib.h>    /* for atof() */
#include <ctype.h>
#include <math.h>
#include <string.h>

/*
 * Exercise 4.10. An alternate organization uses getline to read an entire input line; this makes getch and ungetch unneccessary.
 * Revise the calculator to use this approach.
 */

#define MAXOP 100        /* max size of operand or operator */
#define NUMBER '0'       /* signal that a number was found */
#define NAME 'n'         /* signal that a name was found */
#define MAXLINE 1000     /* maximum input line size */

int getop(char [], char [], int *k);
void push(double);
double pop(void);
void print(void);
void duplicate(void);
void swap(void);
void clear(void);
void mathfnc(char s[]);
int get_line(char *line, int maxline);

/* reverse Polish calculator */
int main()
{
    int type, var, k;
    double op2, prev;
    char s[MAXOP];
    double variable[26];
    
    int len;
    char line[MAXLINE];              /* current input line */
    
    for (int i = 0; i < 26; ++i)
        variable[i] = 0.0;
    
    while ((len = get_line(line, MAXLINE)) > 0)
    {
        printf("string is %s\n",line);
        k = 0;
        while (k < len){
            type = getop(line,s, &k);
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
        } // switch
    } // while
    } // while
        
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

/* getop: get next operator or numeric operand */
int getop(char line[], char s[], int *k)
{
    int i, c;
    while ((s[0] = c = line[(*k)++]) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    i = 0;
    
    if (islower(c)) {      /* if sin, exp, and pow*/
        while (islower(s[++i] = c = line[(*k)++]))
            ;
        s[i] = '\0';
        if (strlen(s) > 1)
            return NAME;
        else
            return c;
    }
    
    if (!isdigit(c) && c != '.' && c != '-')
        return c;          /* not a number */
    
    if (c == '-')
    {
        if ( !isdigit(c = line[(*k)++]) )
            return '-';
        else
            s[++i] = c;
    }
    
    if (isdigit(c))    /* collect integer part */
        while (isdigit(s[++i] = c = line[(*k)++]))
            ;
    if (c == '.')    /* collect fraction part */
        while (isdigit(s[++i] = c = line[(*k)++]))
            ;
    s[i] = '\0';
    return NUMBER;
}

/* get_line: read a line into s, return length */
int get_line(char *line, int maxline)
{
    int c, i;
    
    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}
