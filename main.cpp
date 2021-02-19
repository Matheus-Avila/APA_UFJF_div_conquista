#include <fstream>
#include <iostream>
#include <chrono>
#include "src/mergesort.h"
#include "src/insertionsort.h"
#include <time.h>
#include <vector>
#define Tamanho 100000

using namespace std;

vector<int> cria_vetor(int tipo_vetor){

    vector<int> vetor_numeros;
    if(tipo_vetor == 1 || tipo_vetor == 3){
        for(int i = 0; i < Tamanho; i++){
            vetor_numeros.push_back(i);
        }
    }else{
        for(int i = 0; i < Tamanho; i++){
            vetor_numeros.push_back(Tamanho-i);
        }
    }
    
    return vetor_numeros;
}
void salva_resultados(int menu, double media_tempo_execucao){

    fstream file_relatorio;
    if(menu == 1){//melhor caso do merge sort
        file_relatorio.open("./relatorios/merge_melhor_caso.txt", std::ios::app);
        file_relatorio << "Tempo medio de execucao no melhor caso de um vetor de tamanho " << Tamanho << endl;
        file_relatorio << media_tempo_execucao << " microssegundos" <<endl;        
    }else{
        if(menu == 2){
            file_relatorio.open("./relatorios/merge_pior_caso.txt", std::ios::app);
            file_relatorio << "Tempo medio de execucao no melhor caso de um vetor de tamanho " << Tamanho << endl;
            file_relatorio << media_tempo_execucao << " microssegundos" << endl;        
        }
        else{
            if(menu == 3){
            file_relatorio.open("./relatorios/insertion_melhor_caso.txt", std::ios::app);
            file_relatorio << "Tempo medio de execucao no melhor caso de um vetor de tamanho " << Tamanho << endl;
            file_relatorio << media_tempo_execucao << " microssegundos" << endl;        
            }else{
                file_relatorio.open("./relatorios/insertion_pior_caso.txt", std::ios::app);
                file_relatorio << "Tempo medio de execucao no melhor caso de um vetor de tamanho " << Tamanho << endl;
                file_relatorio << media_tempo_execucao << " microssegundos" << endl;
            }
        }
    }
    file_relatorio.close();
}
void executa_merge(int tipo_vetor){
    double media_tempo_execucao = 0;
    vector<int> vetor_numeros;
    for(int i =0; i < 10; i++){
        cout << "Iteracao " << i << " merge" << endl;
        vetor_numeros = cria_vetor(tipo_vetor);
        mergesort* merge = new mergesort(vetor_numeros, Tamanho);
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        merge->ordena(0, Tamanho-1);
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        media_tempo_execucao += std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
    }
    media_tempo_execucao = media_tempo_execucao/10.0;
    salva_resultados(tipo_vetor, media_tempo_execucao);
}

void executa_insertion(int tipo_vetor){
    double media_tempo_execucao = 0;
    vector<int> vetor_numeros;
    for(int i =0; i < 10; i++){
        cout << "Iteracao " << i << " insertion" << endl;
        vetor_numeros = cria_vetor(tipo_vetor);
        insertionsort* insertion = new insertionsort(vetor_numeros, Tamanho);
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        insertion->ordena();
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        media_tempo_execucao += std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
    }
    media_tempo_execucao = media_tempo_execucao/10.0;
    salva_resultados(tipo_vetor, media_tempo_execucao);
}

//Inicia o menu
void exibeMenu(){
    int menu = 1;//variavel para controle do menu
    
    while(menu != 0){
        cout << "Escolha uma das opções abaixo:\n" << endl;
        cout << "1: Executar MergeSort em um vetor ordenado(melhor caso) 10 vezes" << endl;
        cout << "2: Executar MergeSort em um vetor em ordem decrescente(pior caso) 10 vezes" << endl;
        cout << "3: Executar InsertionSort em um vetor ordenado(melhor caso) 10 vezes" << endl;
        cout << "4: Executar InsertionSort em um vetor em ordem decrescente(pior caso) 10 vezes" << endl;
        cout << "5: Executar todas as opções acima" << endl;
        cout << "0: Encerra o programa"<< endl;
        
        if (!(cin >> menu)){
          cin.clear();
          cin.ignore();
          menu = 9;
        }
        
        switch (menu)
        {
        case 1://Melhor caso
        //Substitui tudo por uma funcao que executa 10vezes e tira a media?
            executa_merge(1);
            break;
        
        case 2://Pior caso
            executa_merge(2);
            break;
        
        case 3://Melhor caso
            executa_insertion(3);   
            break;
        
        case 4://Pior caso
            executa_insertion(4);
            break;

        case 5://Todos os casos a cima serão executados
            executa_merge(1);
            cout << "merge 1 finalizado" << endl;
            executa_merge(2);
            cout << "merge 2 finalizado" << endl;
            executa_insertion(3);
            cout << "insertion 1 finalizado" << endl;
            executa_insertion(4);
            break;

        case 0:
            break;

        default:
            cout << "O valor digitado não corresponde a nenhum comando!" << endl;
        }
    }
}

int main(){
    exibeMenu();
    return 0;
}