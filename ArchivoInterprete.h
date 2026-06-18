#ifndef ARCHIVOINTERPRETE_H_INCLUDED
#define ARCHIVOINTERPRETE_H_INCLUDED
#include "interprete.h"
class ArchivoInterprete{
private:
    char nombre[30];
    int tamanioRegistro;

public:
    ArchivoInterprete(const char *n = "Interpretes.dat");

    int agregarRegistro(Interprete reg);
    bool listarRegistros();
    int buscarRegistro(int idInterprete);
    Interprete leerRegistro(int pos);
    bool modificarRegistro(Interprete reg, int pos);
    int contarRegistros();
    bool bajaLogica(int pos);
    bool activarRegistro(int pos);
};

#endif // ARCHIVOINTERPRETE_H_INCLUDED
