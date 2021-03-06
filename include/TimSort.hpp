#ifndef TIMSORT_HPP
#define TIMSORT_HPP

#include <iostream>
#include <time.h>
#include <tuple>
#include "Dados.hpp"
#include "MergeSort.hpp"
#include "InsertionSort.hpp"

class TimSort {
  public:
    TimSort(Dados *conjunto, int size);
    std::tuple<Dados*, clock_t> sort();
  
  protected:
    timSort(Dados *conjunto, int n);
    
}

#endif