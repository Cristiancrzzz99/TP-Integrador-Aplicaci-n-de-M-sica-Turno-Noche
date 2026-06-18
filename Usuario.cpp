#include "Usuario.h"
#include "Funciones.h"
#include "ArchivoUsuario.h"
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

void Usuario::Cargar(){
    cout<<"=== REGISTRO DE USUARIO ==="<<endl;
    cout<<endl<<"=== DATOS PERSONALES ==="<<endl;
    persona.Cargar();
    cout<<"Ingrese clave: ";
    cargarCadena(Clave, 20);
    Eliminado = false;
}

void Usuario::Mostrar(){
    cout<<"------------------------------------------------------"<<endl;
    cout<<"ID USUARIO: " << IdUsuario<<endl;
    cout<< "CLAVE: " << Clave<<endl;
    cout<<endl<< "=== DATOS PERSONALES ==="<<endl;
    persona.Mostrar();
    cout<<"ESTADO: "<<(Eliminado ? "ACTIVO" : "ELIMINADO")<<endl;
    cout<< "------------------------------------------------------"<<endl;
}

int ingresoUsuario(){
    ArchivoUsuario archi;
    int id;
    char clave[20];

    while(true){
        cout<<"INGRESE SU ID: ";
        cin>>id;

        int pos=archi.buscarRegistro(id);

        if(pos==-1){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
            return -1;
        }
        if(pos==-2){
            cout<<"ID INCORRECTO. VUELVA A INTENTAR"<<endl;
            continue;
        }

        Usuario reg = archi.leerRegistro(pos);

        cout<<"INGRESE SU CLAVE: ";
        cin>>clave;

        if(strcmp(reg.getClave(), clave) == 0){
            cout<<"ACCESO PERMITIDO\n";
            return id;
        } else {
            cout<<"CLAVE INCORRECTA. VUELVA A INTENTAR.\n";
        }
    }

    return -1;
}
void cargarCadena(char *pal, int tam){
    int i;
    fflush(stdin);
    for(i=0; i<tam; i++)
    {
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}


bool bajaUsuario(){
    ArchivoUsuario archi;
    int IdUsuario;
    cout<<"INGRESAR EL ID DEL USUARIO A BORRAR ";
    cin>>IdUsuario;
    int pos=archi.buscarRegistro(IdUsuario);
    if(pos==-1){
         cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
         return false;
    }
    if(pos==-2){
            cout<<"NO EXISTE UN REGISTRO CON ESE USUARIO"<<endl;
            return false;
    }
    return archi.bajaLogica(pos);
}

bool modificarUsuario(){
    int IdUsuario;
    ArchivoUsuario archi;
    Usuario reg;

    cout<<"INGRESAR EL ID DEL USUARIO A MODIFICAR: ";
    cin>>IdUsuario;

    int pos=archi.buscarRegistro(IdUsuario);

    if(pos==-1){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO\n";
        return false;
    }
    if(pos==-2){
        cout<< "NO EXISTE UN USUARIO CON ESE ID\n";
        return false;
    }

    reg = archi.leerRegistro(pos);

    cout<<"INGRESE NUEVA CLAVE: ";
    cin.ignore();
    char nuevaClave[20];
    cargarCadena(nuevaClave, 20);
    reg.setClave(nuevaClave);

    if(archi.modificarRegistro(reg, pos)){
        cout<<"CLAVE MODIFICADA CORRECTAMENTE\n";
        return true;
    }

    cout<<"NO SE PUDO MODIFICAR EL REGISTRO\n";
    return false;
}

bool listarUsuario(){
    ArchivoUsuario archi;
    if(archi.contarRegistros()==0)return false;
    archi.listarRegistros();
    system("pause");
    return true;
}

bool altaUsuario(){
    Usuario reg;
    ArchivoUsuario archi;

    int nuevoID = archi.contarRegistros() + 1;
    reg.setIdUsuario(nuevoID);

    reg.Cargar();
    reg.setEliminado(true);

    if(archi.agregarRegistro(reg) > 0){
        cout<<"Registro agregado con ID: "<<nuevoID<<endl;
        return true;
    }
    return false;
}
