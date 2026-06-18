#include <iostream>
#include <cstring>

using namespace std;
#include "Fecha.h"
#include "Usuario.h"
#include "ArchivoUsuario.h"

ArchivoUsuario::ArchivoUsuario(const char *n){
    strcpy(nombre, n);
    tamanioRegistro=sizeof(Usuario);
}
int ArchivoUsuario::agregarRegistro(Usuario reg){
     FILE *p;
     p=fopen(nombre, "ab");
     if(p==nullptr){
        return -1;

     }
     int escribio=fwrite(&reg, tamanioRegistro,1,p);

    fclose(p);
    return escribio;
}
bool ArchivoUsuario::listarRegistros(){
    Usuario obj;
    FILE *p;
    p=fopen(nombre,"rb");

    if(p==nullptr){
       return false;
    }
    while(fread(&obj, tamanioRegistro,1,p)==1){
        if(obj.getEliminado()){
            obj.Mostrar();
            cout<<endl;
        }
    }
    fclose(p);
    return true;
}
int ArchivoUsuario::buscarRegistro(int idUsuario){
    Usuario obj;
    FILE *p;
    p=fopen(nombre,"rb");

    if(p==nullptr){
       return -1;
    }
    int cantReg=contarRegistros();
    for(int i=0;i<cantReg;i++){
        fread(&obj, tamanioRegistro,1,p);
        if(obj.getEliminado() && obj.getIdUsuario()==idUsuario){
            fclose(p);
            return i;
        }
    }

    fclose(p);
    return -2;

}
Usuario ArchivoUsuario::leerRegistro(int pos){
    Usuario obj;
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


bool ArchivoUsuario::modificarRegistro(Usuario reg, int pos){
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

int ArchivoUsuario::contarRegistros(){
    Usuario obj;
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

bool ArchivoUsuario::bajaLogica(int pos){
    Usuario reg;
    reg=leerRegistro(pos);
    reg.setEliminado(false);
    return modificarRegistro(reg,pos);
}


bool ArchivoUsuario::activarRegistro (int pos){
    Usuario reg;
    reg=leerRegistro(pos);
    reg.setEliminado(true);
    return modificarRegistro(reg,pos);

}

