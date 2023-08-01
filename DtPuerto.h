#ifndef DTPUERTO
#define DTPUERTO
#include <string>
#include "DtFecha.h"
#include <iostream>
using namespace std;

class DtPuerto{
    private:
        string id;
        string nombre;
        DtFecha fechaCreacion;
        int cantArribos;
    public:
        DtPuerto();
        DtPuerto(string,string,DtFecha,int);
        string getId();
        string getNombre();
        DtFecha getFecha();
        int getArribos();
        ~DtPuerto();

        friend ostream& operator<<(ostream&,DtPuerto&);
};


#endif
