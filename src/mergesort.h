#ifndef _MERGESORT_H_
#define _MERGESORT_H_
#include <vector>

class mergesort
{
private:
    int tamanho;
    void intercalaMerge(int inicio, int fim, int meio);
    std::vector<int> vet;
public:
    mergesort(std::vector<int> vetor, int tam);
    void ordena(int inicio, int fim);
    ~mergesort();
};

#endif