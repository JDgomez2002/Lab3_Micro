//Universidad del Valle de Guatemala
//Programacion de Microprocesadores
//Seccion 21
//Catedratico Roger Diaz
//Segundo Semestre 2022
//Jose Daniel Gomez Cabrera 21429
//Actividad: Laboratorio 03 Parte 1

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <iostream>
using namespace std;

//VARIABLES
int max_calculation, pt_amount, n, *pt_ranges;
int total;

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
//SUB-RUTINE
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------

void *calculation(void *thread_number){
    long begining, end, k;
    long tID = (long)thread_number;
    int total_pt = 0;
    if(tID==(pt_amount-1)){
        begining = (((tID-1)*(pt_ranges[tID-1]))+pt_ranges[tID-1]);
        end = (begining+pt_ranges[tID]);
    }
    else{
        begining = (tID*(pt_ranges[tID]));
        end = (begining+pt_ranges[tID]);
    }

    if(tID==(pt_amount-1)){
        cout << "- Thread " << tID << ": from " << begining << " to " << end << " (Incluyendolo: Final)" << endl;
        end++; //Porque queremos incluir el numero final, por ejemplo 0->83, el 83 se inlcuye porque es primo.
    }
    else{
        cout << "- Thread " << tID << ": from " << begining << " to " << end << " (Sin incluirlo)" << endl;
    }

    cout << "Primos: ";
    for(k = begining; k<end ;k++){
        //4,5,6,etc...,k
        if(k>3){
            bool prime = true;
            int counter = 2;
            while((prime)&&(counter<k)){
                if((k%counter)==0){
                    prime = false;
                }
                counter++;
            }
            if(prime){
                if(k==(end-1)){
                    cout << k;
                }
                else{
                    cout << k << ", ";
                }
                total_pt += k;
            }
        }
        //2,3
        else if(((k>1)&&(k<4))){
            if(k==(end-1)){
                    cout << k;
            }
            else{
                cout << k << ", ";
            }
            total_pt += k;
        }
    }
    cout << "\nTOTAL hilo: " << total_pt << "\n" << endl;
    total += total_pt;
    pthread_exit(NULL);
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
    request();
    n_calculation();

    cout << "Reparticion de los '" << pt_amount << "' Threads hasta "<< max_calculation << ": [ ";

    for(int i = 0; i<pt_amount; i++){
        cout << pt_ranges[i] << " ";
    }
    cout << "]\n---------------------------------------------------------\n"<<endl;

    int rc;
    long i;
    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for(i = 0; i<pt_amount; i++){
        rc = pthread_create(&tid, &attr, calculation, (void *)i);
        rc = pthread_join(tid, NULL);
    }
    
    cout << "---------------------------------------------------------"<<endl;
    cout << "\nLa SUMATORIA DE PRIMOS es: " << total << endl;
 
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
    cout << "Bienvenido a la parte 1 del Lab 3!" <<endl;
    cout << "- Jose Daniel Gomez Cabrera 21429 -" <<endl;
    cout << "---------------------------------------------------------"<<endl;
    cout << "Este es un programa de sumatoria de numeros primos!"<<endl;
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
