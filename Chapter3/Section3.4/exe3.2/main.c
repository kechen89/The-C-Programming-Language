#include <stdio.h>
#include <time.h>
/*
 * Exercise 3.2. Write a function escape(s,t) that converts characters like newline and tab into visible escape sequences like \n and \t as
 * it copies the string t to s. Use a switch. Write a function for other direction as well, converting escape squences into the real characters.
 */

#define MAXLINE 1000

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main()
{
    int c, i;
    char s[MAXLINE], t[MAXLINE];
    
    printf("Enter string t that contains '\\' 't' and '\\' 'n' \n");
    i = 0;
    while ( (c = getchar()) != EOF && i < MAXLINE - 1)
    {
        t[i] = c;
        ++i;
    }
    
    t[i] = '\0';
    
    escape(s, t);
    
    printf("The converted string is\n%s \n", s);
    
    return 0;
}

/* unescape: convert visible escape sequences into real characters */
void unescape(char s[], char t[])
{
    int i = 0;
    int j = 0;
    
    while (t[i] != '\0')
    {
        if (t[i] == '\\')
        {
            switch (t[i + 1])
            {
                case 'n':
                    s[j] = '\n';
                    ++i;
                    break;
                case 't':
                    s[j] = '\t';
                    ++i;
                    break;
                default:
                    s[j] = '\\';
                    break;
            }
        }
        else
        {
            s[j] = t[i];
        }
            
        ++i;
        ++j;
    }
    s[j] = '\0';
}

/* escape: expand newline and tab into visible escape sequences */
void escape(char s[], char t[])
{
    int i = 0;
    int j = 0;
    
    while (t[i] != '\0')
    {

            switch (t[i])
            {
                case '\n':
                    s[j] = '\\';
                    s[++j] = 'n';
                    break;
                case '\t':
                    s[j] = '\\';
                    s[++j] = 't';
                    break;
                default:
                    s[j] = t[i];
                    break;
            }
        ++i;
        ++j;
    }
    s[j] = '\0';
}
