#ifndef INTERPRETE_H_INCLUDED
#define INTERPRETE_H_INCLUDED
#include<cstdlib>
#include<cstring>
#include <iostream>
using namespace std;

class Interprete{

private:
    int IdInterprete;
    char Nombre[30];
    bool Eliminado;
    public:
    void Cargar();
    void Mostrar();

    int getIdInterprete(){return IdInterprete;}
    const char* getNombre(){return Nombre;}
    bool getEliminado(){return Eliminado;}


    void setIdInterprete(int id){IdInterprete=id;}
    void setNombre(const char* n){strcpy(Nombre,n);}
    void seteliminado(bool e){Eliminado=e;}

};

#endif
