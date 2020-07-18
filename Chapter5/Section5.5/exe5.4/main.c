#include <stdio.h>
#include <string.h>

/* Exercise 5.4. Write the function strend(s,t), which returns 1 if the string
 * t occurs at the end of the string s, and zero otherwise.
*/

int strend(char *s, char *t);

int main()
{
    int i;
    char s[20];
    char t[20];
    printf("Enter two strings s and t \n");
    scanf("%s", s);
    scanf("%s", t);
    
    i = strend(s, t);
    printf("String t occurs at the end of string s? %d \n", i);
    return 0;
}

int strend(char *s, char *t)
{
    int i, j, len1, len2;
    
    len1 = strlen(s);
    len2 = strlen(t);
    
    i = len2 - 1;
    j = len1 - 1;
    while (i >= 0 && j >= 0)
    {
        if (t[i] == s[j])
        {
            i--;
            j--;
        }
        else
            return 0;
    }
    
    if (i < 0)
        return 1;
    else
        return 0;
}
