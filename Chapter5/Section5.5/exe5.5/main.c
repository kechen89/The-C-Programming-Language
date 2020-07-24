#include <stdio.h>

/* Exercise 5.5. Write versions of the library functions strncpy, strncat, and strncmp,
 * which operate on at most the first n characters of their argument strings. For example,
 * strncpy(s, t, n) copies at most n characters of t to s. Full descriptions are in Appendix B.
 .
*/

void myStrncpy(char *s, char *t, int n);
void myStrncat(char *s, char *t, int n);
int myStrncmp(char *s, char *t, int n);

void strncpy_C_answer_book(char *s, char *t, int n);
int strncmp_C_answer_book(char *s, char *t, int n);

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
    
    //myStrncpy(s, t, n);
    //myStrncat(s, t, n);
    printf("s is larger than n: %d\n", myStrncmp(s, t, n));
    //printf("s is larger than n: %d\n", strncmp_C_answer_book(s, t, n));
    //strncpy_C_answer_book(s, t, n);
    //printf("Copy at most %d characters of t to s is %s \n", n, s);
    return 0;
}

/*
 * myStrncpy: copy at most n characters of string t to s,
 * pad with '\0' if t has fewer than n characters
 */
void myStrncpy(char *s, char *t, int n)
{
    int i = 0;
    
    while (i < n && (*s++ = *t++) != '\0')
        i++;
    
    for (; *s != '\0' && i < n; i++)   // if t has fewer than n characters
        *s++ = '\0';
    
    return;
}

/*
 * myStrncat: concatenate at most n characters of string t to s,
 * terminate s with '\0'
 */
void myStrncat(char *s, char *t, int n)
{
    int i = 0;
    
    while (*s != '\0')   // find the end of s
        s++;
    
    while (i < n && (*s++ = *t++) != '\0')  // copy t to s
        i++;
    
    if (*s != '\0')
        *s = '\0';
}

/*
 * myStrncmp: compare at most n characters of string s to string t;
 * return < 0 if s < t, 0 if s == t, or > 0 if s > t.
 */

int myStrncmp(char *s, char *t, int n)
{
    while (n > 0 && (*s == *t) && *s != '\0' && *t != '\0')
    {
        s++;
        t++;
        n--;
    }
        
    if (n <= 0)
        return 0;
    else
        return *s - *t;
}

void strncpy_C_answer_book(char *s, char *t, int n)
{
    while (*t && n-- > 0)
        *s++ = *t++;
    while (n-- > 0)
        *s++ = '\0';
}

int strncmp_C_answer_book(char *s, char *t, int n)
{
    for ( ; *s == *t; s++, t++)
        if (*s == '\0' || --n <= 0)
            return 0;
    return *s - *t;
}
