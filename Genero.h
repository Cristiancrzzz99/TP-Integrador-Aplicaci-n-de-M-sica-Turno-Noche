#ifndef GENERO_H_INCLUDED
#define GENERO_H_INCLUDED
#include<cstdlib>
#include<cstring>
#include <iostream>
using namespace std;

class Genero{
private:
     int IdGenero;
     char Nombre [20];
     bool Eliminado ;

public:
    void Cargar();
    void Mostrar();

    int getIdGenero(){return IdGenero;}
    const char* getNombre(){return Nombre;}
    bool getEliminado(){return Eliminado;}


    void setIdGenero(int id){IdGenero=id;}
    void setNombre(const char* n){strcpy(Nombre,n);}
    void seteliminado(bool e){Eliminado=e;}

};


#endif
