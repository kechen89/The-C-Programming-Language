#include <stdio.h>
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
