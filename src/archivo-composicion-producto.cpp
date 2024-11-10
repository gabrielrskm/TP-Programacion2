#include "../include/archivo-composicion-producto.h"

#include <cstring>

ArchivoComposicionProducto::ArchivoComposicionProducto() {
}

bool ArchivoComposicionProducto::Guardar(ComposicionProducto recurso) {
   FILE *pArchivo = fopen(_nombreArchivo, "ab");
   if (pArchivo == NULL) {
      return false;
   }
   bool ok = fwrite(&recurso, sizeof(recurso), 1, pArchivo);
   fclose(pArchivo);
   return ok;
}

bool ArchivoComposicionProducto::Crear() {
   FILE *pArchivo = fopen(_nombreArchivo, "wb+");
   if (pArchivo == NULL) {
      return false;
   }
   fclose(pArchivo);
   return true;
}

bool ArchivoComposicionProducto::Guardar(ComposicionProducto recurso, int posicion) {
   FILE *pArchivo = fopen(_nombreArchivo, "rb+");
   if (pArchivo == NULL) {
      return false;
   }
   fseek(pArchivo, sizeof(ComposicionProducto) * posicion, SEEK_SET);
   bool ok = fwrite(&recurso, sizeof(ComposicionProducto), 1, pArchivo);
   fclose(pArchivo);
   return ok;
}

int ArchivoComposicionProducto::Buscar(std::string idRef) {
   FILE *pArchivo = fopen(_nombreArchivo, "rb");
   if (pArchivo == NULL) {
      return -1;
   }
   ComposicionProducto composicion;
   int i = 0;
   while (fread(&composicion, sizeof(ComposicionProducto), 1, pArchivo)) {
      if (composicion.getId() == idRef) {
         fclose(pArchivo);
         return i;
      }
      i++;
   }
   fclose(pArchivo);
   return -1;
}

ComposicionProducto ArchivoComposicionProducto::Leer(int posicion) {
   FILE *pArchivo = fopen(_nombreArchivo, "rb");
   if (pArchivo == NULL) {
      return ComposicionProducto();
   }
   ComposicionProducto recurso;
   fseek(pArchivo, sizeof(ComposicionProducto) * posicion, SEEK_SET);
   fread(&recurso, sizeof(ComposicionProducto), 1, pArchivo);
   fclose(pArchivo);
   return recurso;
}

int ArchivoComposicionProducto::CantidadRegistros() {
   FILE *pArchivo = fopen(_nombreArchivo, "rb");
   if (pArchivo == NULL) {
      return 0;
   }
   fseek(pArchivo, 0, SEEK_END);
   int cantidadRegistros = ftell(pArchivo) / sizeof(ComposicionProducto);
   fclose(pArchivo);
   return cantidadRegistros;
}


void ArchivoComposicionProducto::LeerTodo(ComposicionProducto *&vector, int &vectorSize) {
   FILE *pArchivo = fopen(_nombreArchivo, "rb");
   if (pArchivo == NULL) {
      vectorSize = 0;
      return;
   }
   fseek(pArchivo, 0, SEEK_END);
   int cantidadRegistros = ftell(pArchivo) / sizeof(ComposicionProducto);
   vectorSize = cantidadRegistros;
   if (cantidadRegistros < 1) {
      fclose(pArchivo);
      return;
   }
   vector = new ComposicionProducto[cantidadRegistros];
   fseek(pArchivo, 0, SEEK_SET);
   for (int i = 0; i < cantidadRegistros; i++) {
      fread(&vector[i], sizeof(ComposicionProducto), 1, pArchivo);
   }
   fclose(pArchivo);
}