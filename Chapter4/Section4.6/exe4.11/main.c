#include "calc.h"

/*
 * Exercise 4.11. Modify getop so that it doesn't need to use ungetch. Hint: use an internal static variable.
 */

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

