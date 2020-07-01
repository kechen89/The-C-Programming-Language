#include <stdio.h>
#include <string.h>
/* Exercise 4.14. Define a macro swap(t,x,y) that interchanges two arguments of type t. (Block structure will help.)
 */

#define swap(t, x, y) { \
t tmp; \
tmp = x; \
x = y; \
y = tmp; \
}


int main()
{
    int x = 3;
    int y = 5;
    swap(int, x, y);
    printf("x: %d\n", x);
    printf("y: %d\n", y);

    return 0;
}

