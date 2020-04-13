#include <stdio.h>
#include <stdbool.h>
/*
 * Exercise 3.3. Write a function expand(s1,s2) that expands shorthand notations like a-z in the string s1 into the equivalent complete list
 * abc...xyz in s2. Allow for letters of either case and digits, and be prepared to handle cases like a-b-c and a-z0-9. Arrange that a leading
 * or trailing - is taken literally.
 */

#define MAXLINE 1000

void expand(char s1[], char s2[]);

bool myisletter(int c);
bool myisdigit(int c);

int main()
{
    int c, i;
    char s1[MAXLINE], s2[MAXLINE];
    
    printf("Enter a string with shorthand notation like a-z or 0-9\n");
    
    while ( (c = getchar()) != EOF && i < MAXLINE - 1)
    {
        s1[i] = c;
        ++i;
    }
    
    s1[i] = '\0';
    
    expand(s1, s2);
    
    printf("The converted string is\n%s \n", s2);
    
    return 0;
}

void expand(char s1[], char s2[])
{
    int i, j, k, sign;
    
    i = j = 0;
    while (s1[i] != '\0')
    {
         printf("\n %d \n", i);
        
        if (myisletter(s1[i]) && s1[i+1] == '-' && myisletter(s1[i+2]) && s1[i] < s1[i+2])
        {
            for (k = s1[i]; k <= s1[i+2]; ++k, ++j)
                s2[j] = k;
            
            i += 3;
            
            if (s1[i] == '-' && myisletter(s1[i+1]))
            {
                for (k = s1[i-1] + 1; k <= s1[i+1]; ++k, ++j)
                    s2[j] = k;
                i += 2;
            }
                
        }
        else if (myisdigit(s1[i]) && s1[i+1] == '-' && myisdigit(s1[i+2]) && s1[i] < s1[i+2])
        {
            for (k = s1[i]; k <= s1[i+2]; ++k, ++j)
                s2[j] = k;
            i += 3;
            
            if (s1[i] == '-' && myisdigit(s1[i+1]))
            {
                for (k = s1[i-1] + 1; k <= s1[i+1]; ++k, ++j)
                    s2[j] = k;
                i += 2;
            }
            
        }
        
        else
        {
            s2[j] = s1[i];
            ++i;
            ++j;
        }
    }
    
    s2[j] = '\0';
}

bool myisletter(int c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool myisdigit(int c)
{
    return c >= '0' && c <= '9';
}
