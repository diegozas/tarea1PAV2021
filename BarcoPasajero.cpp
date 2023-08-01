#include "BarcoPasajero.h"
BarcoPasajero::BarcoPasajero(){}
BarcoPasajero::BarcoPasajero(string nombre,string id,int cant,TipoTamanio tamanio):Barco(nombre,id){
    this->cantPasajeros=cant;
    this->tamanio=tamanio;
}
int BarcoPasajero::getCantPasajeros(){
    return this->cantPasajeros;
}
TipoTamanio BarcoPasajero::getTamanio(){
    return this->tamanio;
}
void BarcoPasajero::setCantPasajeros(int pasajeros){
    this->cantPasajeros=pasajeros;
}
void BarcoPasajero::setTamanio(TipoTamanio tamanio){
    this->tamanio=tamanio;
}
BarcoPasajero::~BarcoPasajero(){}

void BarcoPasajero::arribar(float cargaDespacho){}

DtBarco* BarcoPasajero::getDtBarco(){
DtBarcoPasajero * dtp=new DtBarcoPasajero(this->getNombre(),
                                          this->getId(),
                                          this->getCantPasajeros(),
                                          this->getTamanio());
return dtp;
}