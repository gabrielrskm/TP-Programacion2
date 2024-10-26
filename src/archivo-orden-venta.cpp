#include "../include/archivo-orden-venta.h"

ArchivoOrdenVenta::ArchivoOrdenVenta(){

}

bool ArchivoOrdenVenta::Crear(){
    FILE *pArchivo = fopen(_nombreArchivo, "wb+");
    if(pArchivo == NULL){
        return false;
    }
    fclose(pArchivo);
    return true;
}

bool ArchivoOrdenVenta::Guardar(OrdenVenta orden){
    FILE *pArchivo = fopen(_nombreArchivo, "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&orden, sizeof(orden), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoOrdenVenta::Guardar(OrdenVenta orden, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(OrdenVenta) * posicion, SEEK_SET);
    bool ok = fwrite(&orden, sizeof(OrdenVenta), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoOrdenVenta::Buscar(int IDCliente){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return -1;
    }
    OrdenVenta orden;
    int i = 0;
    while(fread(&orden, sizeof(OrdenVenta), 1, pArchivo)){
        if(orden.getIdCliente() == IDCliente){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

OrdenVenta ArchivoOrdenVenta::Leer(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return OrdenVenta();
    }
    OrdenVenta orden;
    fseek(pArchivo, sizeof(OrdenVenta) * posicion, SEEK_SET);
    fread(&orden, sizeof(OrdenVenta), 1, pArchivo);
    fclose(pArchivo);
    return orden;
}

int ArchivoOrdenVenta::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(OrdenVenta);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoOrdenVenta::Leer(int cantidadRegistros, OrdenVenta *vector){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(OrdenVenta), 1, pArchivo);
    }
    fclose(pArchivo);
}

