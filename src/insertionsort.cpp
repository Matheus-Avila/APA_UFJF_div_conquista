#ifndef _INSERTIONSORT_H_
#include "insertionsort.h"

void insertionsort::ordena(int vet[], int tam){
    int j;
    int pivo;
    for(int i = 1; i<tam-1; i++){
        pivo = vet[i];
        for(j = i-1; j >= 0; j--){
            if(pivo<vet[j]){
                vet[j+1]= vet[j];
            }
            else{
                vet[j+1] = pivo;
            }
        }

    }
}


insertionsort::insertionsort(/* args */)
{
}

insertionsort::~insertionsort()
{
}

#endif