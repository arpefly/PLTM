#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void* a, const void* b)
{
    float num1 = *(const float *)a;
    float num2 = *(const float *)b;
    return (num1 > num2) - (num1 < num2);
}

int main(int argc, char* argv[])
{
    srand(time(NULL));

    int arr_size = atoi(argv[1]);
    float* arr = (float*)calloc(arr_size, sizeof(float));
    float min = atof(argv[2]), max = atof(argv[3]);

    for (int i = 0; i < arr_size; i++)
        arr[i] = (float)rand() / (float)(RAND_MAX / (max - min + 1)) + min;

    for (int i = 0; i < arr_size; i++)
        printf("%lf\n", arr[i]);
    
    FILE* file;

    if ((file = fopen("task4out.txt", "w")) == NULL)
    {
        printf("[ERROR] Unable to wrtie to file task4.txt");
        exit(EXIT_FAILURE);
    }

    qsort(arr, arr_size, sizeof(float), compare);

    for (int i = 0; i < arr_size; i++)
        fprintf(file, "%lf\n", arr[i]);
    
    fclose(file);
    free(arr);

    return 0;
}