#pragma once
#include <string>
#include "composicion-orden.h"

class ArchivoComposicionOrden {
private:
    const char* _nombreArchivo = "db/composicion-producto.dat";

public:
    ArchivoComposicionOrden();
    bool Crear();
    bool Guardar(ComposicionOrden composicion);
    bool Guardar(ComposicionOrden composicion, int posicion);
    int Buscar(std::string idProducto);
    ComposicionOrden Leer(int posicion);
    int CantidadRegistros();
    void Leer(int cantidadRegistros, ComposicionOrden* vector);
};
