#include "archivo-composicion-movimiento.h"

#include <cstring>

ArchivoComposicionMovimientos::ArchivoComposicionMovimientos() {}
bool ArchivoComposicionMovimientos::Guardar(ComposicionMovimientos composicionM){
    FILE *pArchivo = fopen(_nombreArchivo, "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&composicionM, sizeof(composicionM), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}
bool ArchivoComposicionMovimientos::Crear(){
    FILE *pArchivo = fopen(_nombreArchivo, "wb+");
    if(pArchivo == NULL){
        return false;
    }
    fclose(pArchivo);
    return true;
}
bool ArchivoComposicionMovimientos::Guardar(ComposicionMovimientos composicionM, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(ComposicionMovimientos) * posicion, SEEK_SET);
    bool ok = fwrite(&composicionM, sizeof(ComposicionMovimientos), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoComposicionMovimientos::Buscar(int nroMovimiento){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return -1;
    }
    ComposicionMovimientos composicionM;
    int i = 0;
    while(fread(&composicionM, sizeof(ComposicionMovimientos), 1, pArchivo)){
        if(composicionM.getNroMovimiento() == nroMovimiento){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

ComposicionMovimientos ArchivoComposicionMovimientos::Leer(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return ComposicionMovimientos();
    }
    ComposicionMovimientos composicionM;
    fseek(pArchivo, sizeof(ComposicionMovimientos) * posicion, SEEK_SET);
    fread(&composicionM, sizeof(ComposicionMovimientos), 1, pArchivo);
    fclose(pArchivo);
    return composicionM;
}

int ArchivoComposicionMovimientos::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(ComposicionMovimientos);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoComposicionMovimientos::Leer(int cantidadRegistros, ComposicionMovimientos *vector){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(ComposicionMovimientos), 1, pArchivo);
    }
    fclose(pArchivo);
}