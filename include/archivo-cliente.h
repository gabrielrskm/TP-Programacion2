#pragma once
#include <string>
#include "cliente.h"

class ArchivoCliente{
    private:
        const char * _nombreArchivo  = "db/Cliente.dat";
        
    public:
        ArchivoCliente();
        bool Crear();
        bool Guardar(Cliente cliente);
        bool Guardar(Cliente cliente, int posicion);
        int Buscar(int IDCliente);
        Cliente Leer(int posicion);
        int CantidadRegistros();
        void Leer(int cantidadRegistros, Cliente *vector);
};