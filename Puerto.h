#ifndef PUERTO
#define PUERTO  
#include <string>
#include "DtFecha.h"
#include "Arribo.h"
#include "DtArribo.h"
#define MAX_ARRIBOS 30
using namespace std;

class Puerto{
    private:
        string id;
        string nombre;
        DtFecha fechaCreacion;
        //Pseudo Atributo
        Arribo* arribos[MAX_ARRIBOS];
        int topeArribo;
    public:
        Puerto();
        Puerto(string,string,DtFecha);
        string getId();
        string getNombre();
        DtFecha getFecha();
        void setId(string);
        void setNombre(string);
        void setFecha(DtFecha);
        ~Puerto();

        int getCantArribos();
        void agregarArribo(Arribo*);

        DtArribo** getDtArribos();
        void elminarArribos(DtFecha);
};







#endif