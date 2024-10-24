#include "../include/fecha.h"
#include <string>

Fecha::Fecha() {
   _dia = 1;
   _mes = 1;
   _anio = 2023;
};
Fecha::Fecha(int d, int m, int a) {
   if (validarFecha(d, m, a)) {
      _dia = d;
      _mes = m;
      _anio = a;
   } else {
      _dia = 1;
      _mes = 1;
      _anio = 2023;
   }
}

void Fecha::setDia(int d) {
   if (validarFecha(d, _mes, _anio)) {
      _dia = d;
   }
}

void Fecha::setMes(int m) {
   if (validarFecha(_dia, m, _anio)) {
      _mes = m;
   }
}

void Fecha::setAnio(int a) {
   if (a > 0) {
      _anio = a;
   }
}

int Fecha::getDia() { return _dia; }
int Fecha::getMes() { return _mes; }
int Fecha::getAnio() { return _anio; }

void Fecha::agregarDia() {
   if (esBisiesto(_mes) && _mes == 2 && _dia == 29) {
      _dia = 1;
      _mes++;
   }

   else if (_mes == 2 && _dia == 28) {
      _dia = 1;
      _mes++;
   }

   else if (_mes == 12 && _dia == 31) {
      _dia = 1;
      _mes = 1;
      _anio++;
   } else if (esMesGrande(_mes) && _dia == 31) {
      _dia = 1;
      _mes++;
   } else if (esMesChico(_mes) && _dia == 30) {
      _dia = 1;
      _mes++;
   } else {
      _dia++;
   }
}

void Fecha::restarDia() {
   if (esBisiesto(_anio) && _dia == 1 && _mes == 3) {
      _dia = 29;
      _mes--;
   }

   else if (_dia == 1 && _mes == 3) {
      _dia = 28;
      _mes--;
   }

   else if (_mes == 2 && _dia == 28) {
      _dia = 1;
      _mes++;
   }

   else if (_dia == 1 && _mes == 1) {
      _dia = 31;
      _mes = 12;
      _anio--;
   }

   else if (_dia == 1) {
      _dia = 1;
      _mes--;
   } else {
      _dia--;
   }
}

std::string Fecha::toString() {
   std::string d, m, a;
   if (_dia < 10) {
      d = "0" + std::to_string(_dia);
   } else {
      d = std::to_string(_dia);
   }
   if (_mes < 10) {
      m = "0" + std::to_string(_mes);
   } else {
      m = std::to_string(_mes);
   }
   a = std::to_string(_anio);
   return d + "/" + m + "/" + a;
}

void Fecha::agregarDias(int ds) {
   for (int i = 0; i < ds; i++) {
      agregarDia();
   }
}
bool Fecha::validarFecha(int d, int m, int a) {
   if (d <= 0 || m <= 0 || m > 12 || a < 1) {
      return false;
   }
   if (esBisiesto(a) && m == 2 && d <= 29) {
      return true;
   }
   if (m == 2 && d <= 28) {
      return true;
   }
   if (esMesGrande(m) && d <= 31) {
      return true;
   }
   if (esMesChico(m) && d <= 30) {
      return true;
   }
   return false;
}

bool Fecha::esMesGrande(int m) {
   if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)) {
      return true;
   }
   return false;
}

bool Fecha::esMesChico(int m) {
   if ((m == 4 || m == 6 || m == 9 || m == 11)) {
      return true;
   }
   return false;
}

bool Fecha::esBisiesto(int a) {
   if (a % 400 == 0 || (a % 4 == 0 && a % 100 != 0)) {
      return true;
   }
   return false;
}



