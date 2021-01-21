#ifndef _INSERTIONSORT_H_
#define _INSERTIONSORT_H_
#include <vector>
class insertionsort
{
private:
    int tamanho;
public:
    std::vector<int> vet;
    insertionsort(std::vector<int> vetor, int tamanho);
    void ordena();
    ~insertionsort();
};

#endif