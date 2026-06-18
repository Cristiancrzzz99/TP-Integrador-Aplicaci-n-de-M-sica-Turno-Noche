#include <iostream>
#include <cstdlib>
#include "Usuario.h"
#include "Cancion.h"
#include "Acceso.h"
#include "Interprete.h"
#include "Genero.h"
#include "Funciones.h"
#include "Menues.h"
using namespace std;
#include "ArchivoUsuario.h"
#include "ArchivoCancion.h"
#include "ArchivoAcceso.h"
#include "ArchivoInterprete.h"


void menuApp(int idUsuario){
    ArchivoUsuario arcU;
    int pos=arcU.buscarRegistro(idUsuario);
    Usuario reg = arcU.leerRegistro(pos);
    int opc;
    do{
        system("cls");
        cout << "------ MENU DE USUARIO-------"<<endl;
        cout<< "Bienvenido "<<reg.getPersona().getNombre()<<" "<< reg.getPersona().getApellido()<<endl<<endl;
        cout << "1. Escuchar una cancion"<<endl;
        cout << "2. Explorar por interprete"<<endl;
        cout << "3. Explorar por genero"<<endl;
        cout << "4. Ver historial (accesos)"<<endl;

        cout << "0. Cerrar sesion"<<endl;
        cin >> opc;

        switch(opc){
            case 1:
                menuAppCancion();

                break;

            case 2:
                listarInterprete();
                system("pause");
                break;
            case 3:
                listarGenero(); system("pause");
                break;
            case 4:
                listarAcceso();
                system("pause");
                break;

            case 0:
                break;

            default:
                cout << "Opcion incorrecta.\n";
                system("pause");
        }

    } while(opc != 0);
}

//---------------- MENÚ DE USUARIOS ----------------//
void menuUsuarios(){
    int opc;
    do {
        system("cls");
        cout << "---- MENU USUARIOS ----" << endl;
        cout << "1. Agregar usuario" << endl;
        cout << "2. Listar usuarios" << endl;
        cout << "3. Eliminar usuario" <<endl;
        cout << "4. Modificar usuarios" <<endl;

        cout << "0. Volver" << endl;
        cout << "Opcion: ";
        cin >> opc;

        switch(opc){
            case 1: if(altaUsuario()) cout<<"REGISTRO AGREGADO "<<endl;
                    else cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
                    system("pause");
                    break;
            case 2:listarUsuario();
                    break;
            case 3:{
               if(bajaUsuario())
                cout<<"USUARIO ELIMINADO CORRECTAMENTE"<<endl;
              // else
              //  cout<<"NO SE PUDO ELIMINAR EL ARCHIVO"<<endl;
               system("pause");
               break;
            }
            case 4:{
            if(modificarUsuario())
                cout<<"NOMBRE DE USUARIO EDITADO CORRECTAMENTE "<<endl;
           // else
        //     cout<<"NO SE PUDO MODIFICAR LOS DATOS"<<endl;
            system("pause");
            break;
        }
    }
}while(opc != 0);
}
//---------------- MENÚ DE CANCIONES ----------------//
void menuCanciones(){
    int opc;
    do {
        system("cls");
        cout << "---- MENU CANCIONES ----" << endl;
        cout << "1. Agregar cancion" << endl;
        cout << "2. Listar canciones" << endl;
        cout << "3. Modificar cancion" <<endl;
        cout << "4. eliminar cancion" <<endl;

        cout << "0. Volver" << endl;
        cout << "Opcion: ";
        cin >> opc;

        switch(opc){
            case 1:if(altaCancion())cout<<"REGISTRO AGREGADO"<<endl;
            else cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
            system("pause");
            break;
            case 2:listarCancion();
                system("pause");
            break;
            case 3:modificarCancion();
            system("pause");
            break;
            case 4:
            if(bajaCancion())
             break;

        }
    } while(opc != 0);
}
//-------------------------MENU ACCESO-------------------------------
void menuAcceso(){
    int opc;
    do {
        system("cls");
        cout << "---- MENU ACCESO ----" << endl;
        cout << "1. registrar acceso (usuario escucha cancion)" << endl;
        cout << "2. Listar accesos" << endl;
        cout << "3. Borrar accesos" << endl;
        cout << "4. Modificar accesos" << endl;

        cout << "0. Volver" << endl;
        cout << "Opcion: ";
        cin >> opc;

        switch(opc){
            case 1:if(altaAcceso())cout<<"REGISTRO AGREGADO"<<endl;
            else cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
            system("pause");
             break;
            case 2:if(listarAcceso())cout<<"REGISTRO AGREGADO"<<endl;

            system("pause");
            break;
            case 3: bajaAcceso();
            break;
            case 4: modificarAcceso();
            break;
            }
    } while(opc != 0);
}
//------------------------MENU INTERPRETE-----------------------------------------
void menuInterprete(){
    int opc;
    do {
        system("cls");
        cout << "---- MENU INTERPRETE ----" << endl;
        cout << "1. Agregar artista" << endl;
        cout << "2. Listar interpretes" << endl;
        cout << "3. Eliminar interpretes" << endl;
        cout << "4. Modificar interpretes" << endl;

        cout << "0. Volver" << endl;
        cout << "Opcion: ";
        cin >> opc;

        switch(opc){
            case 1:if(altaInterprete())cout<<"REGISTRO AGREGADO"<<endl;
            else cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
            system("pause");
            break;
            case 2:listarInterprete();
            break;
            case 3: if(eliminarInterprete())cout<<"ARTISTA ELIMINADO CORRECTAMENTE"<<endl;
            system ("pause");
            break;
            case 4: modificarInterprete();
            system("pause");
            break;
        }
    } while(opc != 0);
}
//-----------------MENU GENERO-----------------------

void menuGenero(){
    int opc;
    do {
        system("cls");
        cout << "---- MENU GENERO ----" << endl;
        cout << "1. Agregar genero" << endl;
        cout << "2. Listar generos" << endl;
        cout << "3. Eliminar genero" << endl;
        cout << "4. Modificar generos" << endl;

        cout << "0. Volver" << endl;
        cout << "Opcion: ";
        cin >> opc;

        switch(opc){
            case 1:if(altaGenero())cout<<"REGISTRO AGREGADO"<<endl;
            else cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
            system("pause");
            break;
            case 2:if(listarGenero())cout<<"REGISTRO AGREGADO"<<endl;
            system("pause");
            break;
            case 3: bajaGenero();
            system("pause");
            break;
            case 4: modificarGenero();
            system("pause");
            break;
        }
    } while(opc != 0);
}

//---------------- MENÚAPPESCUCHARMUSICA----------------//
void menuAppCancion(){
    int opc;
    do {
        system("cls");
        cout << "---- ESCUCHAR UNA CANCION----" << endl;
        cout << "1. Ver canciones" << endl;
        cout << "2. escuchar cancion" << endl;


        cout << "0. Volver" << endl;
        cout << "Opcion: ";
        cin >> opc;

        switch(opc){
            case 1:
                listarCancion();
                system("pause");
                break;
            case 2: altaAcceso();
           system("pause");
            }
    } while(opc != 0);
}

//----------------------------------------------------------------------------------MENUAPPACCESO-----------------------------------
void menuAppAcceso(){
    int opc;
    do {
        system("cls");
        cout << "---- MENU ACCESO ----" << endl;
        cout << "1. registrar acceso (usuario escucha cancion)" << endl;
        cout << "2. Listar accesos" << endl;


        cout << "0. Volver" << endl;
        cout << "Opcion: ";
        cin >> opc;

        switch(opc){
            case 1:if(altaAcceso())cout<<"REGISTRO AGREGADO"<<endl;
            else cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
            system("pause");
             break;
            case 2:if(listarAcceso())cout<<"REGISTRO AGREGADO"<<endl;
            else cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
            system("pause");
            break;

            }
    } while(opc != 0);
}
