#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int arr_size = 0;
    printf("Array size: ");
    scanf("%d", &arr_size);

    double arr[arr_size];

    srand(time(0));

    for (int i = 0; i < arr_size; i++)
        arr[i] = (float)rand()/RAND_MAX;
    
    for (int i = 0; i < arr_size; i++)
        printf("%lf\n", arr[i]);

    return 0;
}