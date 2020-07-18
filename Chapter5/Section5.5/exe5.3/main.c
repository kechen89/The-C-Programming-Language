#include <stdio.h>

/* Exercise 5.3. Write a pointer version of the function strcat
 * that we showed in Chapter 2: strcat(s,t) copies the string t to the end of s.
*/

void strcatArrayVersion(char s[], char t[]);
void strcatPointerVersion(char *s, char *t);

int main()
{
    char s[20];
    char t[10];
    printf("Enter two strings s and t \n");
    scanf("%s", s);
    scanf("%s", t);
    
    strcatPointerVersion(s, t);
    //strcatArrayVersion(s, t);
    printf("The concatenated string is %s \n", s);
    return 0;
}

void strcatPointerVersion(char *s, char *t)
{
    while (*s != '\0')          /* find end of s */
        s++;
    while ((*s++ = *t++) != '\0')  /* copy t */
        ;
}


/* strcat: concatenate t to end of s; s must be big enough (Chapter 2) */
void strcatArrayVersion(char s[], char t[])
{
    int i, j;
    
    i = j = 0;
    
    while (s[i] != '\0')      /* find end of s */
        i++;
    while ((s[i++] = t[j++]) != '\0')    /* copy t */
        ;
}

