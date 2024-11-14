#include <stdio.h>
#include <stdlib.h>

void display(int output[], int elements)
{
    for (int i = 0; i < elements; i++)
    {
        printf("%d\t", output[i]);
    }
    printf("\n");
}

void countSort(int exp, int arr[], int elements)
{
    int max = 0;

    for (int i = 0; i < elements; i++)
    {
        if ((arr[i] / exp) % 10 > max)
        {
            max = (arr[i] / exp) % 10;
        }
    }

    int *count = (int *)calloc(max + 1, sizeof(int));

    for (int i = 0; i < elements; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    int *output = (int *)malloc(elements * sizeof(int));

    for (int i = elements - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < elements; i++)
    {
        arr[i] = output[i];
    }

    free(count);
    free(output);

    if (max > 0)
    {
        countSort(exp * 10, arr, elements);
    }
}

int main()
{
    int elements;

    printf("Enter the number of elements: ");
    scanf("%d", &elements);

    int *arr = (int *)malloc(elements * sizeof(int));

    printf("Enter each element one by one:\n");
    for (int i = 0; i < elements; i++)
    {
        scanf("%d", &arr[i]);
    }

    countSort(1, arr, elements);

    printf("Sorted array:\n");
    display(arr, elements);

    free(arr);

    return 0;
}
