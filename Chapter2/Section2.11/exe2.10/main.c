#include <stdio.h>
/*
 * Exercise 2.10. Rewrite the function lower, which converts upper case letters to lower case, with
 * a conditional expression instead of if-else
 */

int lower(int c);

int main()
{
    int c, d;
    
    printf("Enter a letter: ");
    
    while ( (c = getchar()) != EOF )
    {
        d = lower(c);
        printf("The lower case of %c is %c \n", c, d);
    }
    
    
    return 0;
}


/* lower: convert c to lower case; ASCII only */
int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
