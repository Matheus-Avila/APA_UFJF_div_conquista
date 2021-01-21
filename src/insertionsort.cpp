#ifndef _INSERTIONSORT_H_
#include "insertionsort.h"
#include <vector>

void insertionsort::ordena(){
    int i = 0, j = 0;
    int chave;
    for(j=1;j<tamanho;j++){
        chave = vet[j];
        i = j-1;
        while(i>0 && vet[i]>chave){
            vet[i+1] = vet[i];
            i--;
        }
        vet[i+1] = chave;
    }
}


insertionsort::insertionsort(std::vector<int> vetor, int tamanho)
{
    this->vet = vetor;
    this->tamanho = tamanho;
}

insertionsort::~insertionsort()
{
}

#endif