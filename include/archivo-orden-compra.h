#pragma once
#include <string>
#include "orden-compra.h"

class ArchivoOrdenCompra{
    private:
        const char * _nombreArchivo  = "orden-compra.dat";
        
    public:
        ArchivoOrdenCompra();
        bool Guardar(OrdenCompra ordenCompra);
        bool Guardar(OrdenCompra ordenCompra, int posicion);
        int Buscar(int idProveedor);
        OrdenCompra Leer(int posicion);
        int CantidadRegistros();
        void Leer(int cantidadRegistros, OrdenCompra *vector);
};