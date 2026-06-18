#include <iostream>
#include <cstdlib>

#include "Funciones.h"
#include "Informes.h"

#include "Funciones.h"
#include "usuario.h"
#include "Cancion.h"
#include "acceso.h"
#include "interprete.h"
#include "genero.h"


//
#include "ArchivoUsuario.h"
#include "ArchivoCancion.h"

using namespace std;

void ingresoAppMusical(){
   int opc;
       do{
        system("cls");
        cout << "------------BIENVENIDO A LA APLICACION DE MUSICA-----------" << endl;
        cout << "1. INICIAR SESION" << endl;
        cout << "2. REGISTRAR NUEVO USUARIO" << endl;
        cout << "0. SALIR" << endl;

        cin>>opc;

        switch(opc){
         case 1:{
              int idUsuario=ingresoUsuario();
              if(idUsuario>0){
                menuApp(idUsuario);
              }}
              break;
         case 2:
            altaUsuario();
             break;
         case 0:
            return;
         default:
            cout<<"Opcion incorrecta"<<endl;


} system("pause");
    }while(opc != 0);
}


void menuMostrar(){
    int opc;
    do{
        system("cls");
        cout << "-----------MOSTRAR ARCHIVOS --------" << endl;
        cout << "1. Usuarios" << endl;
        cout << "2. Canciones" << endl;
        cout << "3. Interpretes" << endl;
        cout << "4. Generos" << endl;
        cout << "5. Accesos" << endl;
        cout << "0. Volver" << endl;
        cout << "Opcion: ";
        cin >> opc;

        switch(opc){
           case 1: menuUsuarios();system("pause"); break;
           case 2: menuCanciones();system("pause"); break;
           case 3: menuInterprete(); system("pause");break;
           case 4: menuGenero();system("pause"); break;
           case 5: menuAcceso(); system("pause"); break;
           case 0: break;
            default: cout << "Opcion incorrecta." << endl; system("pause");
        }
    }while(opc != 0);
}



void menuConsultas(){

    int opc;
    do{
        system("cls");
        cout<<"---------- CONSULTAS Y ESTADISTICAS (INFORMES) ----------------------------" << endl;
        cout<<"1. Canciones mas reproducidas"<<endl;
        cout<<"2. Genero musical mas escuchado"<<endl;
        cout<<"3. Usuario con mas reproducciones"<<endl;
        cout<<"4. Interprete mas escuchado"<<endl;
        cout<<"0. Volver"<<endl;
        cout<<"Opcion: ";
        cin>>opc;

        switch(opc){
           case 1: informeCancionMasEscuchada(); system("pause");break;
           case 2: informeGeneroMasEscuchado();system("pause");break;
           case 3: informeUsuarioMasReproducciones();system("pause"); break;
           case 4: informeInterpreteMasEscuchado();system("pause");break;
           case 0: break;
            default: cout << "Opcion incorrecta." << endl; system("pause");
        }
    }while(opc != 0);
}

