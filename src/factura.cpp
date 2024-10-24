#include "../include/factura.h"

Factura::Factura(){
	Fecha fecha;

	_fecha = fecha;
	_tipoFactura = 'Z';
	_nroFactura = 0;
	_nroVenta = 0;
	_montoTotal = 0.0f;
}

Factura::Factura(Fecha fecha, char tipo,int nroFactura, int nroVenta, float monto){
   _fecha = fecha;
   _tipoFactura = tipo;
   _nroFactura = nroFactura;
   _nroVenta = nroVenta;
   _montoTotal = monto;
}

Fecha Factura::getFecha(){
   return _fecha;
}

void Factura::setFecha(Fecha f){
   _fecha = f;
}

int Factura::getNroFactura(){
   return _nroFactura;
}
void Factura::setNroFactura(int nroFactura){
   _nroFactura = nroFactura;
}
float Factura::getMontoTotal(){
   return _montoTotal;
}
void Factura::setMontoTotal(float monto){
   _montoTotal = monto;
}