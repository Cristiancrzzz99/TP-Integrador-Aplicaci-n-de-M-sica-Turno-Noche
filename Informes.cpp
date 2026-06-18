#include <iostream>
using namespace std;

#include "informes.h"
#include "ArchivoAcceso.h"
#include "ArchivoUsuario.h"
#include "ArchivoCancion.h"
#include "ArchivoInterprete.h"  //terminadoooooo
#include "ArchivoGenero.h"



void informeUsuarioMasReproducciones() {
    ArchivoAcceso arcAcc("Accesos.dat");
    ArchivoUsuario arcUsr("Usuario.dat");

    int cantAcc = arcAcc.contarRegistros();
    int cantUsr = arcUsr.contarRegistros();

    if (cantAcc == 0 || cantUsr == 0) {
        cout<<"No hay datos suficientes"<<endl;
        return;
    }

    int *contador=new int[cantUsr];
    for (int i=0;i<cantUsr;i++) contador[i]=0;


    for (int i=0; i<cantAcc; i++) {
        Acceso a = arcAcc.leerRegistro(i);
        if (!a.getEliminado()) continue;

        int idU=a.getIdUsuario();
        int posU=arcUsr.buscarRegistro(idU);

        if (posU>= 0) contador[posU]++;
    }


    int maxPos = -1;
    int maxCant = -1;
    for (int i=0; i<cantUsr; i++) {
        Usuario u = arcUsr.leerRegistro(i);
        if (!u.getEliminado()) continue;

        if (contador[i] > maxCant) {
            maxCant = contador[i];
            maxPos = i;
        }
    }

    if (maxPos == -1) {
        cout<<"No se encontraron usuarios activos"<<endl;
        delete [] contador;
        return;
    }

    Usuario ganador=arcUsr.leerRegistro(maxPos);

    cout <<"Usuario con mas reproducciones: "<<ganador.getPersona().getNombre()
         <<"(ID "<<ganador.getIdUsuario()<<")"<<endl;

    delete [] contador;
}

void informeInterpreteMasEscuchado() {
    ArchivoAcceso arcAcc("Accesos.dat");
    ArchivoCancion arcCan("Canciones.dat");
    ArchivoInterprete arcInt("Interpretes.dat");

    int cantAcc=arcAcc.contarRegistros();
    int cantCan=arcCan.contarRegistros();
     int cantInt=arcInt.contarRegistros();

    if (cantAcc==0||cantCan==0||cantInt==0) {
        cout <<"No hay datos suficientes"<<endl;
        return;
    }

    int *contador = new int[cantInt];
    for (int i=0;i<cantInt;i++) contador[i] = 0;

    for (int i=0; i<cantAcc; i++) {
        Acceso a=arcAcc.leerRegistro(i);
        if (!a.getEliminado()) continue;

        int idC=a.getIdCancion();
        int posC=arcCan.buscarRegistro(idC);
        if (posC<0) continue;

        Cancion c = arcCan.leerRegistro(posC);
        int idI = c.getIdInterprete();
        int posI = arcInt.buscarRegistro(idI);

        if (posI >= 0) contador[posI]++;
    }

    int maxPos=-1;
    int maxCant=-1;

    for (int i=0;i<cantInt;i++) {
        Interprete in=arcInt.leerRegistro(i);
        if (!in.getEliminado()) continue;

        if (contador[i]>maxCant) {
            maxCant=contador[i];
            maxPos= i;
        }
    }

    if (maxPos==-1) {
        cout<<"No se encontraron interpretes activos."<<endl;
    } else {
        Interprete ganador = arcInt.leerRegistro(maxPos);
        cout<<"Interprete mas escuchado: "
        <<ganador.getNombre()<<endl;

    }

    delete [] contador;
}

void informeCancionMasEscuchada() {
    ArchivoAcceso arcAcc("Accesos.dat");
    ArchivoCancion arcCan("Canciones.dat");

    int cantAcc=arcAcc.contarRegistros();
    int cantCan=arcCan.contarRegistros();

    if (cantAcc==0||cantCan==0) {
        cout<<"No hay datos suficientes."<<endl;
        return;
    }

    int *contador = new int[cantCan];
    for (int i = 0; i < cantCan; i++) contador[i] = 0;


    for (int i=0; i<cantAcc; i++) {
        Acceso a=arcAcc.leerRegistro(i);
        if (a.getEliminado()) continue;

        for (int j=0;j<cantCan; j++) {
            Cancion c = arcCan.leerRegistro(j);
            if (c.getEliminado()) continue;

            if (c.getIdCancion()==a.getIdCancion()) {
                contador[j]++;
                break;
            }
        }
    }

    int maxPos=-1;
    int maxCant=0;

    for (int i=0; i<cantCan; i++) {
        Cancion c = arcCan.leerRegistro(i);
        if (c.getEliminado()) continue;

        if (contador[i] > maxCant) {
            maxCant = contador[i];
            maxPos = i;
        }
    }

    if (maxPos == -1 || maxCant == 0) {
        cout<<"No hay reproducciones registradas."<<endl;
    } else {
        Cancion c = arcCan.leerRegistro(maxPos);
         cout<<"Cancion mas escuchada: "<<c.getNombre()<<endl;
    }

    delete[] contador;
}
void informeGeneroMasEscuchado() {
    ArchivoAcceso arcAcc("Accesos.dat");
    ArchivoCancion arcCan("Canciones.dat");
    ArchivoGenero arcGen("Generos.dat");

    int cantAcc=arcAcc.contarRegistros();
    int cantCan=arcCan.contarRegistros();
    int cantGen=arcGen.contarRegistros();

    if (cantAcc==0||cantCan==0||cantGen==0) {
        cout<<"No hay datos suficientes."<<endl;
        return;
    }

    int *contador = new int[cantGen];
    for (int i=0; i<cantGen; i++) contador[i] = 0;

    for (int i=0; i<cantAcc; i++) {
        Acceso a = arcAcc.leerRegistro(i);
        if (!a.getEliminado()) continue;

        int idC = a.getIdCancion();
        int posC = arcCan.buscarRegistro(idC);
        if (posC < 0) continue;

        Cancion c = arcCan.leerRegistro(posC);
        int idG = c.getIdGenero();

        int posG = arcGen.buscarRegistro(idG);
        if (posG >= 0) contador[posG]++;
    }

    int maxPos = -1;
    int maxCant = -1;

    for (int i=0; i<cantGen; i++) {
        Genero g = arcGen.leerRegistro(i);
        if (!g.getEliminado()) continue;

        if (contador[i] > maxCant) {
            maxCant = contador[i];
            maxPos = i;
        }
    }

    if (maxPos == -1) {
        cout<<"No se encontro genero activo."<<endl;
    } else {
        Genero g = arcGen.leerRegistro(maxPos);
        cout<<"Genero mas escuchado: "<< g.getNombre()<<endl;
    }

    delete [] contador;
}
