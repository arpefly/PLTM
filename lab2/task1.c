#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n = 0, max = 0;
    printf("Array size: ");
    scanf("%d", &n);
    printf("Max value: ");
    scanf("%d", &max);

    int arr[n];

    srand(time(0));

    for (int i = 0; i < n; i++)
        arr[i] = rand() % (max+1);
    
    for (int i = 0; i < n; i++)
        printf("%d\n", arr[i]);
    
    return 0;
}