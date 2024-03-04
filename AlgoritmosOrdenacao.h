#pragma once

#define MAX 10000

void bubbleSort(int* list, unsigned long long* comp, unsigned long long* troc,
    unsigned long long* it);

void selectionSort(int* list, unsigned long long* comp,
    unsigned long long* troc, unsigned long long* it);

void insertionSort(int* list, unsigned long long* comp,
    unsigned long long* troc, unsigned long long* it);

void quickSort(int* list, int ini, int fim, unsigned long long* comp,
    unsigned long long* troc, unsigned long long* it);
int particionar(int* list, int ini, int fim, unsigned long long* comp,
    unsigned long long* troc, unsigned long long* it);

void heapSort(int* list, unsigned long long* comp, unsigned long long* troc,
    unsigned long long* it);
void construirHeapMax(int* list, int qtdeElem, unsigned long long* comp,
    unsigned long long* troc, unsigned long long* it);
void maxHeapify(int* list, int i, int qtdeElem, unsigned long long* comp,
    unsigned long long* troc, unsigned long long* it);

//Quick sort com pivo aleatorio
void quickSortAleatorio(int* list, int ini, int fim, unsigned long long* comp,
    unsigned long long* troc, unsigned long long* it);
int particionarRandom(int* list, int ini, int fim, unsigned long long* comp,
    unsigned long long* troc, unsigned long long* it);
int particionarR(int* list, int ini, int fim, unsigned long long* comp,
    unsigned long long* troc, unsigned long long* it);

//Quick Sort com pivo utilizando a escolha mediana de 3
void quickSortMedianaDe3(int* list, int ini, int fim, unsigned long long* comp,
    unsigned long long* troc, unsigned long long* it);
int particionarMediana3(int* list, int ini, int fim, unsigned long long* comp,
    unsigned long long* troc, unsigned long long* it);
