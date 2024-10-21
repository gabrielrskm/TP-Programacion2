#pragma once
#include <string>
#include "factura.h"

class ArchivoFactura{
    private:
        const char * _nombreArchivo  = "db/factura.dat";
        
    public:
        ArchivoFactura();
        bool Crear();
        bool Guardar(Factura factura);
        bool Guardar(Factura factura, int posicion);
        int Buscar(int nroFactura);
        Factura Leer(int posicion);
        int CantidadRegistros();
        void Leer(int cantidadRegistros, Factura *vector);
};