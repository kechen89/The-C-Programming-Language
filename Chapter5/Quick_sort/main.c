#include <stdio.h>
/* Quick sort */


void QuickSort(int a[], int left, int right);
void swap(int *b, int *c);

int main()
{
    int a[10] = {8, 3, 9, 6, 4, 5, 8, 2, 5, 7};
    QuickSort(a, 0, 9);
    for (int i = 0; i < 10; i++)
        printf("%d\n", a[i]);
    return 0;
}

void QuickSort(int a[], int left, int right)
{
    if (left >= right)
        return;
    
    int middle = (left + right)/2;
    int last;
    int tmp;
    
    swap(a + left, a + middle);  // move partition element to beginning
    last = left + 1;
    
    for (int i = left + 1;  i <= right ; i++)
    {
        if (a[i] < a[left])
        {
            swap(a + last, a + i);
            ++last;
        }
    
    }
    
    swap(a + left, a + last - 1);
    QuickSort(a, left, last - 2);
    QuickSort(a, last, right);

    
}

void swap(int *b, int*c)
{
    int tmp;
    tmp = *b;
    *b = *c;
    *c = tmp;
}
