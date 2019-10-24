#include <stdio.h>

int main()
{
    int c, nb, nt, nl;
    
    nb = nt = nl = 0;
    
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++nb;
        if (c == '\t')
            ++nt;
        if (c == '\n')
            ++nl;
    }
    printf("The number of blanks is %d\n", nb);
    printf("The number of tabs is %d\n", nt);
    printf("The number of newlines is %d\n", nl);
    
    return 0;
}
