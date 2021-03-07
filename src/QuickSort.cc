#include "../include/Dados.hpp"
#include "../include/QuickSort.hpp"

QuickSort::QuickSort(Dados *conjunto, int size)
{
    this->conjuntoClasse = conjunto;
    this->size = size;
}

void QuickSort::partitionRecursive(Dados *planeta, int esquerda, int direita, int *i, int *j)
{
    Dados x, w;
    *i = esquerda;
    *j = direita;
    x = planeta[(*i + *j) / 2];
    do
    {
        while (x.distancia > planeta[*i].distancia)
            (*i)++;
        while (x.distancia < planeta[*j].distancia)
            (*j)--;
        if (*i <= *j)
        {
            w = planeta[*i];
            planeta[*i] = planeta[*j];
            planeta[*j] = w;
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

void QuickSort::quickSortRecursive(Dados *dados, int esquerda, int direita)
{
    int i, j;
    partitionRecursive(dados, esquerda, direita, &i, &j);
    if (esquerda < j)
        quickSortRecursive(dados, esquerda, j);
    if (i < direita)
        quickSortRecursive(dados, i, direita);
}

std::tuple<Dados *, clock_t> QuickSort::sort(std::string tipo)
{
    clock_t time;
    if (tipo == "iterativo")
    {
        time = clock();
        this->quickSortIterative(this->conjuntoClasse, 0, this->size - 1);
        time = clock() - time;
    }
    else if (tipo == "recursivo")
    {
        time = clock();
        quickSortRecursive(this->conjuntoClasse, 0, this->size - 1);
        time = clock() - time;
    }
    else
    {
        throw std::runtime_error("Tipo não reconhecido. Escolha iterativo ou recursivo");
    }
    return {this->conjuntoClasse, time};
}

void QuickSort::troca(Dados *troca1, Dados *troca2)
{
    Dados aux = *troca1;
    *troca1 = *troca2;
    *troca2 = aux;
}

int QuickSort::partitionIterative(Dados *conjunto, int esquerda, int direita)
{
    Dados pivo = conjunto[direita / 2];
    int i = (esquerda - 1);

    for (int j = esquerda; j < direita; j++)
    {
        if (conjunto[j].distancia <= pivo.distancia)
        {
            i++;
            troca(&conjunto[i], &conjunto[j]);
        }
    }
    troca(&conjunto[i + 1], &conjunto[direita]);
    return (i + 1);
}

// void QuickSort::quickSort(Dados *conjunto, int esquerda, int direita)
// {
//     if (esquerda < direita)
//     {
//         int indiceParticionamento = partition(conjunto, esquerda, direita);
//         quickSort(conjunto, esquerda, indiceParticionamento - 1);
//         quickSort(conjunto, indiceParticionamento + 1, direita);
//     }
// }

void QuickSort::quickSortIterative(Dados *conjunto, int esquerda, int direita)
{
    int *pilha = new int[direita - esquerda + 1];

    int topo = -1;

    pilha[++topo] = esquerda;
    pilha[++topo] = direita;

    while (topo >= 0)
    {
        direita = pilha[topo--];
        esquerda = pilha[topo--];

        int pivo = partitionIterative(conjunto, esquerda, direita);

        if (pivo - 1 > esquerda)
        {
            pilha[++topo] = esquerda;
            pilha[++topo] = pivo - 1;
        }

        if (pivo + 1 < direita)
        {
            pilha[++topo] = pivo + 1;
            pilha[++topo] = direita;
        }
    }
    free(pilha);
}