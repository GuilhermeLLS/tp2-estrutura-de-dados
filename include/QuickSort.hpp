#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <iostream>
#include "Dados.hpp"

class QuickSort
{
public:
    QuickSort(Dados conjunto[]);
    Dados *sort();

protected:
    void swap(Dados *a, Dados *b);
    int partition(Dados conjunto[], int low, int high);
    void quickSort(Dados conjunto[], int low, int high);

private:
    Dados *conjuntoClasse;
};

#endif