#pragma once
#include <string>
#include  "usuario.h"

class ArchivoUsuario{
    public:
        ArchivoUsuario();
        bool Crear();
        bool Guardar(Usuario usuario);
        bool Guardar(Usuario usuario, int posicion);
        int Buscar(std::string busqueda, int tipoDeBuqueda);        
        Usuario Leer(int posicion);
        Usuario* LeerTodos();
        int calcularCantidadRegistros();
        int aumentarRegistros();
        void Leer(int cantidadRegistros, Usuario *vector);
        int getCantidadRegistros(); 

    private:
        const char * _nombreArchivo  = "db/usuario.dat";
        int _cantidadRegistros = -1; 
        
};