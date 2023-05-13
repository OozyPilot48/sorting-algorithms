#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count[10];

void radixcountSort(int* arr, int len, int exponent)
{
    for (int i = 0; i < 10; i++)
    {
        count[i] = 0;
    }
    int* out = malloc(len * sizeof(int));
    for (int i = 0; i < len; i++)
    {
        count[(arr[i] / exponent) % 10]++;
    }
    for (int i = 0; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = len - 1; i >= 0; i--)
    {
        out[count[(arr[i] / exponent) % 10] - 1] = arr[i];
        count[(arr[i] / exponent) % 10]--;
    }
    for (int i = 0; i < len; i++)
    {
        arr[i] = out[i];
    }
}

void radixSort (int* arr, int len)
{
    int maximum = arr[0];
    for (int i = 1; i < len; i++)
    {
        if (arr[i] > maximum)
        {
            maximum = arr[i];
        }
    }
    for (int exponent = 1; maximum / exponent > 0; exponent *= 10)
    {
        radixcountSort(arr, len, exponent);
    }
}

void call (int* arr, int len)
{
    radixSort(arr, len);
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