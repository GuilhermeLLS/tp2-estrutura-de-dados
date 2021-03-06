#include "../include/Dados.hpp"
#include "../include/QuickSort.hpp"

QuickSort::QuickSort(Dados conjunto[], int size)
{
    this->conjuntoClasse = conjunto;
    this->size = size;
}

std::tuple<Dados *, clock_t> QuickSort::sort(std::string type)
{
    clock_t time;
    if (type == "iterativo")
    {
        time = clock();
        this->quickSortIterative(this->conjuntoClasse, 0, this->size - 1);
        time = clock() - time;
    }
    else if (type == "recursivo")
    {
        time = clock();
        this->quickSort(this->conjuntoClasse, 0, this->size - 1);
        time = clock() - time;
    }
    else
    {
        throw std::runtime_error("Tipo não reconhecido. Escolha iterativo ou recursivo");
    }
    return {this->conjuntoClasse, time};
}

int QuickSort::partition(Dados *conjunto, int low, int high)
{
    Dados aux;
    Dados pivo = conjunto[high / 2];
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

void QuickSort::quickSortIterative(Dados *conjunto, int low, int high)
{
    // Create an auxiliary stack
    int stack[high - low + 1];

    // initialize top of stack
    int top = -1;

    // push initial values of l and h to stack
    stack[++top] = low;
    stack[++top] = high;

    // Keep popping from stack while is not empty
    while (top >= 0)
    {
        // Pop h and l
        high = stack[top--];
        low = stack[top--];

        // Set pivot element at its correct position
        // in sorted array
        int p = partition(conjunto, low, high);

        // If there are elements on left side of pivot,
        // then push left side to stack
        if (p - 1 > low)
        {
            stack[++top] = low;
            stack[++top] = p - 1;
        }

        // If there are elements on right side of pivot,
        // then push right side to stack
        if (p + 1 < high)
        {
            stack[++top] = p + 1;
            stack[++top] = high;
        }
    }
}