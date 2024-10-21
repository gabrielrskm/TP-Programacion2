#pragma once
#include <string>
#include "orden-venta.h"

class ArchivoOrdenVenta{
    private:
        const char * _nombreArchivo  = "db/orden-venta.dat";
        
    public:
        ArchivoOrdenVenta();
        bool Crear();
        bool Guardar(OrdenVenta ordenventa);
        bool Guardar(OrdenVenta ordenventa, int posicion);
        int Buscar(int idCliente);
        OrdenVenta Leer(int posicion);
        int CantidadRegistros();
        void Leer(int cantidadRegistros, OrdenVenta *vector);
};