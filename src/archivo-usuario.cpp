#include "../include/archivo-usuario.h"

ArchivoUsuario::ArchivoUsuario(){
}
bool ArchivoUsuario::Crear(){
    FILE *pArchivo = fopen(_nombreArchivo, "wb+");
    if(pArchivo == NULL){
        return false;
    }
    fclose(pArchivo);
    return true;
}
bool ArchivoUsuario::Guardar(Usuario usuario){
    FILE *pArchivo = fopen(_nombreArchivo, "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&usuario, sizeof(usuario), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoUsuario::Guardar(Usuario usuario, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(Usuario) * posicion, SEEK_SET);
    bool ok = fwrite(&usuario, sizeof(Usuario), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoUsuario::Buscar(std::string _nombreUsuario){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return -1;
    }
    Usuario usuario;
    int i = 0;
    while(fread(&usuario, sizeof(Usuario), 1, pArchivo)){
        if(usuario.getNombreUsuario() == _nombreUsuario){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

Usuario ArchivoUsuario::Leer(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return Usuario();
    }
    Usuario usuario;
    fseek(pArchivo, sizeof(Usuario) * posicion, SEEK_SET);
    fread(&usuario, sizeof(Usuario), 1, pArchivo);
    fclose(pArchivo);
    return usuario;
}

int ArchivoUsuario::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Usuario);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoUsuario::Leer(int cantidadRegistros, Usuario *vector){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Usuario), 1, pArchivo);
    }
    fclose(pArchivo);
}

Usuario* ArchivoUsuario::LeerTodos(){
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == NULL){
        return nullptr;
    }
    fseek(pArchivo, 0, SEEK_END);
    int tamanoArchivo = ftell(pArchivo);
    int cantidadRegistros = tamanoArchivo / sizeof(Usuario);
    
    if (tamanoArchivo % sizeof(Usuario) != 0) {
        fclose(pArchivo);
        cantidadRegistros = 0;
        return nullptr;
    }
    Usuario *vector = new Usuario[cantidadRegistros];
    if(vector == NULL){
        fclose(pArchivo);
        return nullptr;
    }

    fseek(pArchivo, 0, SEEK_SET);
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Usuario), 1, pArchivo);
    }
    fclose(pArchivo);
    return vector;
}

