#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

int main(int argc, char* argv[])
{
    srand(time(NULL));

    int arr_size = atoi(argv[1]);
    int* arr = (int*)calloc(arr_size, sizeof(int));
    int min = atoi(argv[2]), max = atoi(argv[3]);

    for (int i = 0; i < arr_size; i++)
        arr[i] = rand() % (max - min + 1) + min;

    for (int i = 0; i < arr_size; i++)
        printf("%d\n", arr[i]);
    
    FILE* file;

    if ((file = fopen("task4.txt", "w")) == NULL)
    {
        printf("[ERROR] Unable to wrtie to file task4.txt");
        exit(EXIT_FAILURE);
    }

    qsort(arr, arr_size, sizeof(int), compare);

    for (int i = 0; i < arr_size; i++)
    {
        fprintf(file, "%d\n", arr[i]);
    }    
    
    fclose(file);
    free(arr);

    return 0;
}