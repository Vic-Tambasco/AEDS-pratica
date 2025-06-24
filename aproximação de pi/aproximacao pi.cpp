/* 
 * File:   main.cpp
 * Author: 2025.1.08.030
 *
 * Created on 25 de abril de 2025, 08:54
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int expoente, dividendo, i, casas, contador;
    contador = 0;
    i = 0;
    
    cout << "escolha quantas casas de pi voce quer: " << endl;
    cin >> casas;

    while (i <= casas) {
        expoente = i + 3;
        dividendo = 1;
        
        if (contador % 2 == 0 && i % 2 == 0) {
            cout << dividendo << "/" << expoente;
            cout << " ";
            cout << i << endl;
        } else {
            if (contador % 2 != 0 && i % 2 == 0) {
                cout << (dividendo) * (-1) << "/" << expoente;
                cout << " ";
                cout << i << endl;
            }
        }
        contador = contador + 1;
        i = i + 1;
    }

    return 0;
}

