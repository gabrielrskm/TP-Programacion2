#include "../include/archivo-orden-produccion.h"

ArchivoOrdenProduccion::ArchivoOrdenProduccion(){

}

bool ArchivoOrdenProduccion::Crear(){
    FILE *pArchivo = fopen(_nombreArchivo, "wb+");
    if(pArchivo == NULL){
        return false;
    }
    fclose(pArchivo);
    return true;
}

bool ArchivoOrdenProduccion::Guardar(OrdenProduccion orden){
    FILE *pArchivo = fopen(_nombreArchivo, "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&orden, sizeof(orden), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoOrdenProduccion::Guardar(OrdenProduccion orden, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(OrdenProduccion) * posicion, SEEK_SET);
    bool ok = fwrite(&orden, sizeof(OrdenProduccion), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoOrdenProduccion::Buscar(std::string IdProducto){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return -1;
    }
    OrdenProduccion orden;
    int i = 0;
    while(fread(&orden, sizeof(OrdenProduccion), 1, pArchivo)){
        if(orden.getIdProducto() == IdProducto){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

OrdenProduccion ArchivoOrdenProduccion::Leer(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return OrdenProduccion();
    }
    OrdenProduccion orden;
    fseek(pArchivo, sizeof(OrdenProduccion) * posicion, SEEK_SET);
    fread(&orden, sizeof(OrdenProduccion), 1, pArchivo);
    fclose(pArchivo);
    return orden;
}

int ArchivoOrdenProduccion::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(OrdenProduccion);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoOrdenProduccion::Leer(int cantidadRegistros, OrdenProduccion *vector){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(OrdenProduccion), 1, pArchivo);
    }
    fclose(pArchivo);
}

