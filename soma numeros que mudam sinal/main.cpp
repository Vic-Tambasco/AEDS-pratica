/* 
 * File:   main.cpp
 * Author: 2025.1.08.030
 *
 * Created on 25 de abril de 2025, 08:08
 */

#include <cstdlib>
#include <iostream>
#include<fstream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    /*int numero, i, par, impar, soma;
    
    i = 1;
    soma = 0;
    cout << "escolha um numero que se deseja para fazer esse calculo: " << endl;
   cin >> numero;
    
    
    
    while(numero >= i){
        par = i;
        impar = i * (-1);
        
        if(i % 2 != 0 ){
        cout << impar;
        soma = soma + impar;
        }else{
            if(i % 2 == 0){    
            cout << "+" << par;
        soma = soma + par;    
        }
                }
        i = i + 1;
            }*/
   
    int sinal, numero, i,soma,numesin;
    soma = 0;
    numesin = 0;
    i = 1;
    sinal = (-1);
    cout << "escolha um numero que se deseja para fazer esse calculo: " << endl;
    cin >> numero;
    
    while( numero >= i){
        numesin = sinal * i;
        cout << numesin << " ";
        i = i + 1;
        sinal = sinal * (-1); 
        soma = soma + numesin;
    }
        
   cout << endl;     
   cout << "o valor dessa operaçao sera: " << soma << endl; 
    
     
    return 0;

}

