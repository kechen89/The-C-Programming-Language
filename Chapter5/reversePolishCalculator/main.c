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
   
}

int getop(char *operandString)
{
    int i, c;
    while ((c = getchar()) == ' ' || c == '\t' )
        ;

    if (!isdigit(c))
        return c;

    i = 0;
    operandString[i] = '\0';
    
    while (isdigit(c))
    {
        operandString[i++] = c;
        c = getch();
    }
    
    if (c == '.')
        operandString[i++] = c;
    
    while (isdigit(c))
    {
        operandString[i++] = c;
        c= getch();
        
    }
    
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
}

double pop()
{
    return sp > 0 ? stack[--sp] : printf("error: the stack is empty\n");
}
