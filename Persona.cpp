#include <iostream>
#include <cstring>
#include "Persona.h"

using namespace std;

Persona::Persona(const char* nom, const char* ape,
                 const char* dni, const char* tel,
                 const char* email, bool elim){
    strcpy(Nombre, nom);
    strcpy(Apellido, ape);
    strcpy(Dni, dni);
    strcpy(Telefono, tel);
    strcpy(Email, email);
    Eliminado = elim;
}

void Persona::Cargar(){
    cout<<"Nombre: ";
    cin>> Nombre;
    cout<<"Apellido: ";
    cin>>Apellido;
    cout<<"DNI: ";
    cin>>Dni;
    cout<<"Telefono: ";
    cin>>Telefono;
    cout<<"Email: ";
    cin>>Email;

    Eliminado = false;
}

void Persona::Mostrar(){
    cout<<"Nombre: " << Nombre << endl;
    cout<<"Apellido: " << Apellido << endl;
    cout<<"DNI: " << Dni << endl;
    cout<<"Telefono: " << Telefono << endl;
    cout<<"Email: " << Email << endl;
    cout<<"Eliminado: " << (Eliminado ? "SI" : "NO") << endl;
}


const char* Persona::getNombre(){ return Nombre; }
const char* Persona::getApellido(){ return Apellido; }
const char* Persona::getDni(){ return Dni; }
const char* Persona::getTelefono(){ return Telefono; }
const char* Persona::getEmail(){ return Email; }
bool Persona::getEliminado(){ return Eliminado; }


void Persona::setNombre(const char* n){ strcpy(Nombre, n); }
void Persona::setApellido(const char* a){ strcpy(Apellido, a); }
void Persona::setDni(const char* d){ strcpy(Dni, d); }
void Persona::setTelefono(const char* t){ strcpy(Telefono, t); }
void Persona::setEmail(const char* e){ strcpy(Email, e); }
void Persona::setEliminado(bool e){ Eliminado = e; }
