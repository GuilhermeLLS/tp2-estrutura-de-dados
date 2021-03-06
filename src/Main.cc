#include <fstream>
#include <string>
#include <iostream>
#include "../include/Dados.hpp"
#include "../include/QuickSort.hpp"
#include "../include/InsertionSort.hpp"
#include "../include/MergeSort.hpp"

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

    for (int i = 0; i < linhasParaLer; i++)
    {
        std::cout << conjunto[i].nome << ", " << conjunto[i].distancia << std::endl;
    }

    std::cout << "=================================" << std::endl;
    QuickSort sorter = QuickSort(conjunto, linhasParaLer);
    Dados *aux = sorter.sort();
    std::cout << "Quicksorted:" << std::endl;
    for (int i = 0; i < linhasParaLer; i++)
    {
        std::cout << aux[i].nome << ", " << aux[i].distancia << std::endl;
    }
    std::cout << "=================================" << std::endl;
    std::cout << "Insertsorted: " << std::endl;
    InsertionSort inSorter = InsertionSort(conjunto, linhasParaLer);
    Dados *auxIns = inSorter.sort();
        for (int i = 0; i < linhasParaLer; i++)
    {
        std::cout << auxIns[i].nome << ", " << auxIns[i].distancia << std::endl;
    }    
    std::cout << "=================================" << std::endl;
    std::cout << "Mergesorted: " << std::endl;
    MergeSort mergSorter = MergeSort(conjunto, linhasParaLer);
    Dados *auxMer = mergSorter.sort();
        for (int i = 0; i < linhasParaLer; i++)
    {
        std::cout << auxMer[i].nome << ", " << auxMer[i].distancia << std::endl;
    }
    return 0;
}