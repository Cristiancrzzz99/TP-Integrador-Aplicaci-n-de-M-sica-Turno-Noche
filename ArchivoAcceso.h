#ifndef ARCHIVOACCESO_H_INCLUDED
#define ARCHIVOACCESO_H_INCLUDED

#include "acceso.h"

class ArchivoAcceso{
private:
    char nombre[30];
    int tamanioRegistro;

public:
    ArchivoAcceso(const char *n = "Accesos.dat");

    int agregarRegistro(Acceso reg);
    bool listarRegistros();
    int buscarRegistro(int IdAcceso);
    Acceso leerRegistro(int pos);
    bool modificarRegistro(Acceso reg, int pos);
    int contarRegistros();
    bool bajaLogica(int pos);
    bool activarRegistro(int pos);
};

#endif // ARCHIVOACCESO_H_INCLUDED
