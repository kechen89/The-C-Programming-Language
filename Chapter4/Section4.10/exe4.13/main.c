#include <stdio.h>
#include <string.h>
/* Exercise 4.13. Write a recursive version of the function reverse(s), which reverses the string s in place.
 */

#define MAXLINE 100

void reverse_recursive(char s[], int ibegin, int iend);

int main()
{
    char s[MAXLINE];
    
    printf("Enter a string: \n");
    
    scanf("%s",s);
    
    reverse_recursive(s, 0, strlen(s) - 1);
    
    printf("The reversed string is: %s\n",s);

    return 0;
}

/* reverse: reverse a string in place by recursion*/
void reverse_recursive(char s[], int ibegin, int iend)
{
    char c;
    
    if (ibegin <= iend)
    {
        c = s[ibegin];
        s[ibegin] = s[iend];
        s[iend] = c;
        reverse_recursive(s, ibegin+1, iend-1);
    }
    
    return;
}
