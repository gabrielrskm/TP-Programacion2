#pragma once
#include <string>
#include "movimientos.h"

class ArchivoMovimientos{
    private:
        const char * _nombreArchivo  = "movimientos.dat";
        
    public:
        ArchivoMovimientos();
        bool Guardar(Movimientos movimientos);
        bool Guardar(Movimientos movimientos, int posicion);
        int Buscar(int nroMovimiento);
        Movimientos Leer(int posicion);
        int CantidadRegistros();
        void Leer(int cantidadRegistros, Movimientos *vector);
};