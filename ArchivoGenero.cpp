#include <iostream>
#include <cstring>
using namespace std;

#include "Genero.h"
#include "ArchivoGenero.h"

ArchivoGenero::ArchivoGenero(const char *n){
    strcpy(nombre, n);
    tamanioRegistro = sizeof(Genero);
}

int ArchivoGenero::agregarRegistro(Genero reg){
    FILE *p = fopen(nombre, "ab");
    if(p == nullptr) return -1;

    int escribio = fwrite(&reg, tamanioRegistro, 1, p);
    fclose(p);
    return escribio;
}

bool ArchivoGenero::listarRegistros(){
    FILE *p = fopen(nombre, "rb");
    if(p == nullptr) return false;

    Genero obj;
    while(fread(&obj, tamanioRegistro, 1, p) == 1){
        if(obj.getEliminado()){
            obj.Mostrar();
            cout << endl;
        }
    }
    fclose(p);
    return true;
}

int ArchivoGenero::buscarRegistro(int IdGenero){
    FILE *p = fopen(nombre, "rb");
    if(p == nullptr) return -1;

    Genero obj;
    int cant = contarRegistros();

    for(int i = 0; i < cant; i++){
        fread(&obj, tamanioRegistro, 1, p);
        if(obj.getEliminado() && obj.getIdGenero() == IdGenero){
            fclose(p);
            return i;
        }
    }

    fclose(p);
    return -2;
}

Genero ArchivoGenero::leerRegistro(int pos){
    Genero obj;
    FILE *p = fopen(nombre, "rb");
    if(p == nullptr) return obj;

    fseek(p, pos * tamanioRegistro, SEEK_SET);
    fread(&obj, tamanioRegistro, 1, p);
    fclose(p);
    return obj;
}

bool ArchivoGenero::modificarRegistro(Genero reg, int pos){
    FILE *p = fopen(nombre, "rb+");
    if(p == nullptr) return false;

    fseek(p, pos * tamanioRegistro, SEEK_SET);
    bool ok = fwrite(&reg, tamanioRegistro, 1, p);
    fclose(p);
    return ok;
}

int ArchivoGenero::contarRegistros(){
    FILE *p = fopen(nombre, "rb");
    if(p == nullptr) return 0;

    fseek(p, 0, SEEK_END);
    int cant = ftell(p) / tamanioRegistro;
    fclose(p);
    return cant;
}

bool ArchivoGenero::bajaLogica(int pos){
    Genero reg = leerRegistro(pos);
    reg.seteliminado(false);
    return modificarRegistro(reg, pos);
}

bool ArchivoGenero::activarRegistro(int pos){
    Genero reg = leerRegistro(pos);
    reg.seteliminado(true);
    return modificarRegistro(reg, pos);
}
