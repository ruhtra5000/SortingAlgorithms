#include <stdlib.h>
#include <time.h>

#include "AlgoritmosOrdenacao.h"

void bubbleSort(int* list, unsigned long long* comp, unsigned long long* troc,
    unsigned long long* it) {
    int i, j, temp;
    for (i = 0; i < MAX - 1; i++) {
        (*it)++;
        for (j = 0; j < MAX - 1 - i; j++) {
            (*it)++;
            (*comp)++;
            if (list[j] > list[j + 1]) {
                // Swap
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
                (*troc)++;
            }
        }
    }
}

void selectionSort(int* list, unsigned long long* comp,
    unsigned long long* troc, unsigned long long* it) {
    int i, j, menorIndex, tmp;
    for (i = 0; i < MAX; i++) {
        (*it)++;
        menorIndex = i;
        // Busca do indice do menor elemento da lista
        for (j = i + 1; j < MAX; j++) {
            (*it)++;
            (*comp)++;
            if (list[j] < list[menorIndex]) {
                menorIndex = j;
            }
        }
        // Swap do elemento no indice i com o menor elemento no indice menorIndex
        tmp = list[i];
        list[i] = list[menorIndex];
        list[menorIndex] = tmp;
        (*troc)++;
    }
}

void insertionSort(int* list, unsigned long long* comp,
    unsigned long long* troc, unsigned long long* it) {
    int i, j, key;
    for (i = 1; i < MAX; i++) {
        (*it)++;
        key = list[i];
        // Movendo os elementos da lista para a direita,
        // elementos maiores que a chave do elemento no indice i
        for (j = i - 1; j >= 0 && list[j] > key; j--) {
            (*it)++;
            (*comp)++;
            list[j + 1] = list[j];
            (*troc)++;
        }
        list[j + 1] = key;
        (*troc)++;
    }
}

void quickSort(int* list, int ini, int fim, unsigned long long* comp,
    unsigned long long* troc, unsigned long long* it) {
    // Chamada recursiva = +1 iteraçao
    (*it)++;
    (*comp)++;
    if (ini < fim) {
        int indexPivo = particionar(list, ini, fim, comp, troc, it);
        quickSort(list, ini, indexPivo - 1, comp, troc, it);
        quickSort(list, indexPivo + 1, fim, comp, troc, it);
    }
}

int particionar(int* list, int ini, int fim, unsigned long long* comp,
    unsigned long long* troc, unsigned long long* it) {
    int pivo = list[fim];
    int index = ini - 1;
    for (int q = ini; q < fim; q++) {
        (*it)++;
        (*comp)++;
        if (list[q] <= pivo) {
            index++;
            // Swap
            int temp = list[q];
            list[q] = list[index];
            list[index] = temp;
            (*troc)++;
        }
    }
    int temp = list[index + 1];
    list[index + 1] = list[fim];
    list[fim] = temp;
    (*troc)++;

    return index + 1;
}

void heapSort(int* list, unsigned long long* comp, unsigned long long* troc,
    unsigned long long* it) {
    int qtdeElem = MAX - 1, i, temp;
    construirHeapMax(list, qtdeElem, comp, troc, it);
    for (i = qtdeElem; i > 0; i--) {
        (*it)++;
        temp = list[0];
        list[0] = list[i];
        list[i] = temp;
        (*troc)++;

        qtdeElem--;
        maxHeapify(list, 0, qtdeElem, comp, troc, it);
    }
}

void construirHeapMax(int* list, int qtdeElem, unsigned long long* comp,
    unsigned long long* troc, unsigned long long* it) {
    int i;
    for (i = qtdeElem / 2; i > -1; i--) {
        (*it)++;
        maxHeapify(list, i, qtdeElem, comp, troc, it);
    }
}

void maxHeapify(int* list, int i, int qtdeElem, unsigned long long* comp,
    unsigned long long* troc, unsigned long long* it) {
    int esq = (2 * i) + 1, dir = (2 * i) + 2;
    int maior = i, temp;
    if (esq <= qtdeElem && list[esq] > list[maior]) {
        maior = esq;
    }
    if (dir <= qtdeElem && list[dir] > list[maior]) {
        maior = dir;
    }
    (*comp) += 3;

    if (maior != i) {
        temp = list[maior];
        list[maior] = list[i];
        list[i] = temp;
        (*troc)++;
        maxHeapify(list, maior, qtdeElem, comp, troc, it);
    }
}

//Quick sort com pivô aleatório
void quickSortAleatorio(int* list, int ini, int fim, unsigned long long* comp,
    unsigned long long* troc, unsigned long long* it) {
    // Chamada recursiva = +1 iteraçao
    (*it)++;
    (*comp)++;
    if (ini < fim) {
        int indexPivo = particionarRandom(list, ini, fim, comp, troc, it);
        quickSort(list, ini, indexPivo - 1, comp, troc, it);
        quickSort(list, indexPivo + 1, fim, comp, troc, it);
    }
}

int particionarRandom(int* list, int ini, int fim, unsigned long long* comp,
    unsigned long long* troc, unsigned long long* it) {
    //Chamada da função = +1 iteração
    (*it)++;
    
    srand(time(0));
    int random = ini + rand() % (fim - ini);

    int temp = list[random];
    list[random] = list[ini];
    list[ini] = temp;
    (*troc)++;

    return particionarR(list, ini, fim, comp, troc, it);
}

int particionarR(int* list, int ini, int fim, unsigned long long* comp,
    unsigned long long* troc, unsigned long long* it) {
    int pivo = list[fim];
    int index = ini;
    for (int q = ini; q < fim; q++) {
        (*it)++;
        (*comp)++;
        if (list[q] <= pivo) {
            // Swap
            int temp = list[q];
            list[q] = list[index];
            list[index] = temp;
            (*troc)++;

            index++;
        }
    }
    int temp = list[index];
    list[index] = list[fim];
    list[fim] = temp;
    (*troc)++;

    return index;
}

//Quick Sort Mediana de 3
void quickSortMedianaDe3(int* list, int ini, int fim, unsigned long long* comp,
    unsigned long long* troc, unsigned long long* it) {
    // Chamada recursiva = +1 iteraçao
    (*it)++;
    (*comp)++;
    if (ini < fim) {
        int indexPivo = particionarMediana3(list, ini, fim, comp, troc, it);
        quickSort(list, ini, indexPivo - 1, comp, troc, it);
        quickSort(list, indexPivo + 1, fim, comp, troc, it);
    }
}

int particionarMediana3(int* list, int ini, int fim, unsigned long long* comp,
    unsigned long long* troc, unsigned long long* it) {

    int temp;
    int meio = (ini + fim) / 2;

    (*comp)++;
    if (list[meio] < list[ini]) {
        temp = list[meio];
        list[meio] = list[ini];
        list[ini] = temp;
        (*troc)++;
    }
    (*comp)++;
    if (list[fim] < list[ini]) {
        temp = list[fim];
        list[fim] = list[ini];
        list[ini] = temp;
        (*troc)++;
    }
    (*comp)++;
    if (list[fim] < list[meio]) {
        temp = list[fim];
        list[fim] = list[meio];
        list[meio] = temp;
        (*troc)++;
    }
    temp = list[meio];
    list[meio] = list[fim - 1];
    list[fim - 1] = temp;
    (*troc)++;

    particionar(list, ini, fim, comp, troc, it);
}
