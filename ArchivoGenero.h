#ifndef ARCHIVOGENERO_H_INCLUDED
#define ARCHIVOGENERO_H_INCLUDED

#include "genero.h"

class ArchivoGenero{
private:
    char nombre[30];
    int tamanioRegistro;

public:
    ArchivoGenero(const char *n = "Generos.dat");

    int agregarRegistro(Genero reg);
    bool listarRegistros();
    int buscarRegistro(int IdGenero);
    Genero leerRegistro(int pos);
    bool modificarRegistro(Genero reg, int pos);
    int contarRegistros();
    bool bajaLogica(int pos);
    bool activarRegistro(int pos);
};

#endif // ARCHIVOGENERO_H_INCLUDED
