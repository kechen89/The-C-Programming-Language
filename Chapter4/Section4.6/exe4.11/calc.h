#ifndef calc_h
#define calc_h

#include <stdio.h>
#include <stdlib.h>    /* for atof() */
#include <ctype.h>
#include <math.h>
#include <string.h>

#define NUMBER '0'
#define MAXOP 100        /* max size of operand or operator */
#define NAME 'n'         /* signal that a name was found */

#define MAXVAL 100      /* maximum depth of val stack */

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

void print(void);
void duplicate(void);
void swap(void);
void clear(void);
void mathfnc(char s[]);

#endif /* calc_h */
