#include<cstdlib>
#include<cstring>
#include <iostream>
#include "Acceso.h"
#include "ArchivoAcceso.h"

using namespace std;
#include <ctime>
void Acceso::Cargar(){
    cout<<"Ingrese su ID de USUARIO: ";
    cin>>IdUsuario;

    cout<<"Ingrese el ID de la CANCION: ";
    cin>>IdCancion;

    time_t t=time(NULL);
     tm *tiempo=localtime(&t);

    Hora    = tiempo->tm_hour;
    Minuto  = tiempo->tm_min;
    Segundo = tiempo->tm_sec;

    FechaAcceso.setDia(tiempo->tm_mday);
    FechaAcceso.setMes(tiempo->tm_mon + 1);
    FechaAcceso.setAnio(tiempo->tm_year + 1900);

    Eliminado=false;
}
void Acceso::Mostrar(){
    cout<<"------------------------------------------------------"<<endl;
    cout<<"ID ACCESO: "<<IdAcceso<<endl;
    cout<<"ID USUARIO: "<<IdUsuario<<endl;
    cout<<"ID CANCION: "<<IdCancion<<endl;
    cout<<"Fecha: ";
    cout << "Fecha: ";
    FechaAcceso.Mostrar();
    cout << " ";

   cout<<"Hora: ";
   if(Hora<10) cout<< "0";
    cout<<Hora<< ":";

    if(Minuto<10) cout<<"0";
    cout<<Minuto<<":";

    if(Segundo<10) cout<<"0";
     cout<<Segundo<< endl;
    cout<<"ESTADO: "<<(Eliminado?"eliminado" : "activo")<<endl;
    cout<<"------------------------------------------------------"<<endl;

}

bool altaAcceso(){
    Acceso reg;
    ArchivoAcceso archi;

    int nuevoID=archi.contarRegistros()+1;
    reg.setIdAcceso(nuevoID);
    reg.Cargar();
    if(archi.agregarRegistro(reg)>0){
        cout<<"REPRODUCIENDO...."<<endl;
        cout<<""<<endl;
        cout<<"CANCION ESCUCHADA!!!"<<endl;
        cout<<"Reproduccion registara correctamente con ID:" <<nuevoID<<endl;
        return true;
        }
        return false;
    }


bool listarAcceso(){
    ArchivoAcceso archi;
    if(!archi.listarRegistros()){
        cout<<"NO SE PUDO ABRIR LOS ACCESOS"<< endl;
        return false;
    }
    return true;
}
bool bajaAcceso(){
    ArchivoAcceso archi;
    int id;

    cout<<"ID ACCESO A BORRAR: ";
    cin>>id;

    int pos=archi.buscarRegistro(id);

    if(pos==-1){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        system("pause");
        return false;
    }
    if(pos==-2){
        cout<<"NO EXISTE ESE ACCESO"<<endl;
        system("pause");
        return false;
    }

    if(archi.bajaLogica(pos)){
        cout << "ACCESO ELIMINADO CORRECTAMENTE"<<endl;
        system("pause");
        return true;
    }

    cout<<"NO SE PUDO ELIMINAR EL ACCESO"<<endl;
    system("pause");
    return false;
}
bool modificarAcceso(){
    ArchivoAcceso archi;
    int id;

    cout<<"ID ACCESO A MODIFICAR: ";
    cin>>id;

    int pos=archi.buscarRegistro(id);

    if(pos==-1){
        cout<< "NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        system("pause");
        return false;
    }
    if(pos==-2){
        cout<<"NO EXISTE ESE ACCESO"<<endl;
        system("pause");
        return false;
    }

    Acceso reg=archi.leerRegistro(pos);

    cout<<"ID CANCION ACTUAL: "<<reg.getIdCancion()<<endl;
    cout<<"NUEVO ID CANCION: ";
    int nuevaCancion;
    cin>>nuevaCancion;

    reg.setIdCancion(nuevaCancion);

    if(archi.modificarRegistro(reg, pos)){
        cout<<"ACCESO MODIFICADO CORRECTAMENTE"<<endl;
        system("pause");
        return true;
    }

    cout << "NO SE PUDO MODIFICAR EL ACCESO"<<endl;
    system("pause");
    return false;
}
