#ifndef CANCION_H_INCLUDED
#define CANCION_H_INCLUDED

#include<cstdlib>
#include<cstring>
#include <iostream>

#include "Fecha.h"
using namespace std;

class Cancion{

private:
    int IdCancion;
    char Nombre[20];
    int IdInterprete;
   int IdGenero;
   Fecha FechaPublicacion;
   bool Eliminado;

public:
    void Cargar();
    void Mostrar();

    int getIdCancion(){return IdCancion;}
    const char* getNombre(){return Nombre;}
    int getIdInterprete(){return IdInterprete;}
    Fecha getFechaPublicacion() {return FechaPublicacion;}
    int getIdGenero(){return IdGenero;}
    bool getEliminado(){return Eliminado;}


    void setIdCancion(int id){IdCancion=id;}
    void setNombre(const char* n){strcpy(Nombre,n);}
    void setInterprete(int id){IdInterprete=id;}
    void setIdGenero(int id){IdGenero=id;}
    void setFechaPublicacion(Fecha f){FechaPublicacion=f;}
    void setEliminado(bool e){Eliminado=e;}


};


#endif // CANCION_H_INCLUDED
