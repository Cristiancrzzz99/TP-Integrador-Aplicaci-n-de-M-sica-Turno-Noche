#include <iostream>
#include <cstring>
using namespace std;

#include "Interprete.h"
#include "ArchivoInterprete.h"

ArchivoInterprete::ArchivoInterprete(const char *n){
    strcpy(nombre, n);
    tamanioRegistro = sizeof(Interprete);
}

int ArchivoInterprete::agregarRegistro(Interprete reg){
    FILE *p = fopen(nombre, "ab");
    if(p == nullptr) return -1;

    int escribio = fwrite(&reg, tamanioRegistro, 1, p);
    fclose(p);
    return escribio;
}

bool ArchivoInterprete::listarRegistros(){
    Interprete obj;
    FILE *p = fopen(nombre, "rb");
    if(p == nullptr) return false;

    while(fread(&obj, tamanioRegistro, 1, p) == 1){
        if(obj.getEliminado() == true){
            obj.Mostrar();
            cout << endl;
        }
    }
    fclose(p);
    return true;
}

int ArchivoInterprete::buscarRegistro(int idInterprete){
    Interprete obj;
    FILE *p = fopen(nombre, "rb");
    if(p == nullptr) return -1;

    int cant = contarRegistros();
    for(int i=0; i<cant; i++){
        fread(&obj, tamanioRegistro, 1, p);
        if(obj.getEliminado() && obj.getIdInterprete() == idInterprete){
            fclose(p);
            return i;
        }
    }

    fclose(p);
    return -2;
}

Interprete ArchivoInterprete::leerRegistro(int pos){
    Interprete obj;
    FILE *p = fopen(nombre, "rb");
    if(p == nullptr) return obj;

    fseek(p, pos * tamanioRegistro, SEEK_SET);
    fread(&obj, tamanioRegistro, 1, p);
    fclose(p);
    return obj;
}

bool ArchivoInterprete::modificarRegistro(Interprete reg, int pos){
    FILE *p = fopen(nombre, "rb+");
    if(p == nullptr) return false;

    fseek(p, pos * tamanioRegistro, SEEK_SET);
    bool ok = fwrite(&reg, tamanioRegistro, 1, p);
    fclose(p);
    return ok;
}

int ArchivoInterprete::contarRegistros(){
    FILE *p = fopen(nombre, "rb");
    if(p == nullptr) return 0;

    fseek(p, 0, SEEK_END);
    int cant = ftell(p) / tamanioRegistro;
    fclose(p);
    return cant;
}

bool ArchivoInterprete::bajaLogica(int pos){
    Interprete reg = leerRegistro(pos);
    reg.seteliminado(false);
    return modificarRegistro(reg, pos);
}

bool ArchivoInterprete::activarRegistro(int pos){
    Interprete reg = leerRegistro(pos);
    reg.seteliminado(true);
    return modificarRegistro(reg, pos);
}
