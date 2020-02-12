#include "sort.h"

void
insertion_sort(int * restrict arr, const uint length)
{
    if (!length)
        return;
        
    int i, j, key;

    for (j = 1; j < length; ++j)
    {
        key = *(arr + j);
        i   = j - 1;

        while (*(arr + i) > key)
        {
            *(arr + (i + 1)) = *(arr + i);
            i--;
        }

        *(arr + (i + 1)) = key;
    }
}

void
bubblesort(int * restrict arr, const uint length)
{
    if (!length)
        return;

    int i, j, temp;
    
    for (i = 0; i < length - 1; ++i)
        for (j = length - 1; j >= i + 1; --j)
            if (*(arr + j) < *(arr + (j - 1)))
            {
                temp = *(arr + j);
                *(arr + j) = *(arr + (j - 1));
                *(arr + (j - 1)) = temp;
            }
}

static void
merge(int * restrict arr, const uint p, const uint q, const uint r)
{
    if (p > q || q > r)
        return;

    int n1, n2, i, j, k;
    n1 = q - p;
    n2 = r - q;

    int L[n1 + 1];
    int R[n2 + 1];

    for (i = 0; i < n1 + 1; ++i)
        L[i] = arr[p + i];
    for (i = 0; i < n2 + 1; ++i)
        R[i] = arr[q + i];

    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    i = 0;
    j = 0;

    for (k = p; k < r; ++k)
        if (L[i] <= R[j])
            arr[k] = L[i++];
        else
            arr[k] = R[j++];
}

void
merge_sort(int * restrict arr, const uint p, const uint r)
{
    uint q;

    if (p < r)
    {
        q = (p + r) / 2;
        merge_sort(arr, p, q);
        merge_sort(arr, q, r);
        merge(arr, p, q, r);
    }
}

