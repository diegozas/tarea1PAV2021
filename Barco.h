#ifndef BARCO
#define BARCO
#include <string>
#include "DtBarco.h"
using namespace std;

class Barco{
    private:
        string nombre;
        string id;
    public:
        Barco();
        Barco(string,string);
        string getNombre();
        string getId();
        void setId(string);
        void setNombre(string);
        ~Barco();
        virtual void arribar(float)=0;

        virtual DtBarco* getDtBarco()=0;
};

#endif