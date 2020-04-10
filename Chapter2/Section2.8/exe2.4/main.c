#include <stdio.h>
/*
 * Exercise 2.4. Write an alternate version of squeeze(s1, s2) that deletes each character in s1 that matches any character in the string s2.
 */

#define MAXLINE 1000

int get_line(char s[], int lim);

void squeeze(char s1[], char s2[]);

int main()
{
    int len1, len2;
    char line1[MAXLINE];
    char line2[MAXLINE];
    
    printf("Enter two stings: \n");
    
    len1 = get_line(line1, MAXLINE);
    len2 = get_line(line2, MAXLINE);
    
    squeeze(line1, line2);
    
    printf("String after deleting character in string s1 that matches character in string s2:\n%s\n",line1);
    
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

void squeeze(char s1[], char s2[])
{
    int i, j, k;
    int state;
    
    for (i = j = 0; s1[i] != '\0'; ++i)
    {
        state = 0;
        for (k = 0; s2[k] != '\0'; ++k)
            if (s1[i] == s2[k])
                state = 1;
        if (state == 0)
            s1[j++] = s1[i];
    }
    s1[j] = '\0';
}
