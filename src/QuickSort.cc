/* C implementation QuickSort */
#include "../include/Dados.hpp"
#include "../include/QuickSort.hpp"

QuickSort::QuickSort(Dados conjunto[])
{
    this->conjuntoClasse = conjunto;
}

Dados *QuickSort::sort()
{
    int n = sizeof(this->conjuntoClasse) / sizeof(this->conjuntoClasse[0]);
    std::cout << n << std::endl;
    quickSort(this->conjuntoClasse, 0, 49);
    return this->conjuntoClasse;
}

void QuickSort::swap(Dados *a, Dados *b)
{
    Dados aux = *a;
    *a = *b;
    *b = aux;
}

int QuickSort::partition(Dados *conjunto, int low, int high)
{
    Dados pivo = conjunto[high];
    int indiceMenor = low - 1;

    for (int i = low; i <= high; i++)
    {
        if (conjunto[i].distancia <= pivo.distancia)
        {
            indiceMenor++;
            this->swap(&conjunto[indiceMenor], &conjunto[i]);
        }
    }
    this->swap(&conjunto[indiceMenor + 1], &conjunto[high]);
    return indiceMenor + 1;
}

void QuickSort::quickSort(Dados *conjunto, int low, int high)
{
    std::cout << "entrei " << low << "," << high << std::endl;
    if (low < high)
    {
        int indiceParticionamento = this->partition(conjunto, low, high);
        std::cout << indiceParticionamento << std::endl;
        this->quickSort(conjunto, low, indiceParticionamento - 1);
        this->quickSort(conjunto, indiceParticionamento + 1, high);
    }
}
