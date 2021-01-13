#ifndef _QUICKSORT_H_
#include "quicksort.h"

void quicksort::trocaDePosicao(int i, int j, int *vet)
{
    int k = vet[i];
    vet[i] = vet[j];
    vet[j] = k;
}

int quicksort::particao(int start, int end, int *vet)
{   
    int pivo = vet[end];
    int i = start-1;
    for (int j = start; j < end-1; j++)
    {
        if (vet[j] <= pivo)
        {   i++;
            trocaDePosicao(i, j, vet);
        }
    }

    trocaDePosicao(i+1, end, vet);
    
    return i + 1;
}

void quicksort::ordena(int start, int end, int *vet)
{   
    if (start >= end)
        return;

    int pivo = particao(start, end, vet);
    ordena(start, pivo - 1, vet);
    ordena(pivo + 1, end, vet);
}

quicksort::quicksort(/* args */)
{
}

quicksort::~quicksort()
{
}

#endif