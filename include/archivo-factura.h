#pragma once
#include <string>
#include "factura.h"

class ArchivoFactura{
    private:
        const char * _nombreArchivo  = "factura.dat";
        
    public:
        ArchivoFactura();
        bool Guardar(Factura factura);
        bool Guardar(Factura factura, int posicion);
        int Buscar(int nroFactura, char tipo);
        Factura Leer(int posicion);
        int CantidadRegistros();
        void Leer(int cantidadRegistros, Factura *vector);
};