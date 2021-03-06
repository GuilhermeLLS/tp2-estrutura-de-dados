#include "../include/Dados.hpp"
#include "../include/MergeSort.hpp"

MergeSort::MergeSort(Dados *conjunto, int size)
{
    this->conjuntoClasse = conjunto;
    this->size = size;
}

std::tuple<Dados *, clock_t>MergeSort::sort()
{
    clock_t time = clock();
    this->mergeSort(this->conjuntoClasse, 0, this->size - 1);
    time = clock() - time;
    return {this->conjuntoClasse, time};
}

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void MergeSort::merge(Dados *arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    Dados L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]

    // Initial index of first subarray
    int i = 0;

    // Initial index of second subarray
    int j = 0;

    // Initial index of merged subarray
    int k = l;

    while (i < n1 && j < n2)
    {
        if (L[i].distancia <= R[j].distancia)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void MergeSort::mergeSort(Dados *arr, int l, int r)
{
    if (l >= r)
    {
        return; //returns recursively
    }
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}