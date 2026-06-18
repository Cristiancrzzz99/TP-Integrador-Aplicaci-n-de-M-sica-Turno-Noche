#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

class Persona{
private:
    char Nombre[20];
    char Apellido[30];
    char Dni[20];
    char Telefono[30];
    char Email[40];
    bool Eliminado;

public:
    Persona(const char* nom="", const char* ape="",
            const char* dni="", const char* tel="",
            const char* email="", bool elim=false);

    void Cargar();
    void Mostrar();


    const char* getNombre();
    const char* getApellido();
    const char* getDni();
    const char* getTelefono();
    const char* getEmail();
    bool getEliminado();


    void setNombre(const char* n);
    void setApellido(const char* a);
    void setDni(const char* d);
    void setTelefono(const char* t);
    void setEmail(const char* e);
    void setEliminado(bool e);
};

#endif // PERSONA_H_INCLUDED
