#ifndef DTBARCO
#define DTBARCO
#include <string>
#include <iostream>
using namespace std;
class DtBarco{
    private:
        string nombre;
        string id;
    public:
        DtBarco();
        DtBarco(string,string);
        string getNombre();
        string getId();
        virtual ~DtBarco();
        friend ostream& operator <<(ostream&,const DtBarco&);
};


#endif
