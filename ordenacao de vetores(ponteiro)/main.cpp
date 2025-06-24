/* 
 * File:   main.cpp
 * Author: Victoria Tambasco
 * 
 *
 * Created on June 16, 2025, 8:39 PM
 */

#include <cstdlib>
#include <iostream>
#include "ORDENACAO.h"

using namespace std;

/*Esse codigo tem como objetivo ordenar vetores usando 3 tipos de ordenaçao, a bubblesort, selectionsort e a insertionsort,
 * esses vetores estão definidos por 3 tipos de caso, o melhor caso para se ordenar um vetor(vetor crescente), o pior caso 
 * para se ordenar um vetor(vetor decrescente), e o caso mais comum (vetor aleatorio).
 * Foi criado um arquivo (ORDENACAO.h), apenas para guardar as funcoes que serao chamadas no arquivo atual (main.cpp).
 * 
 */
int main(int argc, char** argv) {
    const int TAM = 10;
    int vCresc[TAM], vDecre[TAM], vAleat[TAM];

    //ordenação usando bubblesort

    vetores(vCresc, vDecre, vAleat, TAM);
    cout << "--------Ordenacao bubblesort--------" << endl;

    //ordenação do vetor aleatoriamente desordenado
    cout << endl << "Estado do vetor antes da ordenacao" << endl;
    listagem(vAleat, TAM);
    cout << endl;
    bubblesort(vAleat, TAM); //puxa a função de ordenacao
    cout << "Estado aleatorio depois da ordenacao:" << endl;
    listagem(vAleat, TAM);

    //ordenaçao do vetor desordenado de maneira crescente
    cout << endl << "\nEstado do vetor antes da ordenacao" << endl;
    listagem(vCresc, TAM);
    cout << endl;
    bubblesort(vCresc, TAM); //puxa a função de ordenacao
    cout << endl << "Estado crescente depois da ordenacao:" << endl;
    listagem(vCresc, TAM);

    //ordenaçao do vetor desordenado de maneira decrescente
    cout << endl << "\nEstado do vetor antes da ordenacao" << endl;
    listagem(vDecre, TAM);
    cout << endl;
    bubblesort(vDecre, TAM); //puxa a função de ordenacao
    cout << endl << "Estado decrescente depois da ordenacao:" << endl;
    listagem(vDecre, TAM);

    cout << "\n===========================================================================\n" << endl;

    //ordenação usando selectionsort
    cout << "--------Ordenacao selectionsort--------" << endl;
    vetores(vCresc, vDecre, vAleat, TAM);
    //ordenaçao do vetor desordenado de maneira crescente
    cout << endl << "Estado do vetor antes da ordenacao" << endl;
    listagem(vCresc, TAM);
    cout << endl;
    selectionsort(vCresc, TAM);
    cout << endl << "Estado crescente depois da ordenacao:" << endl;
    listagem(vCresc, TAM);

    //ordenação do vetor aleatoriamente desordenado
    cout << endl << "Estado do vetor antes da ordenacao" << endl;
    listagem(vAleat, TAM);
    cout << endl;
    selectionsort(vAleat, TAM);
    cout << endl << "Estado aleatorio depois da ordenacao:" << endl;
    listagem(vAleat, TAM);

    //ordenaçao do vetor desordenado de maneira decrescente
    cout << endl << "Estado do vetor antes da ordenacao" << endl;
    listagem(vDecre, TAM);
    cout << endl;
    selectionsort(vDecre, TAM);
    cout << endl << "Estado decrescente depois da ordenacao:" << endl;
    listagem(vDecre, TAM);

    cout << "\n===========================================================================\n" << endl;

    //ordenação usando insertionsort
    cout << "--------Ordenacao insertionsort--------" << endl;

    vetores(vCresc, vDecre, vAleat, TAM);

    //ordenaçao do vetor desordenado de maneira crescente
    cout << endl << "Estado do vetor antes da ordenacao" << endl;
    listagem(vCresc, TAM);
    cout << endl;
    insertionSort(vCresc, TAM);
    cout << endl << "Estado crescente depois da ordenacao:" << endl;
    listagem(vCresc, TAM);

    //ordenação do vetor aleatoriamente desordenado
    cout << endl << "Estado do vetor antes da ordenacao" << endl;
    listagem(vAleat, TAM);
    cout << endl;
    insertionSort(vAleat, TAM);
    cout << endl << "Estado aleatorio depois da ordenacao:" << endl;
    listagem(vAleat, TAM);

    //ordenaçao do vetor desordenado de maneira decrescente
    cout << endl << "Estado do vetor antes da ordenacao" << endl;
    listagem(vDecre, TAM);
    cout << endl;
    insertionSort(vDecre, TAM);
    cout << endl << "Estado decrescente depois da ordenacao:" << endl;
    listagem(vDecre, TAM);


    return 0;
}

