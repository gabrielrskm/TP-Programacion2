#pragma once
#include <string>
#include "composicion-movimiento.h"

class ArchivoComposicionMovimientos{
    private:
        const char * _nombreArchivo  = "composicion-movimiento.dat";
        
    public:
        ArchivoComposicionMovimientos();
        bool Guardar(ComposicionMovimientos composicion);
        bool Guardar(ComposicionMovimientos composicion, int posicion);
        int Buscar(int nromovimiento);
        ComposicionMovimientos Leer(int posicion);
        int CantidadRegistros();
        void Leer(int cantidadRegistros, ComposicionMovimientos *vector);
};