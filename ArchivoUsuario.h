#ifndef ARCHIVOUSUARIO_H_INCLUDED
#define ARCHIVOUSUARIO_H_INCLUDED

#include "Usuario.h"

class ArchivoUsuario{
private:
    char nombre[30];
    int tamanioRegistro;

public:
    ArchivoUsuario(const char *n = "Usuario.dat");

    int agregarRegistro(Usuario reg);
    bool listarRegistros();
    int buscarRegistro(int idUsuario);
    Usuario leerRegistro(int pos);
    bool modificarRegistro(Usuario reg, int pos);
    int contarRegistros();
    bool bajaLogica(int idUsuario);
    bool activarRegistro(int idUsuario);


};
#endif // ARCHIVOUSUARIO_H_INCLUDED
