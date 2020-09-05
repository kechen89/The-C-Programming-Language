#include <stdio.h>
#include <stdlib.h>      /* for atof() */
#include <ctype.h>       /* for isdigit() */
/* Rerverse Polish Calculator.
 */

#define MAXOP 1000
#define NUMBER '0'
#define BUFSIZE 1000

int getop(char*);
void push(double);
double pop(void);

int getch(void);
void ungetch(int);

int sp;
double stack[MAXOP];

int main()
{
    int type;
    
    char operandString[MAXOP];
    
    double operandValue, op1, op2;
    
    while ( (type = getop(operandString)) != EOF)
    {
        switch(type)
        {
            case NUMBER:
                operandValue = atof(operandString);
                push(operandValue);
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op1 = pop();
                op2 = pop();
                push(op2 - op1);
                break;
            case '*':
                push (pop() * pop());
                break;
            case '/':
                op1 = pop();
                op2 = pop();
                if (op2 != 0)
                     push(op2 / op1);
                else
                    printf("Error: the divisor can not be 0 \n");
                break;
            case '\n':
                printf("The result is %f\n",pop());
                break;
            default:
                printf("Invalid input\n");
                break;
        }
    }
   
    return 0;
}

int getop(char *operandString)
{
    int i, c;
    while ((operandString[0] = c = getch()) == ' ' || c == '\t' )
        ;

    i = 1;
    operandString[i] = '\0';
    
    if (!isdigit(c) && c != '.')
        return c;
    
    i = 0;
    if ( isdigit(c) )
        while ( isdigit( operandString[++i] = c = getch() ) )
            ;
    
    if (c == '.')
        while ( isdigit( operandString[++i] = c = getch() ) )
        ;
    operandString[i] = '\0';
    
    if (c != EOF)
        ungetch(c);
    
    return NUMBER;
}

int buf[BUFSIZE];
int bufp;

int getch()
{
    return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp < MAXOP)
        buf[bufp++] = c;
    else
        printf("The array is full \n");
}


void push(double value)
{
    if (sp < MAXOP)
        stack[sp++] = value;
    else
        printf("error: stack is full\n");
}

double pop()
{
    if (sp > 0)
        return stack[--sp];
    else
    {
        printf("error: the stack is empty\n");
        return 0.0;
    }
}
