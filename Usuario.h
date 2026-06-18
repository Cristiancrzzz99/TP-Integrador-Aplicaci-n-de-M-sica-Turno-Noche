#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

#include<cstdlib>
#include<cstring>
#include <iostream>

#include "persona.h"

using namespace std;

class Usuario{
private:
     int IdUsuario;
    char Clave[20];
    Persona persona;
    bool Eliminado;
public:
    void Cargar();
    void Mostrar();

    int getIdUsuario(){return IdUsuario;}
    const char* getClave(){return Clave;}
    Persona getPersona(){return persona;}
    bool getEliminado(){return Eliminado;}


    void setIdUsuario(int id){IdUsuario=id;}
    void setClave(const char* c){strcpy(Clave,c);}
    void setPersona(Persona p){persona=p;}
    void setEliminado(bool e){Eliminado=e;}

};


#endif
