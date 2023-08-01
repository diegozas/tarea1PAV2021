#include "DtBarco.h"
DtBarco::DtBarco(){}
DtBarco::DtBarco(string nombre,string id){
    this->nombre=nombre;
    this->id=id;
}
string DtBarco::getNombre(){
    return this->nombre;
}
string DtBarco::getId(){
    return this->id;
}
DtBarco::~DtBarco(){}

ostream& operator <<(ostream& salida,const DtBarco& barco){
    cout<<"Id barco: "<<barco.id<<endl<<"Nombre: "<<barco.nombre<<endl;
    return salida;

}
