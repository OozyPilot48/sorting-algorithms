#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition (int* arr, int left, int right)
{
    srand(time(NULL));
    //int pivot = rand() % (right - left + 1) + left;
    int pivot = arr[right];
    int q = left - 1;
    for (int i = left; i <= right; i++)
    {
        if (arr[i] < pivot)
        {
            q++;
            swap(&arr[i], &arr[q]);
        }
    }
    q++;
    swap(&arr[right], &arr[q]);
    return q;
}
void quickSort (int* arr, int left, int right)
{
    if (left < right)
    {
        int pivot = partition(arr, left, right);
        quickSort (arr, left, pivot - 1);
        quickSort (arr, pivot + 1, right);
    }

}

void call (int* arr, int len)
{
    quickSort(arr, 0, len - 1);
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

//0.000586   random pivot on sorted array

//0.158923   standard pivot on sorted array
