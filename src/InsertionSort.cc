#include "../include/Dados.hpp"
#include "../include/InsertionSort.hpp"

InsertionSort::InsertionSort(Dados *conjunto, int size)
{
    this->conjuntoClasse = conjunto;
    this->size = size;
}

Dados *InsertionSort::sort()
{
    this->insertionSort(this->conjuntoClasse, this->size);
    return this->conjuntoClasse;
}

void InsertionSort::insertionSort(Dados *conjunto, int size)
{
    Dados key;
    int i, j;
    for (i = 1; i < size; i++)
    {
        key = conjunto[i];
        j = i - 1;

        /* Move elements of conjunto[0..i-1], that are 
        greater than key, to one position ahead 
        of their current position */
        while (j >= 0 && conjunto[j].distancia > key.distancia)
        {
            conjunto[j + 1] = conjunto[j];
            j = j - 1;
        }
        conjunto[j + 1] = key;
    }
}