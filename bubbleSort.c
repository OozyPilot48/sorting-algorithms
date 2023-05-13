#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int len)
{
    int temp;
    for (int pos = 0; pos < len - 1; pos++)
    {
        for (int offset = 0; offset < len - pos - 1; offset++)
        {
            if (arr[offset] > arr[offset + 1])
            {
                temp = arr[offset];
                arr[offset] = arr[offset + 1];
                arr[offset + 1] = temp;
            }
        }
    }
}

void call(int* arr, int len)
{
    bubbleSort(arr, len);
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