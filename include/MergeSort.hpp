#ifndef MERGESORT_HPP
#define MERGESORT_HPP

#include <iostream>
#include "Dados.hpp"

class MergeSort
{
public:
    MergeSort(Dados *conjunto, int size);
    Dados *sort();

protected:
    void merge(Dados *conjunto, int left, int middle, int right);
    void mergeSort(Dados *conjunto, int left, int right);

private:
    Dados *conjuntoClasse;
    int size;
};

#endif