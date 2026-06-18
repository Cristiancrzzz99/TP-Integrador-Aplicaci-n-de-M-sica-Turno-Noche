#include <iostream>
#include <cstring>

using namespace std;
#include "Acceso.h"
#include "ArchivoAcceso.h"

ArchivoAcceso::ArchivoAcceso(const char *n){
    strcpy(nombre, n);
    tamanioRegistro=sizeof(Acceso);
}
int ArchivoAcceso::agregarRegistro(Acceso reg){
     FILE *p;
     p=fopen(nombre, "ab");
     if(p==nullptr){
        return -1;

     }
     int escribio=fwrite(&reg, tamanioRegistro,1,p);

    fclose(p);
    return escribio;
}
bool ArchivoAcceso::listarRegistros(){
    Acceso obj;
    FILE *p;
    p=fopen(nombre,"rb");

    if(p==nullptr){
       return false;
    }
    while(fread(&obj, tamanioRegistro,1,p)==1){
        if(!obj.getEliminado()){
            obj.Mostrar();
            cout<<endl;
        }
    }
    fclose(p);
    return true;
}
int ArchivoAcceso::buscarRegistro(int IdAcceso){
    Acceso obj;
    FILE *p;
    p=fopen(nombre,"rb");

    if(p==nullptr){
       return -1;
    }
    int cantReg=contarRegistros();
    for(int i=0;i<cantReg;i++){
        fread(&obj, tamanioRegistro,1,p);
        if(!obj.getEliminado() && obj.getIdAcceso()==IdAcceso){
            fclose(p);
            return i;
        }
    }

    fclose(p);
    return -2;

}
Acceso ArchivoAcceso::leerRegistro(int pos){
    Acceso obj;
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


bool ArchivoAcceso::modificarRegistro(Acceso reg, int pos){
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

int ArchivoAcceso::contarRegistros(){
    Acceso obj;
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

bool ArchivoAcceso::bajaLogica(int pos){
    Acceso reg;
    reg=leerRegistro(pos);
    reg.setEliminado(true);
    return modificarRegistro(reg,pos);
}


bool ArchivoAcceso::activarRegistro (int pos){
    Acceso reg;
    reg=leerRegistro(pos);
    reg.setEliminado(false);
    return modificarRegistro(reg,pos);

}

