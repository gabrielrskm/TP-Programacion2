#pragma once
#include <string>
#include "orden-venta.h"

class ArchivoOrdenVenta{
    private:
        const char * _nombreArchivo  = "orden-venta.dat";
        
    public:
        ArchivoOrdenVenta();
        bool Guardar(OrdenVenta ordenventa);
        bool Guardar(OrdenVenta ordenventa, int posicion);
        int Buscar(std::string idCliente);
        OrdenVenta Leer(int posicion);
        int CantidadRegistros();
        void Leer(int cantidadRegistros, OrdenVenta *vector);
};