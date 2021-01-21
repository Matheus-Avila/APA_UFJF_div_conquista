#ifndef _mergeSORT_H_
#include "mergesort.h"
#include <vector>
#include <iostream>
mergesort::mergesort(std::vector<int> vetor, int tam){
    this->vet = vetor;
    tamanho = tam;
}

mergesort::~mergesort(){

}/*
void mergesort::intercalaMerge(int inicio, int fim, int meio){
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int *L = new int[n1];
    int *R = new int[n2];
    L[n1-1] = -1;
    R[n2-1] = -1;

    for(int i =0; i< n1-1;i++){
        L[i] = vet[inicio+i-1];
    }
    for(int j =0; j< n2-1;j++){
        R[j] = vet[meio+j];
    }
    int i = 0;
    int j = 0;
    for(int k = inicio; k< fim;k++){
        if(L[i]<=R[i] && L[i] != -1){
            vet[k] = L[i];
            i++;
        }
        else{
            vet[k] = R[i];
            j++;
        }
        
    }

    delete []L;
    delete []R;
}*/
void mergesort::intercalaMerge(int inicio, int fim, int meio){  
    int posLivre=0, inicio_vetor1, inicio_vetor2;  
    int aux[fim+1]; 
    inicio_vetor1 = inicio;  
    inicio_vetor2 = meio+1;  
        
    while(inicio_vetor1 <= meio && inicio_vetor2 <= fim){  
        
        if (vet[inicio_vetor1] <= vet[inicio_vetor2])  
        {   
            aux[posLivre] = vet[inicio_vetor1];  
            inicio_vetor1++;  
        }
        else{  
            
            aux[posLivre] = vet[inicio_vetor2];  
            inicio_vetor2++;  
        }  
        posLivre++;  
    }
    
    //se ainda existem numeros no primeiro vetor  
    //que nao foram intercalados  
    while (inicio_vetor1 <= meio)  
    {   
        aux[posLivre] = vet[inicio_vetor1];  
        posLivre++;  
        inicio_vetor1++;
    }  
    
    //se ainda existem numeros no segundo vetor  
    //que nao foram intercalados  
    while (inicio_vetor2 <= fim)  
    {   
        aux[posLivre] = vet[inicio_vetor2];  
        posLivre++;  
        inicio_vetor2++;
    }
    
    //retorne os valores do vetor aux para o vetor X  
    for (int i = inicio; i <=fim; i++)  
    {   
        this->vet[i] = aux[i];
    }
    
}  

void mergesort::ordena(int inicio, int fim){ 
     
    int meio; 
    if (inicio < fim)  
    {  
        meio = int((inicio+fim)/2);  
        ordena(inicio, meio);  
        ordena(meio+1, fim);  
        intercalaMerge(inicio, fim, meio);  
    }  
} 
#endif