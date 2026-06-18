#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void ingresoAppMusical();


void iniciarSesion();
void registrarCuenta();


void menuRegistros();
void menuMostrar();
void menuConsultas();


void menuUsuarios();
void menuCanciones();
void menuAcceso();
void menuInterprete();
void menuGenero();


//menus de usuarios

void menuAppCancion();
void menuAppAcceso();
void menuApp( int idUsuario);

//---------------------------------------------------------FUNCIONES DE CLASES-------------------
//USUARIO

int ingresoUsuario();
bool bajaUsuario();
bool modificarUsuario();
bool listarUsuario();
bool altaUsuario();
void cargarCadena(char *pal, int tam);

//CANCION

bool altaCancion();
bool bajaCancion();
bool modificarCancion();
bool listarCancion();
//ACCESO
bool altaAcceso();
bool listarAcceso();
bool bajaAcceso();
bool modificarAcceso();
//INTERPRETE
bool altaInterprete();
bool modificarInterprete();
bool listarInterprete();
bool eliminarInterprete();
//GENERO
bool altaGenero();
bool bajaGenero();
bool modificarGenero();
bool listarGenero();


#endif // FUNCIONES_H_INCLUDED
