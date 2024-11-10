#pragma once
#include <string>
#include "composicion-producto.h"

class ArchivoComposicionProducto {
private:
    const char* _nombreArchivo = "db/composicion-producto.dat";

public:
    ArchivoComposicionProducto();
    bool Crear();
    bool Guardar(ComposicionProducto composicion);
    bool Guardar(ComposicionProducto composicion, int posicion);
    int Buscar(std::string idProducto);
    ComposicionProducto Leer(int posicion);
    int CantidadRegistros();
    void Leer(int cantidadRegistros, ComposicionProducto* vector);
    void LeerTodo(ComposicionProducto*& vector, int& vectorSize);
};
