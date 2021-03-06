#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <iostream>
#include "Dados.hpp"

class QuickSort
{
public:
    QuickSort(Dados conjunto[], int size);
    Dados *sort();

protected:
    int partition(Dados conjunto[], int low, int high);
    void quickSort(Dados conjunto[], int low, int high);

private:
    Dados *conjuntoClasse;
    int size;
};

#endif