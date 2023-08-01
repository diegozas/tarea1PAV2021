#include "Arribo.h"
Arribo::Arribo(){}
Arribo::Arribo(float carga,DtFecha fecha,Barco* barco){
    this->carga=carga;
    this->fecha=fecha;
    this->barco=barco;
}
float Arribo::getCarga(){
    return this->carga;
}
DtFecha Arribo::Arribo::getFecha(){
    return this->fecha;
}
void Arribo::setCarga(float carga){
    this->carga=carga;
}
void Arribo::setFecha(DtFecha){
    this->fecha=fecha;
}
Arribo::~Arribo(){}


void Arribo::setBarco(Barco* b){
    this->barco=b;
}
Barco* Arribo::getBarco(){
    return this->barco;
}

DtBarco* Arribo::getDtBarco(){
    return this->barco->getDtBarco();
}