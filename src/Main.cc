#include <fstream>
#include <string>
#include <iostream>
#include <time.h>
#include "../include/Dados.hpp"
#include "../include/QuickSort.hpp"
#include "../include/InsertionSort.hpp"
#include "../include/MergeSort.hpp"

void imprimirConjunto(Dados *conjunto, int tamanho, clock_t execTime, std::string algoType)
{
    std::cout << "=================================" << std::endl;
    std::cout << algoType << ":" << std::endl;
    // for (int i = 0; i < tamanho; i++)
    // {
    // std::cout << conjunto[i].nome << ", " << conjunto[i].distancia << std::endl;
    // }
    std::cout << "Execution time: " << ((double)execTime) / ((CLOCKS_PER_SEC / 1000)) << "ms" << std::endl; //conversão para double
}

int main(int argc, char *argv[])
{
    std::string nomeArquivo = argv[1];
    int linhasParaLer = atoi(argv[2]);

    Dados conjunto[linhasParaLer];
    std::ifstream dadosInput(nomeArquivo);
    int i = linhasParaLer;
    while (i > 0)
    {
        std::string line;
        getline(dadosInput, line);
        std::string delimiter = " ";
        size_t pos = 0;
        std::string token;
        while ((pos = line.find(delimiter)) != std::string::npos)
        {
            token = line.substr(0, pos);
            conjunto[i - 1].nome = token;
            line.erase(0, pos + delimiter.length());
        }
        conjunto[i - 1].distancia = stoi(line);
        i--;
    }

    QuickSort sorter = QuickSort(conjunto, linhasParaLer);
    Dados *auxQuickIterativo;
    clock_t execTimeQuickIterativo;
    std::tie(auxQuickIterativo, execTimeQuickIterativo) = sorter.sort("iterativo");
    imprimirConjunto(auxQuickIterativo, linhasParaLer, execTimeQuickIterativo, "Quicksort iterativo");

    Dados *auxQuickRecursivo;
    clock_t execTimeQuickRecursivo;
    std::tie(auxQuickRecursivo, execTimeQuickRecursivo) = sorter.sort("recursivo");
    imprimirConjunto(auxQuickRecursivo, linhasParaLer, execTimeQuickRecursivo, "Quicksort recursivo");

    InsertionSort inSorter = InsertionSort(conjunto, linhasParaLer);
    Dados *auxIns;
    clock_t execTimeInsertion;
    std::tie(auxIns, execTimeInsertion) = inSorter.sort();
    imprimirConjunto(auxIns, linhasParaLer, execTimeInsertion, "InsertionSort");

    MergeSort mergSorter = MergeSort(conjunto, linhasParaLer);
    Dados *auxMergeSort;
    clock_t execTimeMerge;
    std::tie(auxMergeSort, execTimeMerge) = mergSorter.sort();
    imprimirConjunto(auxMergeSort, linhasParaLer, execTimeMerge, "MergeSort");

    return 0;
}