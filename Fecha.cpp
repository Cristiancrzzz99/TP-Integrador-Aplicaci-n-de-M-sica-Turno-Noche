#include <iostream>

using namespace std;

#include "Fecha.h"

Fecha::Fecha(int d, int m, int a){
    dia=d;
    mes=m;
    anio=a;
 }

void Fecha::Cargar(){
        do{cout<<"DIA ";
        cin>>dia;
        if(dia<1||dia>31){
        cout<<"DIA NO VALIDO VUELVA A INTENTAR"<<endl;
        }
        }while(dia<1||dia>31);
       do{ cout<<"MES ";
        cin>>mes;
        if(mes<1||mes>12){
        cout<<"MES NO VALIDO VUELVA A INTENTAR"<<endl;
        }

    }while(mes<1||mes>12);
    do{
    cout<<"ANIO ";
    cin>>anio;

    if(anio <= 0){
        cout<<"ANIO NO VALIDO"<<endl;
    }

}while(anio <= 0);}
 void Fecha::Mostrar(){
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
    }

int Fecha::getDia(){return dia;}
int Fecha::getMes(){return mes;}
int Fecha::getAnio(){return anio;}

void Fecha::setDia(int a){dia=a;}
void Fecha:: setMes(int a){mes=a;}
void Fecha:: setAnio(int a){anio=a;}
