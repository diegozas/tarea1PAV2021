#ifndef BARCOPASAJERO
#define BARCOPASAJERO   
#include "Barco.h"
#include "TipoTamanio.h"
#include "DtBarcoPasajero.h"
class BarcoPasajero:public Barco{
    private:
        int cantPasajeros;
        TipoTamanio tamanio;
    public:
        BarcoPasajero();
        BarcoPasajero(string,string,int,TipoTamanio);
        int getCantPasajeros();
        TipoTamanio getTamanio();
        void setCantPasajeros(int);
        void setTamanio(TipoTamanio);
        ~BarcoPasajero();
        void arribar(float);
        DtBarco* getDtBarco();
        
};
#endif