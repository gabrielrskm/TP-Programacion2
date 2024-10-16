#pragma once
#include <string>
#include "cliente.h"

class ArchivoCliente{
    private:
        const char * _nombreArchivo  = "Cliente.dat";
        
    public:
        ArchivoCliente();
        bool Guardar(Cliente cliente);
        bool Guardar(Cliente cliente, int posicion);
        int Buscar(std::string IDCliente);
        Cliente Leer(int posicion);
        int CantidadRegistros();
        void Leer(int cantidadRegistros, Cliente *vector);
};