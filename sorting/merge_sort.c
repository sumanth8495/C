/**
 * @file
 * @brief Implementation of [merge
 * sort](https://en.wikipedia.org/wiki/Merge_sort) algorithm
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * @addtogroup sorting Sorting algorithms
 * @{
 */
/** Swap two integer variables
 * @param [in,out] a pointer to first variable
 * @param [in,out] b pointer to second variable
 */
void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

/**
 * @brief Perform merge of segments.
 *
 * @param a array to sort
 * @param l left index for merge
 * @param r right index for merge
 * @param n total number of elements in the array
 * @param sorted_arr temporary array to merge the elements
 */
void merge(int *a, int l, int r, int n)
{
    int *sorted_arr = (int *)malloc(n * sizeof(int)); /* dynamic memory must be freed */
    if (sorted_arr == NULL)
    {
        printf("Can't Malloc! Please try again.");
        exit(EXIT_FAILURE);
    }
    int c = l;
    int p1, p2;
    p1 = l;
    p2 = ((l + r) / 2) + 1;
    while ((p1 < ((l + r) / 2) + 1) && (p2 < r + 1))
    {
        if (a[p1] <= a[p2])
        {
            sorted_arr[c++] = a[p1];
            p1++;
        }
        else
        {
            sorted_arr[c++] = a[p2];
            p2++;
        }
    }

    if (p2 == r + 1)
    {
        while ((p1 < ((l + r) / 2) + 1))
        {
            sorted_arr[c++] = a[p1];
            p1++;
        }
    }
    else
    {
        while ((p2 < r + 1))
        {
            sorted_arr[c++] = a[p2];
            p2++;
        }
    }

    for (c = l; c < r + 1; c++) a[c] = sorted_arr[c];

    free(sorted_arr);
}

/** Merge sort algorithm implementation
 * @param a array to sort
 * @param n number of elements in the array
 * @param begin index to sort from
 * @param end index to sort till
 */
void merge_sort(int *arr, int n, int begin, int end)
{
    if (end - begin == 1)
    {
        if (arr[begin] > arr[end])
            swap(&arr[begin], &arr[end]);
    }
    else if (l != r)
    {
        merge_sort(arr, n, begin, (begin + end) / 2);
        merge_sort(arr, n, ((begin + end) / 2) + 1, end);
        merge(arr, begin, end, n);
    }

    /* no change if l == r */
}
/** @} */

/** Main function */
int main(void)
{
    int *arr, n, i;
    printf("Enter Array size: ");
    scanf("%d", &n);
    if (n <= 0) /* exit program if arraysize is not greater than 0 */
    {
        printf("Array size must be Greater than 0!\n");
        return 1;
    }
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) /* exit program if can't malloc memory */
    {
        printf("Can't Malloc! Please try again.");
        return 1;
    }
    for (i = 0; i < n; i++)
    {
        printf("Enter number[%d]: ", i);
        scanf("%d", &array[i]);
    }

    merge_sort(arr, n, 0, n - 1);
    printf("Sorted Array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}
