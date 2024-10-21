#pragma once
#include <string>
#include  "usuario.h"

class ArchivoUsuario{
    private:
        const char * _nombreArchivo  = "db/usuario.dat";
        
    public:
        ArchivoUsuario();
        bool Crear();
        bool Guardar(Usuario usuario);
        bool Guardar(Usuario usuario, int posicion);
        int Buscar(std::string nombreUsuario);
        Usuario Leer(int posicion);
        int CantidadRegistros();
        void Leer(int cantidadRegistros, Usuario *vector);
};