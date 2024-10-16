#pragma once
#include <string>
#include "proveedor.h"

class ArchivoProveedor{
    private:
        const char * _nombreArchivo  = "Proveedor.dat";
        
    public:
        ArchivoProveedor();
        bool Guardar(Proveedor proveedor);
        bool Guardar(Proveedor proveedor, int posicion);
        int Buscar(std::string IDProveedor);
        Proveedor Leer(int posicion);
        int CantidadRegistros();
        void Leer(int cantidadRegistros, Proveedor *vector);
};