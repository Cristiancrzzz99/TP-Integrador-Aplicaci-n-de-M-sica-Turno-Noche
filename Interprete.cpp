#include<cstdlib>
#include<cstring>
#include <iostream>
#include "Funciones.h"
#include "ArchivoInterprete.h"

#include "interprete.h"
using namespace std;

void Interprete::Cargar(){
  //  cout<<"ingrese ID del Interprete: ";
 //   cin>>IdInterprete;
    cout<<"ingrese el nombre del el/la interprete: ";
    cargarCadena(Nombre, 30);
    Eliminado=true;
}
void Interprete::Mostrar(){
    cout<<"------------------------------------------------------"<<endl;
    cout<<"ID INTERPRETE: "<<IdInterprete<<endl;
    cout<<"NOMBRE: "<<Nombre<<endl;
    cout<<"ESTADO: "<<(Eliminado?"activo" : "eliminado")<<endl;
    cout<<"------------------------------------------------------"<<endl;

}

bool altaInterprete(){
    Interprete reg;
    ArchivoInterprete archi;

    int nuevoID = archi.contarRegistros() + 1;
    reg.setIdInterprete(nuevoID);


    reg.Cargar();
    reg.seteliminado(true);

    if(archi.agregarRegistro(reg)>0){
        cout<<"Interprete agregado con ID: "<<nuevoID<<endl;
        return true;
    }

    cout<<"Error al guardar interprete."<<endl;
    return false;
}
bool modificarInterprete(){
    ArchivoInterprete archi;
    int id;

    cout<<"INGRESE ID DE INTERPRETE A MODIFICAR: ";
    cin>>id;

    int pos=archi.buscarRegistro(id);
    if(pos<0){
        cout<<"ID INEXISTENTE O ELIMINADO."<<endl;
        return false;
    }

    Interprete reg = archi.leerRegistro(pos);

    cout<<"NOMBRE ACTUAL: "<<reg.getNombre()<<endl;
    cout<< "NUEVO NOMBRE: ";
    char nuevoNombre[30];
    cin.ignore();
    cin.getline(nuevoNombre, 30);

    reg.setNombre(nuevoNombre);

    if(archi.modificarRegistro(reg, pos)){
        cout<<"NOMBRE MODIFICADO CORRECTAMENTE"<<endl;
        return true;
    }

    cout<<"ERROR AL MODIFICAR"<<endl;
    return false;
}
bool listarInterprete(){
    ArchivoInterprete archi;
    if(!archi.listarRegistros()){
        cout << "No se pudo abrir Interpretes.dat"<<endl;
        return false;
    }

    return true;
}
bool eliminarInterprete(){
    ArchivoInterprete archi;
    int IdInterprete;
    cout<<"INGRESAR EL ID DEL INTERPRETE A BORRAR ";
    cin>>IdInterprete;
    int pos=archi.buscarRegistro(IdInterprete);
    if(pos==-1){
         cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
         return false;
    }
    if(pos==-2){
            cout<<"NO EXISTE UN REGISTRO CON ESE ID DE INTERPRETE "<<endl;
            return false;
    }
    return archi.bajaLogica(pos);
}
