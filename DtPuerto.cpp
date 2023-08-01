#include "DtPuerto.h"
DtPuerto::DtPuerto(){}
DtPuerto::DtPuerto(string id,string nombre,DtFecha fecha,int cant){
    this->id=id;
    this->nombre=nombre;
    this->fechaCreacion=fecha;
    this->cantArribos=cant;
}
string DtPuerto::getId(){
    return this->id;
}
string DtPuerto::getNombre(){
    return this->nombre;
}
DtFecha DtPuerto::getFecha(){
    return this->fechaCreacion;
}
int DtPuerto::getArribos(){
    return this->cantArribos;
}


DtPuerto::~DtPuerto(){}


ostream& operator<<(ostream& sal,DtPuerto& dt){
    cout<<"Id: "<<dt.id<<endl<<"Nombre: "<<dt.nombre<<endl<<"Fecha de creacion: "<<dt.fechaCreacion<<"Cantidad de arribos: "<<dt.cantArribos<<endl;
    return sal;
}
