
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int* arr, int left, int mid, int right)
{
    int i = left, j = mid + 1, k = 0;
    int* temp = (int*)calloc(right - left + 1, sizeof(int));
    while ((i <= mid) && (j <= right))
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    while (j <= right)
    {
        temp[k++] = arr[j++];
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    for (i = left, k = 0; i <= right; i++, k++)
    {
        arr[i] = temp[k];
    }
    free(temp);
}
void mergeSort(int* arr, int left, int right)
{
    if (left < right) 
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        if (arr[mid] > arr[mid + 1])
        {
            merge(arr, left, mid, right);
        }
    }
}  

void call (int* arr, int len)
{
    mergeSort(arr, 0, len - 1);
}

void verify(int* arr, int len)
{
    for (int i = 1; i < len; i++)
    {
        if (arr[i] < arr[i-1])
        {
            printf ("NOT sorted\n");
            return;
        }
    }
    printf ("sorted\n");
}

int main()
{
    system("cls");
    freopen("data.txt", "r", stdin);
    int repeat, len;
    scanf ("%d%d\n", &repeat, &len);
    int* arr = malloc(len * sizeof(int));
    struct timespec stop, start;
    double avgtime = 0;


    for (int i = 0; i < repeat; i++)
    {
        for (int pos = 0; pos < len; pos++)
        {
            scanf ("%d", &arr[pos]);
        }
        scanf ("/n");

        clock_gettime( CLOCK_MONOTONIC, &start );
        call(arr, len);
        clock_gettime( CLOCK_MONOTONIC, &stop );


        double duration = 1.0e+3 * ((double) ((stop.tv_sec - start.tv_sec) + 1.0e-9 * (stop.tv_nsec - start.tv_nsec)));
        printf ("test %d: %lf msec\n", i + 1, duration);
        avgtime += duration;

        verify(arr, len);
    }
    avgtime /= repeat;
    printf ("Average Time: %lf", avgtime);
}
