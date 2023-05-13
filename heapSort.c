#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int* arr, int len, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if (left < len && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < len && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, len, largest);
    }
}

void heapSort(int* arr, int len)
{
    for (int i = len / 2 - 1; i >= 0; i--)
    {
        heapify(arr, len, i);
    }
    for (int i = len - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void call (int* arr, int len)
{
    heapSort(arr, len);
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