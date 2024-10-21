#include "archivo-composicion-factura.h"
#include <cstring>

ArchivoComposicionFactura::ArchivoComposicionFactura() {}

bool ArchivoComposicionFactura::Guardar(ComposicionFactura recurso){
    FILE *pArchivo = fopen(_nombreArchivo, "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&recurso, sizeof(recurso), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoComposicionFactura::Crear(){
    FILE *pArchivo = fopen(_nombreArchivo, "wb+");
    if(pArchivo == NULL){
        return false;
    }
    fclose(pArchivo);
    return true;
}

bool ArchivoComposicionFactura::Guardar(ComposicionFactura recurso, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(ComposicionFactura) * posicion, SEEK_SET);
    bool ok = fwrite(&recurso, sizeof(ComposicionFactura), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoComposicionFactura::Buscar(int nroFactura){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return -1;
    }
    ComposicionFactura recurso;
    int i = 0;
    while(fread(&recurso, sizeof(ComposicionFactura), 1, pArchivo)){
        if(recurso.getNroFactura() == nroFactura){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

ComposicionFactura ArchivoComposicionFactura::Leer(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return ComposicionFactura();
    }
    ComposicionFactura recurso;
    fseek(pArchivo, sizeof(ComposicionFactura) * posicion, SEEK_SET);
    fread(&recurso, sizeof(ComposicionFactura), 1, pArchivo);
    fclose(pArchivo);
    return recurso;
}

int ArchivoComposicionFactura::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(ComposicionFactura);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoComposicionFactura::Leer(int cantidadRegistros, ComposicionFactura *vector){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(ComposicionFactura), 1, pArchivo);
    }
    fclose(pArchivo);
}