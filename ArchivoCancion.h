#ifndef ARCHIVOCANCION_H_INCLUDED
#define ARCHIVOCANCION_H_INCLUDED
#include "cancion.h"

class ArchivoCancion{
private:
    char nombre[30];
    int tamanioRegistro;

public:
    ArchivoCancion(const char *n = "Canciones.dat");

    int agregarRegistro(Cancion reg);
    bool listarRegistros();
    int buscarRegistro(int IdCancion);
    Cancion leerRegistro(int pos);
    bool modificarRegistro(Cancion reg, int pos);
    int contarRegistros();
    bool bajaLogica(int pos);
    bool activarRegistro(int pos);
    Cancion leerRegistroPorId(int id);



};
#endif
