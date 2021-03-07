#ifndef TIMSORT_HPP
#define TIMSORT_HPP

#include <iostream>
#include <time.h>
#include <tuple>
#include <bits/stdc++.h> 

class TimSort
{
public:
  TimSort(Dados *conjunto, int size);
  std::tuple<Dados*, clock_t> sort();

protected:
  void timSort(Dados *conjunto, int n);

private:
  Dados *conjuntoClasse;
  int size;
};

#endif