#include "BarcoPesquero.h"
BarcoPesquero::BarcoPesquero(){}
BarcoPesquero::BarcoPesquero(string nombre,string id,int capacidad,int carga):Barco(nombre,id){
    this->capacidad=capacidad;
    this->carga=carga;
}
int BarcoPesquero::getCapacidad(){
    return this->capacidad;
}
int BarcoPesquero::getCarga(){
    return this->carga;
}
void BarcoPesquero::setCapacidad(int cap){
    this->capacidad=cap;
}
void BarcoPesquero::setCarga(int carga){
    this->carga=carga;
}
BarcoPesquero::~BarcoPesquero(){}

void BarcoPesquero::arribar(float cargaDespacho){
	this->carga=carga - cargaDespacho;
}

DtBarco* BarcoPesquero::getDtBarco(){
DtBarcoPesquero * dtp=new DtBarcoPesquero(this->getNombre(),
                                          this->getId(),
                                          this->getCapacidad(),
                                          this->getCarga());
	return dtp;
}
