#ifndef DTBARCOPESQUERO
#define DTBARCOPESQUERO
#include "DtBarco.h"
class DtBarcoPesquero:public DtBarco{
    private:
        int capacidad;
        int carga;
    public:
        DtBarcoPesquero();
        DtBarcoPesquero(string,string,int,int);
        int getCapacidad();
        int getCarga();
        ~DtBarcoPesquero();
        friend ostream& operator <<(ostream&,const DtBarcoPesquero&);
};


#endif
