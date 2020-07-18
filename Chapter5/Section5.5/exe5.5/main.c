#include <stdio.h>

/* Exercise 5.5. Write versions of the library functions strncpy, strncat, and strncmp,
 * which operate on at most the first n characters of their argument strings. For example,
 * strncpy(s, t, n) copies at most n characters of t to s. Full descriptions are in Appendix B.
 .
*/

void myStrncpy(char *s, char *t, int n);
void strncpy_C_answer_book(char *s, char *t, int n);

int main()
{
    int n;
    char s[20];
    char t[20];
    printf("Enter two strings s and t \n");
    scanf("%s", s);
    scanf("%s", t);
    printf("Enter the number of characters to copy from t to s \n");
    scanf("%d", &n);
    
    myStrncpy(s, t, n);
    //strncpy_C_answer_book(s, t, n);
    printf("Copy at most %d characters of t to s is %s \n", n, s);
    return 0;
}

/* myStrncpy: copies at most n characters of t to s */
void myStrncpy(char *s, char *t, int n)
{
    int i = 0;
    while (i < n && (*s++ = *t++) != '\0')
        i++;
    
    return;
}

void strncpy_C_answer_book(char *s, char *t, int n)
{
    while (*t && n-- > 0)
        *s++ = *t++;
    while (n-- > 0)
        *s++ = '\0';
}
