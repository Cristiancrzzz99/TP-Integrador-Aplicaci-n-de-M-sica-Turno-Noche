#include<cstdlib>
#include<cstring>
#include <iostream>
#include "Funciones.h"
#include "ArchivoGenero.h"

#include "genero.h"
using namespace std;

void Genero::Cargar()
{
//   cout<<"ingrese ID del genero: ";
//    cin>>IdGenero;
    cout<<"ingrese el nombre del genero: ";
    cargarCadena(Nombre, 20);
    Eliminado=true;
}
void Genero::Mostrar()
{
    cout<<"------------------------------------------------------"<<endl;
    cout<<"ID GENERO: "<<IdGenero<<endl;
    cout<<"NOMBRE: "<<Nombre<<endl;
    cout<<"ESTADO: "<<(Eliminado?"activo" : "eliminado")<<endl;
    cout<<"------------------------------------------------------"<<endl;

}
bool altaGenero()
{
    Genero reg;
    ArchivoGenero archi;

    int nuevoID = archi.contarRegistros()+1;
    reg.setIdGenero(nuevoID);
    reg.Cargar();

    if(archi.agregarRegistro(reg)>0)
    {
        cout<<"GENERO AGREGADO CON ID: "<<nuevoID<<endl;
        return true;
    }
    return false;
}
bool bajaGenero()
{
    ArchivoGenero archi;
    int id;

    cout<<"INGRESE EL ID DEL GENERO A ELIMINAR: ";
    cin>>id;

    int pos=archi.buscarRegistro(id);

    if(pos==-1)
    {
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    if(pos == -2)
    {
        cout<<"NO EXISTE GENERO CON ESE ID"<<endl;
        return false;
    }

    if(archi.bajaLogica(pos))
    {
        cout<<"GENERO DADO DE BAJA CORRECTAMENTE"<<endl;
        return true;
    }

    cout<<"NO SE PUDO ELIMINAR EL GENERO"<<endl;
    return false;
}

bool modificarGenero()
{
    ArchivoGenero archi;
    int id;

    cout<<"INGRESE EL ID DEL GENERO A MODIFICAR: ";
    cin >> id;

    int pos=archi.buscarRegistro(id);

    if(pos==-1)
    {
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    if(pos==-2)
    {
        cout<<"NO EXISTE GENERO CON ESE ID"<<endl;
        return false;
    }

    Genero reg=archi.leerRegistro(pos);

    cout<<"NOMBRE ACTUAL:"<<reg.getNombre()<<endl;

    char nuevoNombre[20];
    cout<< "INGRESE NUEVO NOMBRE: ";
    cin.ignore();
    cin.getline(nuevoNombre, 20);

    reg.setNombre(nuevoNombre);

    if(archi.modificarRegistro(reg, pos))
    {
        cout<<"GENERO MODIFICADO EXITOSAMENTE"<<endl;
        return true;
    }

    cout<<"NO SE PUDO MODIFICAR EL GENERO"<<endl;
    return false;
}

bool listarGenero()
{
    ArchivoGenero archi;

    if(!archi.listarRegistros())
    {
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    return true;
}
