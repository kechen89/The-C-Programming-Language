#include <stdio.h>
/* Shell sort */


void Shell_sort(int a[], int n);

int main()
{
    int a[17] = {8, 3, 9, 6, 0, 5, 8, 2, 5, 7, 2, 3, 7, 7, 10, 9, 0};
    Shell_sort(a, 17);
    for (int i = 0; i < 17; i++)
        printf("%d\n", a[i]);
    return 0;
}

void Shell_sort(int a[], int n)
{
    int i, j, tmp, gap;
    
    for (gap = n/2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i += 1)
        {
        for (j = i - gap; j >= 0 && a[j] > a[j + gap]; j -= gap)
        {
            tmp = a[j];
            a[j] = a[j + gap];
            a[j + gap] = tmp;
        }
    }
    }
}
