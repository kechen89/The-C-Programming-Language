#include <stdio.h>

/*copy input to output*/
int main()
{
    int c;
    
    printf("Enter a char: \n");
    
    c = getchar() != EOF;
    
    printf("%d\n", c);
    
    return 0;
}
