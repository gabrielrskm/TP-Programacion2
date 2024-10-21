#pragma once
#include <string>
#include "proveedor.h"

class ArchivoProveedor{
    private:
        const char * _nombreArchivo  = "db/proveedor.dat";
        
    public:
        ArchivoProveedor();
        bool Crear();
        bool Guardar(Proveedor proveedor);
        bool Guardar(Proveedor proveedor, int posicion);
        int Buscar(int IDProveedor);
        Proveedor Leer(int posicion);
        int CantidadRegistros();
        void Leer(int cantidadRegistros, Proveedor *vector);
};