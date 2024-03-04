#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "AlgoritmosOrdenacao.h"
#include "PopularListas.h"

// Auxiliar
void zerarVariaveis(unsigned long long* comp, unsigned long long* troc,
    unsigned long long* it);

int main(void) {
    int* listBubble = (int*) malloc(MAX * sizeof(int));
    int* listSelection = (int*) malloc(MAX * sizeof(int));
    int* listInsertion = (int*) malloc(MAX * sizeof(int));
    int* listQuick = (int*) malloc(MAX * sizeof(int));
    int* listHeap = (int*) malloc(MAX * sizeof(int));

    if (listBubble != NULL && listSelection != NULL && listInsertion != NULL && listQuick != NULL && listHeap != NULL)
        printf("(Memoria alocada)\n\n");

    unsigned long long comparacoes = 0, trocas = 0, iteracoes = 0;

    clock_t start, end;
    unsigned long long tempo;

    preencherAleatorio(listBubble, listSelection, listInsertion, listQuick, listHeap);
    //preencherMetadeOrdenado(listBubble, listSelection, listInsertion, listQuick, listHeap);
    //preencher75Ordenado(listBubble, listSelection, listInsertion, listQuick, listHeap);
    //preencherOrdenado(listBubble, listSelection, listInsertion, listQuick, listHeap);
    //preencherOrdenadoDecrescente(listBubble, listSelection, listInsertion, listQuick, listHeap);

    // Bubble sort
    start = clock() / (CLOCKS_PER_SEC / 1000);
    bubbleSort(listBubble, &comparacoes, &trocas, &iteracoes);
    end = clock() / (CLOCKS_PER_SEC / 1000);
    tempo = end - start;

    printf("Bubble sort demorou %llu milissegundos para ordenar %d "
        "elementos\nComparacoes: %llu\nTrocas: %llu\nIteracoes: %llu\n\n",
        tempo, MAX, comparacoes, trocas, iteracoes);

    zerarVariaveis(&comparacoes, &trocas, &iteracoes);

    // Selection sort
    start = clock() / (CLOCKS_PER_SEC / 1000);
    selectionSort(listSelection, &comparacoes, &trocas, &iteracoes);
    end = clock() / (CLOCKS_PER_SEC / 1000);
    tempo = end - start;

    printf("Selection sort demorou %llu milissegundos para ordenar %d "
        "elementos\nComparacoes: %llu\nTrocas: %llu\nIteracoes: %llu\n\n",
        tempo, MAX, comparacoes, trocas, iteracoes);

    zerarVariaveis(&comparacoes, &trocas, &iteracoes);

    // Insertion sort
    start = clock() / (CLOCKS_PER_SEC / 1000);
    insertionSort(listInsertion, &comparacoes, &trocas, &iteracoes);
    end = clock() / (CLOCKS_PER_SEC / 1000);
    tempo = end - start;

    printf("Insertion sort demorou %llu milissegundos para ordenar %d "
        "elementos\nComparacoes: %llu\nTrocas: %llu\nIteracoes: %llu\n\n",
        tempo, MAX, comparacoes, trocas, iteracoes);

    zerarVariaveis(&comparacoes, &trocas, &iteracoes);

    // Quick sort padrão
    start = clock() / (CLOCKS_PER_SEC / 1000);
    quickSort(listQuick, 0, MAX - 1, &comparacoes, &trocas, &iteracoes);
    end = clock() / (CLOCKS_PER_SEC / 1000);
    tempo = end - start;

    printf("Quick sort padrao demorou %llu milissegundos para ordenar %d "
        "elementos\nComparacoes: %llu\nTrocas: %llu\nIteracoes: %llu\n\n",
        tempo, MAX, comparacoes, trocas, iteracoes);

    zerarVariaveis(&comparacoes, &trocas, &iteracoes);

    // Heap sort
    start = clock() / (CLOCKS_PER_SEC / 1000);
    heapSort(listHeap, &comparacoes, &trocas, &iteracoes);
    end = clock() / (CLOCKS_PER_SEC / 1000);
    tempo = end - start;

    printf("Heap sort demorou %llu milissegundos para ordenar %d "
        "elementos\nComparacoes: %llu\nTrocas: %llu\nIteracoes: %llu\n\n",
        tempo, MAX, comparacoes, trocas, iteracoes);

    zerarVariaveis(&comparacoes, &trocas, &iteracoes);

    /*
    //Quick sort - pivô aleatório
    start = clock() / (CLOCKS_PER_SEC / 1000);
    quickSortAleatorio(listBubble, 0, MAX - 1, &comparacoes, &trocas, &iteracoes);
    end = clock() / (CLOCKS_PER_SEC / 1000);
    tempo = end - start;

    printf("Quick sort aleatorio demorou %llu milissegundos para ordenar %d "
        "elementos\nComparacoes: %llu\nTrocas: %llu\nIteracoes: %llu\n\n",
        tempo, MAX, comparacoes, trocas, iteracoes);

    zerarVariaveis(&comparacoes, &trocas, &iteracoes);

    //Quick sort - pivô mediana de 3
    start = clock() / (CLOCKS_PER_SEC / 1000);
    quickSortMedianaDe3(listHeap, 0, MAX - 1, &comparacoes, &trocas, &iteracoes);
    end = clock() / (CLOCKS_PER_SEC / 1000);
    tempo = end - start;

    printf("Quick sort mediana de 3 demorou %llu milissegundos para ordenar %d "
        "elementos\nComparacoes: %llu\nTrocas: %llu\nIteracoes: %llu\n\n",
        tempo, MAX, comparacoes, trocas, iteracoes);

    zerarVariaveis(&comparacoes, &trocas, &iteracoes);
    */
    
    return 0;
}

// Auxiliar
void zerarVariaveis(unsigned long long* comp, unsigned long long* troc,
    unsigned long long* it) {
    (*comp) = 0;
    (*troc) = 0;
    (*it) = 0;
}
