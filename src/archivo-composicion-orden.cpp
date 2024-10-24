#include "../include/archivo-composicion-orden.h"

#include <cstring>

ArchivoComposicionOrden::ArchivoComposicionOrden() {}
bool ArchivoComposicionOrden::Guardar(ComposicionOrden recurso){
    FILE *pArchivo = fopen(_nombreArchivo, "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&recurso, sizeof(recurso), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoComposicionOrden::Crear(){
    FILE *pArchivo = fopen(_nombreArchivo, "wb+");
    if(pArchivo == NULL){
        return false;
    }
    fclose(pArchivo);
    return true;
}

bool ArchivoComposicionOrden::Guardar(ComposicionOrden recurso, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(ComposicionOrden) * posicion, SEEK_SET);
    bool ok = fwrite(&recurso, sizeof(ComposicionOrden), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoComposicionOrden::Buscar(std::string IdProducto){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return -1;
    }
    ComposicionOrden recurso;
    std::string id = recurso.getIdRecurso();
    int i = 0;
    while(fread(&recurso, sizeof(ComposicionOrden), 1, pArchivo)){
        if(id == IdProducto){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

ComposicionOrden ArchivoComposicionOrden::Leer(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return ComposicionOrden();
    }
    ComposicionOrden recurso;
    fseek(pArchivo, sizeof(ComposicionOrden) * posicion, SEEK_SET);
    fread(&recurso, sizeof(ComposicionOrden), 1, pArchivo);
    fclose(pArchivo);
    return recurso;
}

int ArchivoComposicionOrden::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(ComposicionOrden);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoComposicionOrden::Leer(int cantidadRegistros, ComposicionOrden *vector){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(ComposicionOrden), 1, pArchivo);
    }
    fclose(pArchivo);
}