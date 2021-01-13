#include <iostream>
#include <chrono>
#include "src/insertionsort.h"
#include "src/quicksort.h"
#include <time.h>
#include <vector>

using namespace std;


int main(){
    vector<int> vetor_numeros;
    vetor_numeros.push_back(25);
    vetor_numeros.push_back(15);
    vetor_numeros.push_back(25);
    vetor_numeros.push_back(5);
    vetor_numeros.push_back(35);
    vetor_numeros.push_back(5);
    vetor_numeros.push_back(35);
    for(int i = 0; i< vetor_numeros.size(); i++){
        cout << vetor_numeros[i]<<endl;
    }
    
    return 0;
}