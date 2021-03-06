#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <iostream>
#include <time.h>
#include <tuple>
#include "Dados.hpp"

class QuickSort
{
public:
    QuickSort(Dados conjunto[], int size);
    std::tuple<Dados*, clock_t> sort(std::string type);

protected:
    int partition(Dados conjunto[], int low, int high);
    void quickSort(Dados conjunto[], int low, int high);
    void quickSortIterative(Dados conjunto[], int low, int high);
private:
    Dados *conjuntoClasse;
    int size;
};

#endif