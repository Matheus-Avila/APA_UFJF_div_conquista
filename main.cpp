#include <iostream>
#include <chrono>
#include "src/mergesort.h"
#include "src/insertionsort.h"
#include <time.h>
#include <vector>
#define Tamanho 100
#define valor_max 1000
using namespace std;


int main(){
    vector<int> vetor_numeros;
    srand(0);
    int random = 0;
    for(int i = 0; i < Tamanho; i++){
        random = rand()%valor_max;
        vetor_numeros.push_back(Tamanho-i);
    }
    mergesort* insert = new mergesort(vetor_numeros, Tamanho);
    for(int i =0; i < Tamanho; i++){
        cout << insert->vet[i]<<endl;
    }
    cout << "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
    insert->ordena(0,Tamanho-1);
    
    return 0;
}