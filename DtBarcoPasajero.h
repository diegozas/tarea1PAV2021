#ifndef DTBARCOPASAJERO
#define DTBARCOPASAJERO
#include "DtBarco.h"
#include "TipoTamanio.h"
class DtBarcoPasajero:public DtBarco{
    private:
        int cantPasajeros;
        TipoTamanio tamanio;
    public:
        DtBarcoPasajero();
        DtBarcoPasajero(string,string,int,TipoTamanio);
        int getCantPasajeros();
        TipoTamanio getTamanio();
        ~DtBarcoPasajero();
        friend ostream& operator <<(ostream&,const DtBarcoPasajero&);
};





#endif
