#include <iostream>
#include <cstring>

using namespace std;
#include "Fecha.h"
#include "Cancion.h"
#include "ArchivoCancion.h"

ArchivoCancion::ArchivoCancion(const char *n){
    strcpy(nombre, n);
    tamanioRegistro=sizeof(Cancion);
}
int ArchivoCancion::agregarRegistro(Cancion reg){
     FILE *p;
     p=fopen(nombre, "ab");
     if(p==nullptr){
        return -1;

     }
     int escribio=fwrite(&reg, tamanioRegistro,1,p);

    fclose(p);
    return escribio;
}
bool ArchivoCancion::listarRegistros(){
    Cancion obj;
    FILE *p = fopen(nombre, "rb");
    if(p == nullptr) return false;

    while(fread(&obj, tamanioRegistro, 1, p) == 1){
        if(!obj.getEliminado()){
            obj.Mostrar();
            cout << endl;
        }
    }
    fclose(p);
    return true;
}
int ArchivoCancion::buscarRegistro(int IdCancion){
    Cancion obj;
    FILE *p;
    p=fopen(nombre,"rb");

    if(p==nullptr){
       return -1;
    }
    int cantReg=contarRegistros();
    for(int i=0;i<cantReg;i++){
        fread(&obj, tamanioRegistro,1,p);
        if(!obj.getEliminado() && obj.getIdCancion()==IdCancion){
            fclose(p);
            return i;
        }
    }

    fclose(p);
    return -2;

}
Cancion ArchivoCancion::leerRegistro(int pos){//corregir
    Cancion obj;
    FILE *p;
    p=fopen(nombre,"rb");

    if(p==nullptr){
       return obj;
    }
    fseek(p, tamanioRegistro*pos,0);
    fread(&obj, tamanioRegistro,1,p);
    fclose(p);
    return obj;

}


bool ArchivoCancion::modificarRegistro(Cancion reg, int pos){
    FILE *p;
    p=fopen(nombre,"rb+");
    if(p==nullptr){
       return false;
    }
    fseek(p, pos*tamanioRegistro,0);
    bool escribio=fwrite(&reg, tamanioRegistro,1,p);
    fclose(p);
    return escribio;


}

int ArchivoCancion::contarRegistros(){
    Cancion obj;
    FILE *p;
    p=fopen(nombre,"rb");

    if(p==nullptr){
       return 0;
    }
    fseek(p,0,2);
    int cantReg=ftell(p)/tamanioRegistro;
    fclose(p);
    return cantReg;
}

bool ArchivoCancion::bajaLogica(int pos){
    Cancion reg = leerRegistro(pos);
    reg.setEliminado(true);
    return modificarRegistro(reg, pos);
}

bool ArchivoCancion::activarRegistro(int pos){
    Cancion reg = leerRegistro(pos);
    reg.setEliminado(false);
    return modificarRegistro(reg, pos);
}
 Cancion ArchivoCancion::leerRegistroPorId(int id){
    Cancion obj;
    FILE *p = fopen(nombre, "rb");
    if(p == nullptr) return obj;

    while(fread(&obj, sizeof(Cancion), 1, p) == 1){
        if(obj.getIdCancion() == id){
            fclose(p);
            return obj;
        }
    }

    fclose(p);
    return obj;
}
