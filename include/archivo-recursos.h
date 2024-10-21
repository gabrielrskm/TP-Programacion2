#pragma once
#include <string>
#include  "recursos.h"

class ArchivoRecurso{
    private:
        const char * _nombreArchivo  = "db/recursos.dat";
        
    public:
        ArchivoRecurso();
        bool Crear();
        bool Guardar(Recurso recursos);
        bool Guardar(Recurso recursos, int posicion);
        int Buscar(std::string codigo);
        Recurso Leer(int posicion);
        int CantidadRegistros();
        void Leer(int cantidadRegistros, Recurso *vector);
};