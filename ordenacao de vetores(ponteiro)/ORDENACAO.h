/* 
 * File:   ordenação.h
 * Author: 2025.1.08.030
 *
 * Created on 30 de maio de 2025, 09:19
 */

#ifndef ORDENACAO_H
#define ORDENACAO_H

#include <iostream>

using namespace std;
//essa funçao inicia os valores dos vetores sempre antes de uma ordenaçao começar

void vetores(int vCresc[], int vDecre[], int vAleat[], int TAM) {
    int tempoCresc[TAM] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20}; // melhor caso
    int tempoDecre[TAM] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11}; // pior caso
    int tempoAleat[TAM] = {17, 14, 16, 12, 20, 15, 19, 11, 13, 18}; // caso aleatório

    int *a = vAleat, *d = vDecre, *c = vCresc;

    // Copia os valores para os vetores de saída 
    for (int i = 0; i < TAM; i++) {
        *c++ = tempoCresc[i];
        *d++ = tempoDecre[i];
        *a++ = tempoAleat[i];
    }
}

//lista os valores antes e depois da ordenaçao

void listagem(int *v, int n) {
    for (int *i = v, j = 1; i < v + n; i++, j++) {
        cout << j << "º valor " << *i << endl;
    }
}

//ordena por bubblesort

void bubblesort(int *v, int n) {
    for (int* p = v + n - 1; p > v; p--) {
        for (int* q = v; q < p; q++) {
            if (*q > *(q + 1)) {
                int temp = *q;
                *q = *(q + 1);
                *(q + 1) = temp;
            }
        }
    }
}
//-------------------------------------------------------------------//

//ordena por selectionsort

void selectionsort(int *v, int n) {
    for (int *i = v; i < v + n - 1; i++) {
        int *menor = i;

        // Encontra o menor elemento do vetor
        for (int *j = i + 1; j < v + n; j++) {
            if (*j < *menor) {
                menor = j;
            }
        }

        // Troca os elementos
        int temp = *i;
        *i = *menor;
        *menor = temp;
    }
}
//-------------------------------------------------------------
//função que ordena por insertionsort

void insertionSort(int *v, int n) {
    int *i, q, *j;
    for (i = v + 1; i < v + n; i++) {
        q = *i;
        j = i;

        while (j > v && *(j - 1) > q) {
            *j = *(j - 1);
            j--;
        }
        *j = q;
    }
}




#endif