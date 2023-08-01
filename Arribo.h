#ifndef ARRIBO
#define ARRIBO
#include "DtFecha.h"
#include "Barco.h"
#include "DtBarco.h"
class Arribo{
    private:
        float carga;
        DtFecha fecha;
        //Link a Barco
        Barco* barco;

    public:
        Arribo();
        Arribo(float,DtFecha,Barco*);
        float getCarga();
        DtFecha getFecha();
        void setCarga(float);
        void setFecha(DtFecha);
        void setBarco(Barco*);
        Barco* getBarco();
        ~Arribo();

        DtBarco* getDtBarco();

};





#endif