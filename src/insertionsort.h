#ifndef _INSERTIONSORT_H_
#define _INSERTIONSORT_H_
#include <vector>
class insertionsort
{
private:
    int tamanho;
    std::vector<int> vet;
public:
    insertionsort(std::vector<int> vetor, int tamanho);
    void ordena();
    ~insertionsort();
};

#endif