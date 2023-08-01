#ifndef DTARRIBO
#define DTARRIBO
#include "DtFecha.h"
#include "DtBarco.h"
#include <iostream>
using namespace std;
class DtArribo{
    private:
        DtFecha fecha;
        float carga;
        DtBarco* barco;
    public:
        DtArribo();
        DtArribo(DtFecha,float,DtBarco*);
        DtFecha getFecha();
        float getCarga();
        DtBarco* getBarco();
        ~DtArribo();
        friend ostream& operator<<(ostream&,const DtArribo&);



};



#endif
