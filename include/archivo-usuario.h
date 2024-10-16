#pragma once
#include <string>
#include  "usuario.h"

class ArchivoProveedor{
    private:
        const char * _nombreArchivo  = "usuario.dat";
        
    public:
        ArchivoProveedor();
        bool Guardar(Usuario usuario);
        bool Guardar(Usuario usuario, int posicion);
        int Buscar(std::string IdUsuario);
        Usuario Leer(int posicion);
        int CantidadRegistros();
        void Leer(int cantidadRegistros, Usuario *vector);
};