/*
 * File:   main.cpp
 * Author: Victoria Tambasco
 *
 * Created on April 18, 2025, 10:26 PM
 * 
 * Esse cóigo foi feito com o intuito de gerar valores aleatóios para realizar o calculo de areas e volumes de formas geometricas escolhidas de acordo com a tabela e colocar esses valores no arquivo de texto cenario.txt
 */

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <time.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int quantia, escolhas, i;
    float lado, lado2, lado3, raio, altura, linf/*limite inferior*/, lsup/*limite superior*/, diferenca;
    string figura;
    
    srand(time(NULL));
    i = 0;
    
    ofstream lugar ("cenario.txt");
    if(!lugar.is_open()){
        cout << "seu arquivo nao pode ser aberto" << endl;
        return 1;
    }
    
    //tabela de valores que correspondem a casa forma geometrica//
    cout << "==== tabela de formas geometricas ====" << endl;
    cout << "       1 - cubo " << endl;
    cout << "       2 - quadrado" << endl;
    cout << "       3 - circulo" << endl;
    cout << "       4 - cilindro" << endl;
    cout << "       5 - triangulo equilatero" << endl;
    cout << "       6 - esfera" << endl;
    cout << "       7 - paralelepipedo" << endl;
    cout << "       8 - trapezio" << endl;
    cout << "       9 - hexagono regular" << endl;
   cout <<  "       10- octogono regular" << endl;
   cout << " " << endl;
   
    cout << "quantos figuras voce quer gerar: " << endl;
    cin >> quantia;
   
    cout << "qual o limite superior e inferior: " << endl;
    cin >> lsup;
    cin >> linf;  
    
    
    
   while(i < quantia){
        cout << " " << endl;
        cout << "escolha a forma geometrica que voce quer calcular de 1 a 10, uma por vez:" << endl;
        cin >> escolhas;
        
       diferenca = lsup - linf;
     //impede que os numeros fora da tabela sejam aceitos, e quando digitados recomeça a escolha de figuras// 
    if(escolhas < 1 || escolhas > 10){
     cout << "o valor escolhido nao esta na tabela, tente novamente" << endl;  
     
    }else{   
        if(escolhas == 1){
           lado = linf + rand()*diferenca/RAND_MAX;
           lugar << "cubo" <<" "<< lado << endl;
           cout << "o valor do lado do seu cubo sera: " << lado << endl;
           i = i+1;
        }else{
            if(escolhas == 2){
                lado = linf + rand()*diferenca/RAND_MAX;
                lugar <<"quadrado" << " "<< lado << endl;
                cout << "o valor do lado do seu quadrado sera: " << lado << endl;
                i = i+1;
            }else{
                if(escolhas == 3){
                   raio = linf + rand()*diferenca/RAND_MAX;
                lugar << "circulo"<< " "<< raio << endl;
                cout << "o valor do raio do seu circulo sera: " << raio << endl;
                i = i+1;
                }else{
                    if(escolhas == 4){
                       raio = linf + rand()*diferenca/RAND_MAX;
                       altura = linf + rand()*diferenca/RAND_MAX;
                       lugar << "cilindro" << " " <<raio <<" "<< altura << endl;
                       cout << "o valor do raio e da altura do seu cilindro sera: " << raio <<" "<< altura << endl;
                       i = i+1;
                    }else{
                        if(escolhas == 5){
                           lado = linf + rand()*diferenca/RAND_MAX;
                           lugar << "triangulo_equilatero" << " " << lado << endl;
                           cout << "o valor do lado do seu triangulo equilatero sera: " << lado << endl;
                           i = i+1;
                        }else{
                            if(escolhas == 6){
                                raio = linf + rand()*diferenca/RAND_MAX;
                                lugar << "esfera" << " " << raio << endl;
                                cout << "o valor do raio da sua esfera sera: " << raio << endl;
                                i = i+1;
                            }else{
                                if(escolhas == 7){
                                    lado = linf + rand()*diferenca/RAND_MAX;
                                    lado2 = linf + rand()*diferenca/RAND_MAX;
                                    lado3 = linf + rand()*diferenca/RAND_MAX;
                                    lugar << "paralelepipedo" << " " <<lado <<" "<< lado2 <<" "<< lado3 <<" "<< endl;
                                    cout << "o valor dos lados do seu paralelepipedo sera: " << lado << " " << lado2 <<" "<< lado3 << endl;
                                    i = i+1;
                                }else{
                                    if(escolhas == 8){
                                        lado = linf + rand()*diferenca/RAND_MAX;
                                        lado2 = linf + rand()*diferenca/RAND_MAX;
                                        altura = linf + rand()*diferenca/RAND_MAX;
                                        lugar << "trapezio" << " " << lado <<" "<< lado2 <<" "<< altura << endl;
                                        cout << "o valor dos lados e da altura do seu trapezio sera: " << lado << " " << lado2 << " " <<  altura << endl;
                                        i = i+1;
                                    }else{
                                        if(escolhas == 9){
                                            lado = linf + rand()*diferenca/RAND_MAX;
                                            lugar << "hexagono_regular" << " "<< lado << endl;
                                            cout << "o valor do lado do seu hexagono regular sera: " << lado << endl;
                                            i = i+1;
                                        }else{
                                            if(escolhas == 10){
                                                lado = linf + rand()*diferenca/RAND_MAX;
                                                lugar << "octogono_regular" << " " <<lado << endl;
                                                cout << "o valor do lado do seu octogono regular sera: " << lado << endl;
                                                i = i+1;
                                        
                                        }           
                                    }   
                                           }
                                       }
                                   }
                               }
                           }
                       }
                   }
               }
    }  
       
 }       
    //escreve fim no final do arquivo de texto para que no outro projeto ele execute e tenha um lugar onde parar//   
    lugar << "fim" << endl;
   
    lugar.close();   
    
    cout << "os valores para calculas as figuras estao salvas no arquivo de texto" << endl;
    return 0;

}
