#include "archivo-proveedor.h"

ArchivoProveedor::ArchivoProveedor(){

}

bool ArchivoProveedor::Crear(){
    FILE *pArchivo = fopen(_nombreArchivo, "wb+");
    if(pArchivo == NULL){
        return false;
    }
    fclose(pArchivo);
    return true;
}

bool ArchivoProveedor::Guardar(Proveedor proveedor){
    FILE *pArchivo = fopen(_nombreArchivo, "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&proveedor, sizeof(proveedor), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoProveedor::Guardar(Proveedor proveedor, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(Proveedor) * posicion, SEEK_SET);
    bool ok = fwrite(&proveedor, sizeof(Proveedor), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoProveedor::Buscar(int IDCliente){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return -1;
    }
    Proveedor proveedor;
    int i = 0;
    while(fread(&proveedor, sizeof(Proveedor), 1, pArchivo)){
        if(proveedor.getId() == IDCliente){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

Proveedor ArchivoProveedor::Leer(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return Proveedor();
    }
    Proveedor proveedor;
    fseek(pArchivo, sizeof(Proveedor) * posicion, SEEK_SET);
    fread(&proveedor, sizeof(Proveedor), 1, pArchivo);
    fclose(pArchivo);
    return proveedor;
}

int ArchivoProveedor::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Proveedor);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoProveedor::Leer(int cantidadRegistros, Proveedor *vector){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Proveedor), 1, pArchivo);
    }
    fclose(pArchivo);
}

