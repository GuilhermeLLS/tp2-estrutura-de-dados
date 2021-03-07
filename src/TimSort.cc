#include "../include/Dados.hpp"
#include "../include/MergeSort.hpp"
#include "../include/InsertionSort.hpp"
#include "../include/TimSort.hpp"

const int RUN = 256;

void insertionSort(Dados conjunto[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        Dados temp = conjunto[i];
        int j = i - 1;
        while (j >= left && conjunto[j].distancia > temp.distancia)
        {
            conjunto[j + 1] = conjunto[j];
            j--;
        }
        conjunto[j + 1] = temp;
    }
}

TimSort::TimSort(Dados *conjunto, int size)
{
    this->conjuntoClasse = conjunto;
    this->size = size;
}

std::tuple<Dados *, clock_t> TimSort::sort()
{
    clock_t time = clock();
    this->timSort(this->conjuntoClasse, this->size);
    time = clock() - time;
    return {this->conjuntoClasse, time};
}

void TimSort::timSort(Dados *conjunto, int size)
{
    MergeSort mergeSorter = MergeSort(conjunto, size);

    // Sort individual subarrays of size RUN
    for (int i = 0; i < size; i += RUN)
        insertionSort(conjunto, i, std::min((i + 31), (size - 1)));

    // Start merging from size RUN (or 32).
    // It will merge
    // to form size 64, then 128, 256
    // and so on ....
    for (int chunkSize = RUN; chunkSize < size;
         chunkSize = 2 * chunkSize)
    {

        // pick starting point of
        // left sub array. We
        // are going to merge
        // arr[left..left+chunkSize-1]
        // and arr[left+chunkSize, left+2*chunkSize-1]
        // After every merge, we
        // increase left by 2*chunkSize
        for (int left = 0; left < size;
             left += 2 * chunkSize)
        {

            // find ending point of
            // left sub array
            // mid+1 is starting point
            // of right sub array
            // std::cout << "chunkSize " << chunkSize << std::endl;
            int mid = left + chunkSize - 1;
            int right = std::min((left + 2 * chunkSize - 1),
                                 (size - 1));
            
            if (mid >= right) {
                int diff = mid - right;
                int avg = (right - left) / 2;
                mid = mid - diff - avg;
            }

            // merge sub array arr[left.....mid] &
            // arr[mid+1....right]
            mergeSorter.merge(conjunto, left, mid, right);
        }
    }
}