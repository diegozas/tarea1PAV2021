#include "Puerto.h"
#include <iostream>
using namespace std;
Puerto::Puerto(){}
Puerto::Puerto(string id,string nombre,DtFecha fecha){
    this->id=id;
    this->nombre=nombre;
    this->fechaCreacion=fecha;
    this->topeArribo=0;

    
}
string Puerto::getId(){
    return this->id;
}

string Puerto::getNombre(){
    return this->nombre;
}

DtFecha Puerto::getFecha(){
    return this->fechaCreacion;
}
int Puerto::getCantArribos(){
    return this->topeArribo;
}
void Puerto::setId(string id){
    this->id=id;
}

void Puerto::setNombre(string nombre){
    this->nombre=nombre;
}

void Puerto::setFecha(DtFecha fecha){
    this->fechaCreacion=fecha;
}

Puerto::~Puerto(){}

void Puerto::agregarArribo(Arribo* arr){
    this->arribos[this->topeArribo]=arr;
    this->topeArribo++;
}

DtArribo** Puerto::getDtArribos(){
    DtArribo** dtArribos=new DtArribo*[this->topeArribo];
    for(int i=0;i<this->topeArribo;i++){
       DtArribo* dta =new DtArribo (this->arribos[i]->getFecha(),this->arribos[i]->getCarga(),this->arribos[i]->getDtBarco());
        dtArribos[i]=dta;
    }
    return dtArribos;
}

void Puerto::elminarArribos(DtFecha fecha){
    for(int i=0;i<this->topeArribo;i++){
        while(i<this->topeArribo && this->arribos[i]->getFecha()==fecha){
            this->arribos[i]=this->arribos[this->topeArribo-1];
            this->arribos[this->topeArribo-1]=NULL;
            delete this->arribos[this->topeArribo-1];
            this->topeArribo--;
        }
    }
}