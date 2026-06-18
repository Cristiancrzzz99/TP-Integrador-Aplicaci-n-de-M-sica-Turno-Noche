#ifndef ACCESO_H_INCLUDED
#define ACCESO_H_INCLUDED
#include<cstdlib>
#include<cstring>
#include <iostream>

#include "fecha.h"
#include <ctime>
using namespace std;

class Acceso{

private:
    int IdAcceso;
    int IdUsuario;
    int IdCancion;
    Fecha FechaAcceso;

    int Hora;
    int Minuto;
    int Segundo;

    bool Eliminado;

    public:
    void Cargar();
    void Mostrar();

    int getIdAcceso(){return IdAcceso;}
    int getIdUsuario(){return IdUsuario;}
    Fecha getFechaAcceso() {return FechaAcceso;}
    int getIdCancion(){return IdCancion;}
    bool getEliminado(){return Eliminado;}

    int getHora(){ return Hora; }
    int getMinuto(){ return Minuto; }
    int getSegundo(){ return Segundo; }


    void setIdAcceso(int id){IdAcceso=id;}
    void setIdUsuario(int id){IdUsuario=id;}
    void setIdCancion(int id){IdCancion=id;}
    void setFechaAcceso(Fecha f){FechaAcceso=f;}
    void setEliminado(bool e){Eliminado=e;}
};

#endif
