#pragma once
#include <string>
#include "orden-produccion.h"

class ArchivoOrdenProduccion{
    private:
        const char * _nombreArchivo  = "orden-produccion.dat";
        
    public:
        ArchivoOrdenProduccion();
        bool Guardar(OrdenProduccion ordenProduccion);
        bool Guardar(OrdenProduccion ordenProduccion, int posicion);
        int Buscar(std::string idProducto);
        OrdenProduccion Leer(int posicion);
        int CantidadRegistros();
        void Leer(int cantidadRegistros, OrdenProduccion *vector);
};