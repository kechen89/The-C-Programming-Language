#include <stdio.h>
#include <time.h>
/*
 * Exercise 3.1. Our binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside).
 * Write a version with only one test inside the loop and measure the difference in run-time.
 */

int binsearch(int x, int v[], int n);
int mybinsearch(int x, int v[], int n);

int main()
{
    int i, n, x, pos;
    time_t start, end;
    
    printf("Input the length of the array:\n");
    scanf("%d",&n);
    
    int v[n];
    
    //printf("Input an integer array with %d elements:\n",n);
    for (i = 0; i < n; i++)
        //scanf("%d", &v[i]);
        v[i] = i + 1;
    
    printf("The elements in array are:\n");
    for (i = 0; i < n; i ++)
        printf("%d ",v[i]);
    printf("\n");
    
    printf("Input the element to look up:\n");
    scanf("%d",&x);
    
    time(&start);
    pos = mybinsearch(x, v, n);
    time(&end);
    double time_taken = (end - start);
    printf("Time taken by whole program is: %.*f sec\n", 20, time_taken);

    printf("The position of the element in the array is: %u\n", pos);
    return 0;
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n - 1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else         /* found match */
            return mid;
    }
    return -1;  /* no match */
}

int mybinsearch(int x, int v[], int n)
{
    int low, high, mid;
    
    low = 0;
    high = n - 1;
    
    mid = (low + high) / 2;
    
    while (low <= high && x != v[mid])
    {
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
        mid = (low + high) / 2;
    }
    
    if (x == v[mid])
        return mid;            /*  found match */
    
    return -1;  /* no match */
}
