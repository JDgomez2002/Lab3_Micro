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
#include <math.h>
using namespace std;

//VARIABLES
int n;
double sum = 0;

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
//SUB-RUTINE
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------

void *summation(void *thread_number){
    long number = (long)thread_number;
    double* result = new double;
    *result = 3/(pow(2,number));
    return result;
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
void show_result();

int main(){
    welcome();
    request();

    int rc;
    long i;
    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    void *ptr_sum;

    for(int i = 0; i<=n ;i++){
        rc = pthread_create(&tid, &attr, summation, (void *)i);
        rc = pthread_join(tid, &ptr_sum);
        sum += (*(double*) ptr_sum);
    }

    show_result();
    closing();
    pthread_exit(NULL);
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
    cout << "---------------------------------------------------------"<<endl;
    cout << "- Muchas gracias por utilizar la sumatoria!" << endl;
    cout << "- Vuelve Pronto!" << endl;
    cout << "---------------------------------------------------------"<<endl;
    cout << endl;
}

void request(){
    cout << "---------------------------------------------------------"<<endl;
    cout << "Ingrese el valor de n >> ";
    cin >> n;
    cout << endl;
    cout << "Valor de n: " << n << endl;
}

void show_result(){
    cout << "---------------------------------------------------------"<<endl;
    cout << endl;
    cout << "El TOTAL de la SUMATORIA es de: " << sum << endl;
    cout << endl;
}