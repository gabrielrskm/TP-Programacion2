#include "../include/archivo-factura.h"

ArchivoFactura::ArchivoFactura(){

}

bool ArchivoFactura::Crear(){
    FILE *pArchivo = fopen(_nombreArchivo, "wb+");
    if(pArchivo == NULL){
        return false;
    }
    fclose(pArchivo);
    return true;
}

bool ArchivoFactura::Guardar(Factura factura){
    FILE *pArchivo = fopen(_nombreArchivo, "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&factura, sizeof(factura), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoFactura::Guardar(Factura factura, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(Factura) * posicion, SEEK_SET);
    bool ok = fwrite(&factura, sizeof(Factura), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoFactura::Buscar(int nroFactura){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return -1;
    }
    Factura factura;
    int i = 0;
    while(fread(&factura, sizeof(Factura), 1, pArchivo)){
        if(factura.getNroFactura() == nroFactura){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

Factura ArchivoFactura::Leer(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return Factura();
    }
    Factura factura;
    fseek(pArchivo, sizeof(Factura) * posicion, SEEK_SET);
    fread(&factura, sizeof(Factura), 1, pArchivo);
    fclose(pArchivo);
    return factura;
}

int ArchivoFactura::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Factura);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoFactura::Leer(int cantidadRegistros, Factura *vector){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Factura), 1, pArchivo);
    }
    fclose(pArchivo);
}

