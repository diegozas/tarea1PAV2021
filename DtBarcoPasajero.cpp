#include "DtBarcoPasajero.h"
DtBarcoPasajero::DtBarcoPasajero(){}
DtBarcoPasajero::DtBarcoPasajero(string nombre,string id,int cant,TipoTamanio tam):DtBarco(nombre,id){
    this->cantPasajeros=cant;
    this->tamanio=tam;
}
int DtBarcoPasajero::getCantPasajeros(){
    return this->cantPasajeros;
}
TipoTamanio DtBarcoPasajero::getTamanio(){
    return this->tamanio;
}
DtBarcoPasajero::~DtBarcoPasajero(){}

ostream& operator <<(ostream& sal,const DtBarcoPasajero& barco){
    string a [4]={"BOTE","CRUCERO","GALEON","TRANSATLANTICO"};
    cout<<(DtBarco) barco<<"Tipo de barco: Barco Pasajero"<<endl<<"Cantidad de pasajeros: "<<barco.cantPasajeros<<endl<<"Tamanio: "<<a[barco.tamanio]<<endl;
    return sal;
}
