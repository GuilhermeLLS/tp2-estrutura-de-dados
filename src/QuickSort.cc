#include "../include/Dados.hpp"
#include "../include/QuickSort.hpp"

QuickSort::QuickSort(Dados conjunto[], int size)
{
    this->conjuntoClasse = conjunto;
    this->size = size;
}

Dados *QuickSort::sort()
{
    this->quickSort(this->conjuntoClasse, 0, this->size - 1);
    return this->conjuntoClasse;
}

int QuickSort::partition(Dados *conjunto, int low, int high)
{
    Dados aux;
    Dados pivo = conjunto[high];
    int indiceMenor = low;

    for (int i = low; i < high; i++)
    {
        if (conjunto[i].distancia <= pivo.distancia)
        {
            aux = conjunto[i];
            conjunto[i] = conjunto[indiceMenor];
            conjunto[indiceMenor] = aux;
            indiceMenor++;
        }
    }

    aux = conjunto[high];
    conjunto[high] = conjunto[indiceMenor];
    conjunto[indiceMenor] = aux;

    return indiceMenor;
}

void QuickSort::quickSort(Dados *conjunto, int low, int high)
{
    if (low < high)
    {
        int indiceParticionamento = this->partition(conjunto, low, high);
        this->quickSort(conjunto, low, indiceParticionamento - 1);
        this->quickSort(conjunto, indiceParticionamento + 1, high);
    }
}
