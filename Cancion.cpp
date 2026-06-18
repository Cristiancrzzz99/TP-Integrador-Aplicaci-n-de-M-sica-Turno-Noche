#include<cstdlib>
#include<cstring>
#include <iostream>
#include "Cancion.h"
#include "Funciones.h"
#include "ArchivoCancion.h"
#include "ArchivoGenero.h"
#include "ArchivoInterprete.h"
using namespace std;


void Cancion::Cargar(){
  //  cout<<"ingrese ID de la CANCION: ";
 //   cin>>IdCancion;
    cout<<"ingrese el nombre de la CANCION: ";
    cin.ignore();
    cin.getline(Nombre, 20);
    cout<<"Ingrese el ID de INTERPRETE: ";
    cin>>IdInterprete;
    cout<<"Ingrese el ID del GENERO: ";
    cin>>IdGenero;
    cout<<"ingrese la FECHA DE PUBLICACION: "<<endl;
    FechaPublicacion.Cargar();
    Eliminado= false;

}
void Cancion::Mostrar(){
    cout<<"------------------------------------------------------"<<endl;
    cout<<"ID CANCION: "<<IdCancion<<endl;
    cout<<"NOMBRE: "<<Nombre<<endl;
    cout<<"ID INTERPRETE: "<<IdInterprete<<endl;
    cout<<"ID GENERO: "<<IdGenero<<endl;
    cout<<"FECHA DE PUBLICACION: "<<endl;
      FechaPublicacion.Mostrar();
    cout<<"ESTADO: "<<(Eliminado?"eliminado" : "activo")<<endl;
    cout<<"------------------------------------------------------"<<endl;
}

bool altaCancion(){

    Cancion reg;
    ArchivoCancion arcC("Canciones.dat");
    ArchivoGenero arcGen("Generos.dat");
    ArchivoInterprete arcIn("Interpretes.dat");

    int idGenero, idInterprete;
     char nombre[20];
     Fecha fecha;
    cout << "Ingrese el nombre de la CANCION: ";
    cin.ignore();
    cin.getline(nombre, 20);

    reg.setNombre(nombre);

    do{
        cout<<"Ingrese el ID de INTERPRETE: ";
        cin>>idInterprete;

        if(idInterprete <= 0){

            cout<<"ERROR ID NO INVALIDO"<<endl;
        }
        else if(arcIn.buscarRegistro(idInterprete)<0){
            cout<<"ERROR EL INTERPRETE NO EXISTE"<<endl;
           idInterprete =-1;

        }

    }while(idInterprete <= 0);


    reg.setInterprete(idInterprete);

    do{
        cout<<"Ingrese el ID de GENERO: ";
        cin>>idGenero;

        if(idGenero<= 0){
            cout<<"ERROR ID NO VALIDO"<<endl;
        }
        else if (arcGen.buscarRegistro(idGenero)<0){
            cout<<"ERROR, EL GENERO NO EXISTE"<<endl;
            idGenero=-1;
        }

    }while(idGenero <= 0);


    reg.setIdGenero(idGenero);

    cout<<"Ingrese la FECHA DE PUBLICACION:"<<endl;
    fecha.Cargar();
    reg.setFechaPublicacion(fecha);

    int nuevoID=arcC.contarRegistros() + 1;

    reg.setIdCancion(nuevoID);

    reg.setEliminado(false);

    if(arcC.agregarRegistro(reg) > 0){
        cout<<"Cancion registrada correctamente. ID: "<<nuevoID<<endl;
        return true;
    }

    return false;
}
bool bajaCancion(){
    ArchivoCancion archi("Canciones.dat");
    int IdCancion;

    cout<<"INGRESE EL ID DE LA CANCION A BORRAR: ";
    cin>>IdCancion;

    int pos=archi.buscarRegistro(IdCancion);

    if(pos==-1){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        system("pause");
        return false;
    }

    if(pos == -2){
        cout<<"NO EXISTE UNA CANCION CON ESE ID"<<endl;
        system("pause");
        return false;
    }

    Cancion reg = archi.leerRegistro(pos);

    if(reg.getEliminado()){
        cout<<"LA CANCION YA SE ENCUENTRA ELIMINADA"<<endl;
        system("pause");
        return false;
    }

    if(archi.bajaLogica(pos)){
        cout<<"CANCION ELIMINADA CORRECTAMENTE"<<endl;
    }
    else{
        cout<<"NO SE PUDO ELIMINAR LA CANCION"<<endl;
    }

    system("pause");
    return true;
}
bool modificarCancion(){
    ArchivoCancion archi;
    int id;

    cout<<"INGRESE EL ID DE LA CANCION A MODIFICAR: ";
    cin>>id;

    int pos=archi.buscarRegistro(id);

    if(pos==-1){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    if(pos==-2){
        cout<<"NO EXISTE UNA CANCION CON ESE ID"<<endl;
        return false;
    }

    Cancion reg = archi.leerRegistro(pos);

    cout<<"NOMBRE ACTUAL: "<<reg.getNombre()<<endl;

    char nuevoNombre[20];
    cout<<"INGRESE EL NUEVO NOMBRE: ";
    cin.get();
    cargarCadena(nuevoNombre, 20);

    reg.setNombre(nuevoNombre);

    if(archi.modificarRegistro(reg, pos)){
        cout << "REGISTRO MODIFICADO EXITOSAMENTE"<<endl;
        return true;
    }

    cout<<"NO SE PUDO MODIFICAR EL REGISTRO"<<endl;
    return false;
}
bool listarCancion(){
    ArchivoCancion archi;

    if(archi.contarRegistros() == 0){
        cout<<"No hay canciones cargadas"<<endl;
        system("pause");
        return false;
    }

    archi.listarRegistros();

    cout<<endl;
    return true;
}


