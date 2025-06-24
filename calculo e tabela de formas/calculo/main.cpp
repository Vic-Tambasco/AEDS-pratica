
/* 
 * File:   main.cpp
 * Author: Victoria Tambasco
 *
 * Created on April 20, 2025, 7:03 PM
 * 
 * Esse código tem o intuito de pegar os valores correspondentes a cada forma geometrica dada no arquivo de texto cenagrafica.txt e calcular a area total e o volume total deles
 */

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

string figura;
float areacubo, lado, lado2, lado3, volumecubo, pi, raio, areaquadrado, areacirculo, areacilindro, volumecilindro,altura,areatotal,volumetotal, areatrianguloequilatero, x, areaesfera, volumeesfera,areaparalelepipedo,volumeparalelepipedo, areatrapezio,apotema,areahexagono, raiz2, areaoctogono;
ifstream arquivo("cenagrafica.txt");

x = 0.433012;//raiz 3/4
pi = 3.1415;
areatotal = 0;
volumetotal = 0;
lado = 0;
raio = 0;
altura = 0;
apotema = 2,598076;
raiz2 = 1,41421;

if(!arquivo.is_open()){
    cout << "esse arquivo nao pode ser aberto" << endl;
    return 1;
}
//pega os valores do arquivo de texto e os usa nas formulas que são somadas e mostradas ao final//
while(arquivo >> figura){
 if(figura == "fim"){
    cout << "hora de calcular a area e o volume total" << endl;
 }else{
if(figura == "cubo"){
    arquivo >> lado;
    areacubo = 6*lado*lado;
    volumecubo = lado*lado*lado;
    cout << "area do cubo: " << areacubo << " volume do cubo: " << volumecubo << endl;
    areatotal = areatotal + areacubo;
    volumetotal = volumetotal + volumecubo;
}else{
    if(figura == "quadrado"){
        arquivo >> lado;
        areaquadrado = lado*lado;
        cout << "area do quadrado: " << areaquadrado << endl;
        areatotal = areatotal + areaquadrado;
    }else{
        if(figura == "circulo"){
            arquivo >> raio;
            areacirculo = pi*raio*raio;
            cout << "area do circulo: " << areacirculo << endl;
            areatotal = areatotal + areacirculo;
        }else{
            if(figura == "cilindro"){
                arquivo >> raio >> altura;
                areacilindro = 2*pi*raio*(altura + raio);
                volumecilindro = pi*raio*raio*altura;
                cout << "area do cilindro: " << areacilindro << " volume do cilindro: " << volumecilindro << endl;
                areatotal = areatotal + areacilindro;
                volumetotal = volumetotal + volumecilindro;
            }else{
                if(figura == "triangulo_equilatero" && lado == lado2){
                    arquivo >> lado, lado2;
                    
                    areatrianguloequilatero = x*lado*lado;
                    cout << "area do triangulo equilatero: " << areatrianguloequilatero << endl;
                    areatotal = areatotal + areatrianguloequilatero; 
                }else{
                    if(figura == "esfera"){
                        arquivo >> raio;
                        areaesfera = 4*pi*raio*raio;
                        volumeesfera = (4/3)*pi*raio*raio*raio;
                        cout << "area da esfera: " << areaesfera <<"  volume da esfera: " << volumeesfera << endl;
                        areatotal = areatotal + areaesfera;
                        volumetotal = volumetotal + volumeesfera;
                    }else{
                        if(figura == "paralelepipedo"){
                            arquivo >> lado >> lado2 >> lado3;
                            areaparalelepipedo = 2*(lado*lado2 + lado2*lado3 + lado*lado3);
                            volumeparalelepipedo = lado*lado2*lado3;
                            cout << "area do paralelepipedo: " << areaparalelepipedo << " volume do paralelepipedo: " << volumeparalelepipedo << endl;
                            areatotal = areatotal + areaparalelepipedo;
                            volumetotal = volumetotal + volumeparalelepipedo;
                        }else{
                            if(figura == "trapezio"){
                                arquivo >> lado >> lado2 >> altura;
                                areatrapezio = ((lado + lado2) * altura)/2;
                                cout << "area do trapezio: " << areatrapezio << endl;
                                areatotal = areatotal + areatrapezio;
                            }else{
                                if(figura == "hexagono_regular"){
                                    arquivo >> lado;
                                    areahexagono = apotema*lado*lado;
                                    cout << "area do hexagono regular: " << areahexagono << endl;
                                    areatotal = areatotal + areahexagono;
                                }else{
                                    if(figura == "octogono_regular"){
                                        arquivo >> lado;
                                        areaoctogono = 2*lado*lado*(1 + raiz2);
                                        cout << "area do octogono regular: " << areaoctogono << endl;
                                        areatotal = areatotal + areaoctogono;
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




cout << "a soma das areas é: " << areatotal << endl;
cout << "a soma dos volumes é: " << volumetotal << endl;






arquivo.close();

    return 0;
}

