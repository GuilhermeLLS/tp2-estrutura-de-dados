#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <iostream>
#include <time.h>
#include <tuple>
#include "Dados.hpp"

class QuickSort
{
public:
    QuickSort(Dados *conjunto, int size);
    std::tuple<Dados *, clock_t> sort(std::string tipo);

protected:
    void troca(Dados *troca1, Dados *troca2);
    void partitionRecursive(Dados *conjunto, int esquerda, int direita, int *i, int *j);
    int partitionIterative(Dados *conjunto, int esquerda, int direita);
    void quickSortRecursive(Dados *conjunto, int esquerda, int direita);
    void quickSortIterative(Dados *conjunto, int esquerda, int direita);

private:
    Dados *conjuntoClasse;
    int size;
};

#endif