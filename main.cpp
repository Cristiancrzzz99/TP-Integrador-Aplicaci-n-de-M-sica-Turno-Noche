#include <iostream>
#include <cstdlib>
#include "funciones.h"
#include "menues.h"
#include "rlutil.h"
using namespace std;

int main(){
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::RED);
    rlutil::cls();
    int opcionPrincipal;

    do {
        system("cls");
        cout << "-----------------APLICACION DE GESTION DE MUSICA ---------------" << endl;
        cout << "1. INGRESAR A LA APLICACION MUSICAL" << endl;
        cout << "2. CONFIGURACION" << endl;
        cout << "3. CONSULTAS Y ESTADISTICAS" << endl;

        cout << "0. SALIR" << endl;
        cout << "Opcion: ";
        cin >> opcionPrincipal;

        switch(opcionPrincipal){
            case 1:
                ingresoAppMusical();
                break;
            case 2:
                menuMostrar();
                break;
            case 3:
                menuConsultas();
                break;
            case 0:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
                system("pause");
        }
    } while(opcionPrincipal != 0);

    return 0;
}
