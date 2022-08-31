//Universidad del Valle de Guatemala
//Programacion de Microprocesadores
//Seccion 21
//Catedratico Roger Diaz
//Segundo Semestre 2022
//Jose Daniel Gomez Cabrera 21429
//Actividad: Laboratorio 3 Parte 2

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <iostream>
using namespace std;

//VARIABLES


//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
//SUB-RUTINE
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------

void *my_Subrutine(){
    cout << "Hello World!" << endl;
}

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
//MAIN PROGRAM
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------

void welcome();
void closing();
void request();
void n_calculation();

int main(){
    welcome();

    return 0;
}


//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
//FUNCTIONS SECTION
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------

void welcome(){
    cout << "\n---------------------------------------------------------" <<endl;
    cout << "Bienvenido a la parte 2 del Lab 3!" <<endl;
    cout << "- Jose Daniel Gomez Cabrera 21429 -" <<endl;
    cout << "---------------------------------------------------------"<<endl;
    cout << "Este es un programa de sumatoria de una formula!"<<endl;
}

void closing(){
    cout << "\n---------------------------------------------------------"<<endl;
    cout << "- Muchas gracias por utilizar contador de primos!" << endl;
    cout << "- Vuelve Pronto!" << endl;
    cout << "---------------------------------------------------------"<<endl;
    cout << endl;
}

void request(){
    cout << "---------------------------------------------------------"<<endl;
    cout << "Ingrese el valor maximo >> ";
    cin >> max_calculation;
    cout << endl;
    cout << "Ingrese numero de threads >> ";
    cin >> pt_amount;
    cout << "---------------------------------------------------------"<<endl;
}

void n_calculation(){
    int distribution = (max_calculation/pt_amount);
    cout << "Residuo: " << distribution << endl;
    pt_ranges = new int[pt_amount];
    if((max_calculation%pt_amount)==0){
        for(int i = 0; i<pt_amount; i++){
            pt_ranges[i] = distribution;
        }
    }
    else{
        for(int i = 0; i<pt_amount; i++){
            if(i==(pt_amount-1)){
                pt_ranges[i] = (distribution+(max_calculation%pt_amount));
            }
            else{
                pt_ranges[i] = distribution;
            }
        }
    }
}
