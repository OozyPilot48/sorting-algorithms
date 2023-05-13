#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    
    long len, maxval, repeat;
    printf ("Number of tests:"); scanf ("%ld", &repeat);
    printf ("File Size:"); scanf ("%ld", &len);
    printf ("Max Value:"); scanf ("%ld", &maxval);        


    srand(time(NULL));
    freopen("data.txt", "w", stdout);
    printf ("%ld %ld\n", repeat, len);

    long* arr = malloc(len * sizeof(long));

    for (int r = 0; r < repeat; r++)
    {
        arr = realloc(arr, len * sizeof(long));
        arr[0] = 0;
        arr[len - 1] = 0;
        for (int i = 0; i < len; i++)
        {
            printf ("%ld ", rand() % maxval);
        }
        printf ("\n");
    }
}