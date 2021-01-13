#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_

using namespace std;

class quicksort
{
private:

    void trocaDePosicao(int i, int j, int *vet);
    int particao(int start, int end, int *vet);
public:
    quicksort(/* args */);
    void ordena(int start, int end, int *vet);
    ~quicksort();
};




#endif