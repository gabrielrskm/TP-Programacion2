#include "../include/archivo-composicion-producto.h"
#include <cstring>

ArchivoComposicionProducto::ArchivoComposicionProducto() {}

bool ArchivoComposicionProducto::Guardar(ComposicionProducto recurso){
    FILE *pArchivo = fopen(_nombreArchivo, "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&recurso, sizeof(recurso), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoComposicionProducto::Crear(){
    FILE *pArchivo = fopen(_nombreArchivo, "wb+");
    if(pArchivo == NULL){
        return false;
    }
    fclose(pArchivo);
    return true;
}

bool ArchivoComposicionProducto::Guardar(ComposicionProducto recurso, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(ComposicionProducto) * posicion, SEEK_SET);
    bool ok = fwrite(&recurso, sizeof(ComposicionProducto), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoComposicionProducto::Buscar(std::string IdProducto){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return -1;
    }
    ComposicionProducto recurso;
    std::string id = recurso.getIdProducto();
    int i = 0;
    while(fread(&recurso, sizeof(ComposicionProducto), 1, pArchivo)){
        if(id == IdProducto){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

ComposicionProducto ArchivoComposicionProducto::Leer(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return ComposicionProducto();
    }
    ComposicionProducto recurso;
    fseek(pArchivo, sizeof(ComposicionProducto) * posicion, SEEK_SET);
    fread(&recurso, sizeof(ComposicionProducto), 1, pArchivo);
    fclose(pArchivo);
    return recurso;
}

int ArchivoComposicionProducto::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(ComposicionProducto);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoComposicionProducto::Leer(int cantidadRegistros, ComposicionProducto *vector){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(ComposicionProducto), 1, pArchivo);
    }
    fclose(pArchivo);
}

void ArchivoComposicionProducto::LeerTodo(ComposicionProducto *vector, int &vectorSize){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(ComposicionProducto);
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(ComposicionProducto), 1, pArchivo);
    }
    fclose(pArchivo);
}