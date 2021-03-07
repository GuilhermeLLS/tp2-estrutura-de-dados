#ifndef MERGESORT_HPP
#define MERGESORT_HPP

#include <iostream>
#include <time.h>
#include <tuple>
#include "Dados.hpp"

class MergeSort
{
public:
    MergeSort(Dados *conjunto, int size);
    std::tuple<Dados *, clock_t> sort();

protected:
    void merge(Dados *conjunto, int left, int middle, int right);
    void mergeSort(Dados *conjunto, int left, int right);

private:
    Dados *conjuntoClasse;
    int size;

    friend class TimSort;
};

#endif