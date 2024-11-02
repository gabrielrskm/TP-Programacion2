#include "../include/archivo-recursos.h"

#include <cstring>

ArchivoRecurso::ArchivoRecurso() {}

bool ArchivoRecurso::Crear(){
    FILE *pArchivo = fopen(_nombreArchivo, "wb+");
    if(pArchivo == NULL){
        return false;
    }
    fclose(pArchivo);
    return true;
}

bool ArchivoRecurso::Guardar(Recurso recurso){
    FILE *pArchivo = fopen(_nombreArchivo, "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&recurso, sizeof(recurso), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoRecurso::Guardar(Recurso recurso, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(Recurso) * posicion, SEEK_SET);
    bool ok = fwrite(&recurso, sizeof(Recurso), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoRecurso::Buscar(std::string IdRecurso){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return -1;
    }
    Recurso recurso;
    int i = 0;
    while(fread(&recurso, sizeof(Recurso), 1, pArchivo)){
        if(recurso.getCodigo() == IdRecurso){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

Recurso ArchivoRecurso::Leer(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return Recurso();
    }
    Recurso recurso;
    fseek(pArchivo, sizeof(Recurso) * posicion, SEEK_SET);
    fread(&recurso, sizeof(Recurso), 1, pArchivo);
    fclose(pArchivo);
    return recurso;
}

int ArchivoRecurso::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Recurso);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoRecurso::Leer(int cantidadRegistros, Recurso *vector){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Recurso), 1, pArchivo);
    }
    fclose(pArchivo);
}