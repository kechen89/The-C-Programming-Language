#include <stdio.h>
/*
 * Exercise 2.5. Write the function any(s1,s2), which returns the first location in the string s1 where any character from the string s2 occurs, or -1 if s1 contains no characters from s2. (The standard library function strpbrk does the same job but returns a pointer to the location.)
 */

#define MAXLINE 1000

int get_line(char s[], int lim);

int any(char s1[], char s2[]);

int main()
{
    int len1, len2, pos;
    char line1[MAXLINE];
    char line2[MAXLINE];
    
    printf("Enter two stings: \n");
    
    len1 = get_line(line1, MAXLINE);
    len2 = get_line(line2, MAXLINE);
    
    pos = any(line1, line2);
    
    printf("Length of string s1 is:%d\n",len1);
    printf("Length of string s2 is:%d\n",len2);
    printf("The first location in the string s1 where any character from the string s2 occurs:\n%d\n",pos);
    
    return 0;
}


/* get_line: read a line into s, return length */
int get_line(char s[], int lim)
{
    int c, i;
    
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    
    s[i] = '\0';
    return i;
}


int any(char s1[], char s2[])
{
    int i, j, pos;
    int state = 0;
    
    i = 0;
    while(s1[i] != '\0' && state == 0)
    {
        j = 0;
        while (s2[j] != '\0' && state == 0)
        {
            if (s1[i] == s2[j])
            {
                state = 1;
                pos = i;
            }
            ++j;
        }
        ++i;
    }
    
    if (state == 0)
        pos = -1;
    return pos;
}
