#ifndef BARCOPESQUERO
#define BARCOPESQUERO
#include "Barco.h"
#include "DtBarcoPesquero.h"
class BarcoPesquero:public Barco{
    private:
        int capacidad;
        int carga;
    public:
        BarcoPesquero();
        BarcoPesquero(string,string,int,int);
        int getCapacidad();
        int getCarga();
        void setCapacidad(int);
        void setCarga(int);
        ~BarcoPesquero();
        void arribar(float);

        DtBarco* getDtBarco();
};



#endif