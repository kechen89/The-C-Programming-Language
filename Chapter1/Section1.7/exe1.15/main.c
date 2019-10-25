#include <stdio.h>
/* print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300; floating-point version
 */

float fahr_to_celsius(float fahr);

int main()
{
    float fahr, celsius;
    int lower, upper, step;
    
    lower = 0;     /* lower limit of temperature table */
    upper = 300;   /* upper limit */
    step = 20;     /* step size */
    
    fahr = lower;
    
    printf("%s %s\n", "Fahrenheit", "Celsius");
    
    while (fahr <= upper) {
        celsius = fahr_to_celsius(fahr);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}

float fahr_to_celsius(float fahr)
{
    float celsius;
    celsius = (5.0/9.0) * (fahr - 32.0);
    return celsius;
}
