#include "DtBarcoPesquero.h"
DtBarcoPesquero::DtBarcoPesquero(){}
DtBarcoPesquero::DtBarcoPesquero(string nombre,string id,int capacidad,int carga):DtBarco(nombre,id){
    this->capacidad=capacidad;
    this->carga=carga;
    
}
int DtBarcoPesquero::getCapacidad(){
    return this->capacidad;
}
int DtBarcoPesquero::getCarga(){
    return this->carga;
}

DtBarcoPesquero::~DtBarcoPesquero(){}

ostream& operator <<(ostream& sal, const DtBarcoPesquero& barco){
    cout<<(DtBarco) barco <<"Tipo de barco: Barco Pesquero"<<endl<<"Capacidad: "<< barco.capacidad<<endl<<"Carga: "<<barco.carga<<endl; 
    return sal;
}
