#include "Test.h"
#include <fstream>
#include <string>
#include <iostream>
#include "../include/Dados.hpp"
#include "../include/QuickSort.hpp"

int main(int argc, char *argv[])
{
    std::string nomeArquivo = argv[1];
    int linhasParaLer = atoi(argv[2]);

    Dados conjunto[linhasParaLer];
    std::ifstream dadosInput(nomeArquivo);
    while (linhasParaLer > 0)
    {
        std::string line;
        getline(dadosInput, line);
        std::string delimiter = " ";
        size_t pos = 0;
        std::string token;
        while ((pos = line.find(delimiter)) != std::string::npos)
        {
            token = line.substr(0, pos);
            conjunto[linhasParaLer - 1].nome = token;
            line.erase(0, pos + delimiter.length());
        }
        conjunto[linhasParaLer - 1].distancia = stoi(line);
        linhasParaLer--;
    }

    // for (int i = 0; i < 50; i++)
    // {
        // std::cout << conjunto[i].nome << ", " << conjunto[i].distancia << std::endl;
    // }

    std::cout << "=================================" << std::endl;
    QuickSort sorter = QuickSort(conjunto);
    Dados *aux = sorter.sort();

    for (int i = 0; i < 50; i++)
    {
        std::cout << aux[i].nome << ", " << aux[i].distancia << std::endl;
    }

    return 0;
}