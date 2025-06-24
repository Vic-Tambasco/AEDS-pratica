/* 
 * File:   main.cpp
 * Author: Victoria ã
 *
 * Created on May 20, 2025, 5:42 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <stdio.h>

using namespace std;

/*esse codigo tem como objetivo trabalhar com a modificacao e localizacao dentro de 
 * um vetor por meio de opcoes em uma tabela em que o usuario escolha a que deseja,
 * podendo tambem realizar as opcoes diversas vezes em um mesmo vetor.
 * 
 */
int main(int argc, char** argv) {
    const int TAM = 20;
    int vetor[TAM], dif, lmax, lmin, i, j, escolha = -1, valor, posicao, tam, k;
    tam = TAM;

    // Gera os valores inteiros
    srand(time(NULL));
    cout << "Defina os limites maximos e minimos para os numeros que compoem o vetor: " << endl;
    cin >> lmax >> lmin;

    cout << "Os valores gerados sao: ";
    for (i = 0; i < TAM; i++) {
        dif = lmax - lmin;
        vetor[i] = lmin + rand() % dif;
        cout << vetor[i] << " ";
    }

    // faz o programa funcionar ate que o 0 seja escolhido
    while (escolha != 0) {
        // Tabela de opções
        cout << "  ====== Menu de operacoes =======" << endl;
        cout << "1 - Quantidade de vezes que um valor aparece" << endl;
        cout << "2 - Contar a quantidade de valores em um intervalo" << endl;
        cout << "3 - Buscar pela primeira ocorrencia de um valor e sua posicao" << endl;
        cout << "4 - Exclui a primeira aparicao de um valor definido" << endl;
        cout << "5 - Inserir um valor desejado em uma posicao escolhida nao ocupada" << endl;
        cout << "6 - Retirar valores repetidos" << endl;
        cout << "0 - Sair" << endl;

        cout << "\nEscolha qual operacao voce quer realizar: ";
        cin >> escolha;
       
        
        switch (escolha) {
            case 1:
                //essa opcao mostra quantas vezes o valor escolhido se repetiu
                cout << "Escolha um dos valores para ver quantas vezes ele se repete: ";
                cin >> valor;
                // o j conta quantas vezes o numero escolhido apareceu
                j = 0;
                for (i = 0; i < tam; i++) {
                    if (valor == vetor[i]) {
                        j++;
                    }
                }
                if (j > 0) {
                    cout << "O valor " << valor << " aparece " << j << " vezes" << endl;
                } else {
                    //caso o valor digitado nao esteja presente no vetor 
                    cout << "Esse valor nao esta presente no vetor" << endl;
                }
                break;

            case 2:
                // o usuario define um intervalo, e todos os valores do vetor 
                //que estao nessa faixa sao exibidos alem de mostrar o total de valores desse intervalo
                cout << "Escolha o limite inferior e superior da faixa de valores: ";
                cin >> lmin >> lmax;
                j = 0;
                cout << "Os valores entre " << lmin << " e " << lmax << " sao: ";
                for (i = 0; i < tam; i++) {
                    if (vetor[i] >= lmin && vetor[i] <= lmax) {
                        cout << vetor[i] << " ";
                        j++;
                    }
                }
                cout << " " << endl;
                cout << "Total: " << j << " valores" << endl;
                break;

            case 3:
                //busca pela primeira aparicao de um valor determinado pelo usuario
                cout << "Escolha um valor para ver a primeira ocorrencia: ";
                cin >> valor;
                posicao = -1;
                for (i = 0; i < tam && posicao == -1; i++) {
                    if (vetor[i] == valor) {
                        posicao = i;
                    }
                }
                if (posicao != -1) {
                    cout << "O valor " << valor << " aparece pela primeira vez na posicao " << posicao << endl;
                } else {
                    // se digitado um valor nao presente resulta nessa mensagem
                    cout << "Valor nao encontrado no vetor" << endl;
                }
                break;

            case 4:
                //exclui a primeira ocorrencia de um numero decidido pelo usuario
                cout << "Escolha um valor para excluir sua primeira ocorrencia: ";
                cin >> valor;
                posicao = -1;
                for (i = 0; i < tam && posicao == -1; i++) {
                    if (vetor[i] == valor) {
                        posicao = i;
                    }
                }
                if (posicao != -1) {
                    for (i = posicao; i < tam - 1; i++) {
                        vetor[i] = vetor[i + 1];
                    }
                    tam--;
                    cout << "Vetor apos remocao: ";
                    for (i = 0; i < tam; i++) {
                        cout << vetor[i] << " ";
                    }
                } else {
                    // se digitado um valor nao presente resulta nessa mensagem
                    cout << "Valor nao encontrado no vetor" << endl;
                }
                break;

            case 5:
                //insere um valor escolhido numa posicao determinada pelo usuario se a mesma estiver livre
                cout << "Digite o valor a ser inserido: ";
                cin >> valor;
                //exibe a faixa de posicoes que há no vetor
                cout << "Digite a posicao (0-" << tam << "): ";
                cin >> posicao;

                if (posicao < 0 || posicao > tam) {
                    cout << "Posicao invalida" << endl;
                } else if (tam >= TAM) {
                    cout << "Vetor cheio, nao e possivel inserir mais elementos." << endl;
                } else {
                    // Deslocar elementos para direita se não for a última posição
                    if (posicao < tam) {
                        for (i = tam; i > posicao; i--) {
                            vetor[i] = vetor[i - 1];
                        }
                    }
                    vetor[posicao] = valor;
                    tam++;
                    cout << "Valor inserido com sucesso" << endl;
                }
                break;

            case 6:
                //apaga os valores repetidos dentro do vetor
                for (i = 0; i < tam; i++) {
                    for (j = i + 1; j < tam;) {
                        if (vetor[j] == vetor[i]) {
                            for (k = j; k < tam - 1; k++) {
                                vetor[k] = vetor[k + 1];
                            }// o k nesse momento e usado como um contador que move os elementos do vetor para a esquerda para 
                            //sobrescrever o valor duplicado.
                            
                            //diminui o tamanho do vetor para cada valor excluido
                            tam--;
                        } else {
                            j++;
                        }
                    }
                }
                cout << "Vetor sem duplicados: ";
                for (i = 0; i < tam; i++) {
                    cout << vetor[i] << " ";
                }
                cout << endl;
                break;

            case 0:
                //faz a repeticao do programa acabar
                cout << "Saindo do programa..." << endl;
                break;
        }

        // mostra o vetor atual apos cada operacao (exceto quando sai)
        if (escolha != 0) {
            cout << "Vetor atual (" << tam << " elementos): ";
            for (i = 0; i < tam; i++) {
                cout << vetor[i] << " ";
            }
            cout << endl;
        }
    }
        // mensagem para opcao invalida
        if(escolha < 0 || escolha > 6) {
            cout << "Opcao invalida, tente novamente." << endl;
        }
    return 0;
}



