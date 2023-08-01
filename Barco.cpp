#include "Barco.h"
Barco::Barco(){}
Barco::Barco(string nombre,string id){
    this->nombre=nombre;
    this->id=id;
}
string Barco::getNombre(){
    return this->nombre;
}
string Barco::getId(){
    return this->id;
}
void Barco::setId(string id){
    this->id=id;
}
void Barco::setNombre(string nombre){
    this->nombre=nombre;
}
Barco::~Barco(){}
