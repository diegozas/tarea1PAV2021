#include "DtArribo.h"
DtArribo::DtArribo(){}
DtArribo::DtArribo(DtFecha fecha,float carga,DtBarco* barco){
    this->fecha=fecha;
    this->carga=carga;
    this->barco=barco;
}
DtFecha DtArribo::getFecha(){
    return this->fecha;
}
float DtArribo::getCarga(){
    return this->carga;
}
DtBarco* DtArribo::getBarco(){
    return this->barco;
}

DtArribo::~DtArribo(){}

ostream& operator<<(ostream& sal,const DtArribo& a){
    cout<<"Fecha de arribo: "<<a.fecha<<"Carga: "<<a.carga;
    return sal;
}
