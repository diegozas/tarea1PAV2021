#include "DtFecha.h"
DtFecha::DtFecha(){}
DtFecha::DtFecha(int dia,int mes ,int anio){
    this->dia=dia;
    this->mes=mes;
    this->anio=anio;
}
int DtFecha::getDia(){
    return this->dia;
}
int DtFecha::getMes(){
    return this->mes;
}
int DtFecha::getAnio(){
    return this->anio;
}

ostream& operator << (ostream& salida,const DtFecha fecha){
    cout << fecha.dia << "/" <<fecha.mes << "/" << fecha.anio<<endl;
    return salida;
}

bool operator == (const DtFecha& f1,const DtFecha f2){
    return f1.dia==f2.dia && f1.mes==f2.mes && f1.anio==f2.anio;
}