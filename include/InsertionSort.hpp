#ifndef INSERTIONSORT_HPP
#define INSERTIONSORT_HPP

#include <iostream>
#include "Dados.hpp"

class InsertionSort
{
public:
    InsertionSort(Dados conjunto[], int size);
    Dados *sort();

protected:
    void insertionSort(Dados conjunto[], int size);

private:
    Dados *conjuntoClasse;
    int size;
};

#endif