#include <stdio.h>
/* Exercise 1-5. Modify the temperature conversion program to print the table
 * in reverse order, that is, from 300 degrees to 0.
 */

/* print Fahrenheit-Celsius table
 * for fahr = 300, 280, ..., 0; floating-point version
 */

int main()
{
    int fahr;
    
    printf("%s %s\n", "Fahrenheit", "Celsius");
    
    for (fahr = 300; fahr >= 0; fahr -= 20) {
        printf("%d %6.1f\n", fahr, (5.0/9.0) * (fahr - 32.0));
    }
    return 0;
}
