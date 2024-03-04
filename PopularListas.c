#include <stdlib.h>

#include "PopularListas.h"

void preencherAleatorio(int* listBubble, int* listSelection, int* listInsertion,
    int* listQuick, int* listHeap) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < MAX; i++) {
        j = rand();
        listBubble[i] = j;
        listSelection[i] = j;
        listInsertion[i] = j;
        listQuick[i] = j;
        listHeap[i] = j;
    }
}

void preencherMetadeOrdenado(int* listBubble, int* listSelection, int* listInsertion, 
    int* listQuick, int* listHeap) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < MAX / 2; i++) {
        listBubble[i] = i;
        listSelection[i] = i;
        listInsertion[i] = i;
        listQuick[i] = i;
        listHeap[i] = i;
    }
    for (; i < MAX; i++) {
        j = rand();
        listBubble[i] = j;
        listSelection[i] = j;
        listInsertion[i] = j;
        listQuick[i] = j;
        listHeap[i] = j;
    }
}

void preencher75Ordenado(int* listBubble, int* listSelection, int* listInsertion, 
    int* listQuick, int* listHeap) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < MAX * 0.75; i++) {
        listBubble[i] = i;
        listSelection[i] = i;
        listInsertion[i] = i;
        listQuick[i] = i;
        listHeap[i] = i;
    }
    for (; i < MAX; i++) {
        j = rand();
        listBubble[i] = j;
        listSelection[i] = j;
        listInsertion[i] = j;
        listQuick[i] = j;
        listHeap[i] = j;
    }
}

void preencherOrdenado(int* listBubble, int* listSelection, int* listInsertion,
    int* listQuick, int* listHeap) {
    int i;
    for (i = 0; i < MAX; i++) {
        listBubble[i] = i;
        listSelection[i] = i;
        listInsertion[i] = i;
        listQuick[i] = i;
        listHeap[i] = i;
    }
}

void preencherOrdenadoDecrescente(int* listBubble, int* listSelection, int* listInsertion,
    int* listQuick, int* listHeap) {
    int i, j;
    for (i = MAX - 1, j = 0; i >= 0, j < MAX; i--, j++) {
        listBubble[j] = i;
        listSelection[j] = i;
        listInsertion[j] = i;
        listQuick[j] = i;
        listHeap[j] = i;
    }
}
