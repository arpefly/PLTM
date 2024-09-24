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
        arr[i] = rand() % max;
    
    for (int i = 0; i < n; i++)
        printf("%d\n", arr[i]);

    FILE* file;
    if ((file = fopen("task2.txt", "w")) == NULL)
    {
        printf("[ERROR]");
        exit(EXIT_FAILURE);
    }
    
    for (int i = n; i > 0;)
        fprintf(file, "%d\n", arr[--i]);
    
    return 0;
}