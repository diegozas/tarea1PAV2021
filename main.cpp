#include "DtFecha.h"
#include "Puerto.h"
#include "BarcoPesquero.h"
#include "BarcoPasajero.h"
#include "Barco.h"
#include "Arribo.h"
#include "TipoTamanio.h"
#include "DtBarco.h"
#include "DtArribo.h"
#include "DtPuerto.h"
#include "DtBarcoPesquero.h"
#include "DtBarcoPasajero.h"
#include <iostream>
#include <unistd.h>
#include <string.h>
#define MAX_PUERTOS 50
#define MAX_BARCOS 50
//Todos los puertos del sistema
struct Puertos{
    Puerto * p[MAX_PUERTOS];
    int topePuerto;
}colPuertos;

//Todos los barcos del sistema
struct Barcos{
    Barco* b[MAX_BARCOS];
    int topeBarco;
}colBarcos;
//Operaciones a implementar

//Operacion A
void menuAgregarPuerto();
void agregarPuerto(string,string,DtFecha);

//Operacion B
void menuAgregarBarco();
void agregarBarco(DtBarco&);

//Operacion C
void listarPuertos();
DtPuerto** listarPuertos(int&);

//Operacion D
void agregarArribos();
void agregarArribo(string,string,DtFecha,float);


//Operacion E
void listarArribos();
DtArribo** obtenerInfoArribosEnPuerto(string,int&);


//Operacion F
void menuEliminarArribos();
void eliminarArribos(string,DtFecha);


//Operacion G
void listarBarcos();
DtBarco** listarBarcos(int&);




//Operaciones auxiliares
void existePuerto(string);
void existeBarco(string);
void noExistePuerto(string);
void noExisteBarco(string);
void diaCorrecto(int);
void mesCorrecto(int,int);
void anioCorrecto(int,int,int);
void cargarDatos();
Puerto* obtenerPuerto(string);
Barco* obtenerBarco(string);
void controlarCarga(string,float);
void tieneArribos(string);
void controlFecha(int,int,int);

//Operacion A
void menuAgregarPuerto(){
    system("clear");
    cout<<"______________________________________________"<<endl;
    cout <<"____R E G I S T R O__D E__P U E R T O_________"<< endl; 
    string id,nombre;
    int dia,mes,anio;
    DtFecha fecha;
    try{
        cout<<"Id del puerto: ";
        cin>>id;
        existePuerto(id);
        try{
            cout<<"Nombre del Puerto: ";
            cin>>nombre;
            cout<<"Fecha de creacion"<<endl;
            cout<<"Dia: ";
            cin>>dia;
            diaCorrecto(dia);
            try{
                cout<<"Mes: ";
                cin>>mes;
                mesCorrecto(mes,dia);
                try{
                    cout<<"Anio: ";
                    cin>>anio;
                    anioCorrecto(anio,mes,dia);
                    fecha= DtFecha(dia,mes,anio);
                    agregarPuerto(id,nombre,fecha);
                    cout<<"Se agrego el Puerto de id "<<id<<" correctamente"<<endl;
                    cout<<"Presione enter para continuar"<<endl;
                    system("read X");

                }catch(invalid_argument& e){
                    cout<<e.what();
                    cout<<"Presione enter para continuar"<<endl;
                    system("read X");
                    }

            }catch(invalid_argument& e){
                cout<<e.what();
                cout<<"Presione enter para continuar"<<endl;
                system("read X");
            }
            
            
        }catch(invalid_argument& error){
            cout<<error.what();
            cout<<"Presione enter para continuar"<<endl;
            system("read X");
        }
      
    }catch(invalid_argument& e){
        cout<<e.what();
        cout<<"Presione enter para continuar"<<endl;
        system("read X");
    }   
}
void agregarPuerto(string id,string nombre,DtFecha fechaCreacion){
    Puerto * p= new Puerto(id,nombre,fechaCreacion);
    colPuertos.p[colPuertos.topePuerto]=p;
    colPuertos.topePuerto++;
}
//Operacion B
void menuAgregarBarco(){
    system("clear");
    string nombre,id;
    TipoTamanio tamanio;
    int capacidad,carga,cantPasajeros;
    DtBarcoPesquero dtPesquero;
    DtBarcoPasajero dtPasajeros;
    cout<<"Ingrese el nombre del barco: ";
    cin>>nombre;
    cout<<endl<<"Ingrese el id: ";
    cin>>id;
    try{
        existeBarco(id);
        int opBarco,opTipo;
        cout<<endl<<"Ingrese el tipo de barco"<<endl;
        cout<<endl<<"1-Pesquero"<<endl;
        cout<<endl<<"2-Pasajeros"<<endl;
        cin>>opTipo;
        switch(opTipo){
            case 1:cout<<"Ingrese la capacidad: ";
                    cin>>capacidad;
                    cout<<endl<<"Ingrese la carga: ";
                    cin>>carga;
                    dtPesquero=DtBarcoPesquero(nombre,id,capacidad,carga);
                    agregarBarco(dtPesquero);
                    break;
            case 2: cout<<"Ingrese cantidad de pasajeros: ";
                    cin>>cantPasajeros;
                    cout<<endl<<"Ingrese el tipo de barco"<<endl;
                    cout<<"1-Bote"<<endl;
                    cout<<"2-Crucero"<<endl;
                    cout<<"3-Galeon"<<endl;
                    cout<<"4-Transatlantico"<<endl;
                    cin>>opTipo;
                    switch(opTipo){
                        case 1: tamanio=BOTE;
                                break;
                        case 2: tamanio=CRUCERO;
                                break;
                        case 3: tamanio=GALEON;
                                break;
                        case 4: tamanio=TRANSATLANTICO; 
                                break;
                    }
                    dtPasajeros=DtBarcoPasajero(nombre,id,cantPasajeros,tamanio);
                    agregarBarco(dtPasajeros);
                    break;
        }
        cout<<endl<<"BARCO REGISTRADO"<<endl;
        cout << "\nPulse enter para continuar"<<endl;
        system("read X");
    }catch(invalid_argument &e){
        cout<<e.what()<<endl;
        cout<<"Presione enter para continuar"<<endl;
        system("read X");
    }
}

void agregarBarco(DtBarco& barco){
    try{
        DtBarcoPasajero& b= dynamic_cast<DtBarcoPasajero&>(barco);
        BarcoPasajero* b1= new BarcoPasajero (b.getNombre(),b.getId(),b.getCantPasajeros(),b.getTamanio());
        colBarcos.b[colBarcos.topeBarco]=b1;
        colBarcos.topeBarco++;
    }catch(bad_cast){
        try{
            DtBarcoPesquero& b1= dynamic_cast<DtBarcoPesquero&>(barco);
            BarcoPesquero* b= new BarcoPesquero(b1.getNombre(),b1.getId(),b1.getCapacidad(),b1.getCarga());
            colBarcos.b[colBarcos.topeBarco]=b;
            colBarcos.topeBarco++;

        }catch(bad_cast){}
    }
}
//Operacion C
void listarPuertos(){
    system("clear");
    cout<<"____Listando los puertos del sistema____"<<endl;
    int puerto;
    DtPuerto** puertos=listarPuertos(puerto);
    for(int i=0;i<puerto;i++){
        cout<<*puertos[i]<<endl;
    }
    cout<<"Presione enter para continuar"<<endl;
    system("read X");
}
DtPuerto** listarPuertos(int& cantPuertos){
    cantPuertos=colPuertos.topePuerto;
    DtPuerto** lista= new DtPuerto* [cantPuertos];
    for(int i=0;i<cantPuertos;i++){
        DtPuerto* dtp=new DtPuerto(colPuertos.p[i]->getId(),
                                   colPuertos.p[i]->getNombre(),
                                   colPuertos.p[i]->getFecha(),
                                   colPuertos.p[i]->getCantArribos());
        lista[i]=dtp;
    }
    return lista;
}

//Operacion D
void agregarArribos(){
    system("clear");
    string idPuerto,idBarco;
    int dia,mes,anio;
    DtFecha fecha;
    float cargaDespacho;
    cout<<"Ingrese el id del puerto: "<<endl;
    cin>>idPuerto;
    try{
        noExistePuerto(idPuerto);
        cout<<"Ingrese id del barco: "<<endl;
        cin>>idBarco;
        try{
            noExisteBarco(idBarco);
            cout<<"ingrese el dia: "<<endl;
            cin>>dia;
            cout<<"ingrese el mes: "<<endl;
            cin>>mes;
            cout<<"Ingrese el anio: "<<endl;
            cin>>anio;
            try{
                controlFecha(dia,mes,anio);
                fecha=DtFecha(dia,mes,anio);
                cout<<"Ingrese la carga: "<<endl;
                cin>>cargaDespacho;               
                try{
                    controlarCarga(idBarco,cargaDespacho);
                    try{
                        agregarArribo(idPuerto,idBarco,fecha,cargaDespacho);
                        cout<<"ARRIBO AGREGADO..\n Presione enter para continuar\n";
                    	system("read X");
                    }catch(invalid_argument &e){
                        cout<<e.what()<<endl;
                        cout<<"Presione enter para continuar"<<endl;
                    	system("read X");
                    }                    
                }catch(invalid_argument &e){
                   cout<<e.what()<<endl;
                    cout<<"Presione enter para continuar"<<endl;
                    system("read X");
                } 
            }catch(invalid_argument &e){
                cout<<e.what()<<endl;
                cout<<"Presione enter para continuar"<<endl;
                system("read X");
            }            
        }catch(invalid_argument &e){
            cout<<e.what()<<endl;
            cout<<"Presione enter para continuar"<<endl;
            system("read X");
        }
    }catch(invalid_argument &e){
        cout<<e.what()<<endl;
        cout<<"Presione enter para continuar"<<endl;
        system("read X");
    }
}

void agregarArribo(string idPuerto,string idBarco,DtFecha fecha,float cargaDespacho){
    Puerto * puerto=obtenerPuerto(idPuerto);
    Barco * barco=obtenerBarco(idBarco);
    Arribo*arribo=new Arribo(cargaDespacho,fecha,barco);
    puerto->agregarArribo(arribo);
    if(BarcoPesquero * pesquero=dynamic_cast<BarcoPesquero*>(barco)){
        pesquero->arribar(cargaDespacho);
	}
}

//Operacion E
void listarArribos(){
    system("clear");
    string id;
    cout<<"Id del puerto: ";
    cin>>id;
    try{
        noExistePuerto(id);
        try{
            tieneArribos(id);
            int arribo;
            DtArribo** arribos=obtenerInfoArribosEnPuerto(id,arribo);
            DtBarcoPasajero* dtb;
            DtBarcoPesquero* dtb1;
            cout<<"_______Listando los arribos del puerto: "<<id<<"__________"<<endl;
            for(int i=0;i<arribo;i++){
                if(dtb=dynamic_cast<DtBarcoPasajero*>(arribos[i]->getBarco())){
                    cout<<*arribos[i]<<endl<<*dtb;    
                    cout<<endl;
                }else if(dtb1=dynamic_cast<DtBarcoPesquero*>(arribos[i]->getBarco())){
                    cout<<*arribos[i]<<endl<<*dtb1;
                    cout<<endl;
                }
            }
        }catch(invalid_argument& e){
            cout<<e.what();
        }

    }catch(invalid_argument& e){
        cout<<e.what();
        cout<<"Presione enter para continuar"<<endl;
        system("read X");
    }
    cout<<"Presione enter para continuar"<<endl;
    system("read X");  
}
DtArribo** obtenerInfoArribosEnPuerto(string idPuerto,int& cantArribos){
    Puerto*p = obtenerPuerto(idPuerto);
	cantArribos = p->getCantArribos();
    DtArribo** arribo = p->getDtArribos();
    return arribo;
}



void menuEliminarArribos(){
    system("clear");
    cout<<"______Eliminar arribos de un puerto______"<<endl;
    string id;
    DtFecha fecha;
    int dia,mes,anio;
    cout<<"Id del puerto: ";
    cin>>id;
    try{
        noExistePuerto(id);
        cout<<"Fecha de los arribos que quiere eliminar"<<endl;
        cout<<"Dia: ";
        cin>>dia;
        cout<<"Mes: ";
        cin>>mes;
        cout<<"Anio: ";
        cin>>anio;
        fecha=DtFecha(dia,mes,anio);
        eliminarArribos(id,fecha);
        cout<<"Se elimino los arribos del puerto "<<id<<" con fecha: "<<fecha;
         cout<<"Presione enter para continuar"<<endl;
         system("read X");
    }catch(invalid_argument& e){
        cout<<e.what();
        cout<<"Presione enter para continuar"<<endl;
        system("read X");
    }
}
void eliminarArribos(string idPuerto,DtFecha fecha){
	Puerto*p=obtenerPuerto(idPuerto);
    p->elminarArribos(fecha);
}


//Operacion G
void listarBarcos(){
    system("clear");
    cout<<"______Listando los barcos del sistema______\n"<<endl;
    int cantBarcos;
    DtBarcoPesquero* dtb;
    DtBarcoPasajero* dtb1;
    DtBarco** barcos=listarBarcos(cantBarcos);
    for(int i=0;i<cantBarcos;i++){
        dtb=dynamic_cast<DtBarcoPesquero*>(barcos[i]);
        if(dtb!=NULL){
            cout<<*dtb<<endl;
        }else{
            dtb1=dynamic_cast<DtBarcoPasajero*>(barcos[i]);
            if(dtb1!=NULL)
                cout<<*dtb1<<endl;
        }
    }
    cout<<"Presione enter para continuar"<<endl;
    system("read X");

}
DtBarco** listarBarcos(int& cantBarcos){
  cantBarcos=colBarcos.topeBarco;
  DtBarco** barcos=new DtBarco*[cantBarcos];

  for(int i=0;i<cantBarcos;i++){
      if(BarcoPasajero* b = dynamic_cast<BarcoPasajero*>(colBarcos.b[i])){
          DtBarcoPasajero* dtb=new DtBarcoPasajero(b->getNombre(),
                                                   b->getId(),
                                                   b->getCantPasajeros(),
                                                   b->getTamanio());
        barcos[i]=dtb;
      }else if(BarcoPesquero* b1=dynamic_cast<BarcoPesquero*>(colBarcos.b[i])){
          DtBarcoPesquero* dtb1=new DtBarcoPesquero(b1->getNombre(),
                                                    b1->getId(),
                                                    b1->getCapacidad(),
                                                    b1->getCarga());
        barcos[i]=dtb1;
      }
    }
  return barcos;
}







//Operaciones Auxiliares
void controlarCarga(string idBarco,float cargaDespacho){
    Barco *b=obtenerBarco(idBarco);
    if(BarcoPesquero * pesquero=dynamic_cast<BarcoPesquero*>(b)){
        float carga=pesquero->getCarga();
        float capacidad=pesquero->getCapacidad();
        float disponible=capacidad-carga;
        if(cargaDespacho<0){
            if(disponible == 0 || disponible< cargaDespacho*(-1)){
                throw invalid_argument("EL BARCO NO TIENE SUFICIENTE CAPACIDAD\n");
            }            
        }else{
            if(cargaDespacho>0){
                if(carga<cargaDespacho){
                    throw invalid_argument("EL BARCO NO TIENE SUFICIENTE CARGA\n");
                }
            }
        }
    }else{
        if(BarcoPasajero * pasajeros=dynamic_cast<BarcoPasajero*>(b)){
            if(cargaDespacho !=0){
                throw invalid_argument("BARCO DE PASAJEROS: LA CARGA NO PUEDE SER DISTITNA DE 0 \n");
            }
        }
    }
}

void controlFecha(int dia,int mes,int anio){
    string mensaje=" ";
    string a,b,c;
    if(anio<1900){
        a="Anio incorrecto \n";
        mensaje=mensaje+a;
    }
    if(dia<1 || dia>31){
        b="Dia incorrecto \n";
        mensaje=mensaje+b;
    }
    if(mes<1 || mes>12){
        c="Mes incorrecto \n";
        mensaje=mensaje+c;
    }
    if(strcmp(mensaje.c_str()," ")!=0){
        throw invalid_argument(mensaje);
    }

}

void existePuerto(string IdPuerto){
	int i=0;
	bool existe=false;
	while((i<colPuertos.topePuerto)&&(!existe)){
        if(IdPuerto == colPuertos.p[i]->getId())
		existe=true;
		i++;
	}
	if (existe)
		throw invalid_argument("\nERROR: YA EXISTE UN PUERTO CON ESE ID EN EL SISTEMA\n");
}
void noExistePuerto(string IdPuerto){
	int i=0;
	bool existe=false;
	while((i<colPuertos.topePuerto)&&(!existe)){
        if(IdPuerto == colPuertos.p[i]->getId())
		existe=true;
		i++;
	}
	if (!existe)
		throw invalid_argument("\nERROR: NO EXISTE UN PUERTO CON ESE ID EN EL SISTEMA\n");
}


void existeBarco(string idBarco){
    int i=0;
    bool existe=false;
    while((i<colBarcos.topeBarco) && (!existe)){
        if(idBarco == colBarcos.b[i]->getId())
            existe=true;
        i++;
    }
    if(existe){
        throw invalid_argument("\nERROR: YA EXISTE UN BARCO CON ESE ID EN EL SISTEMA\n");
    }
}
void noExisteBarco(string idBarco){
    int i=0;
    bool existe=false;
    while((i<colBarcos.topeBarco) && (!existe)){
        if(idBarco == colBarcos.b[i]->getId())
            existe=true;
        i++;
    }
    if(!existe){
        throw invalid_argument("\nERROR: NO EXISTE UN BARCO CON ESE ID EN EL SISTEMA\n");
    }
}

void diaCorrecto(int dia){
	if(dia>31|| dia<1)
        throw invalid_argument("\nERROR: El dia no puede ser menor a 1 ni mayor a 31\n");
}
void mesCorrecto(int mes,int dia){
	if(mes==2 && dia>29){
		throw invalid_argument("\nERROR: El mes de febrero tiene 28 dias y 29 en anio bisiesto\n");
	}else if(mes>12|| mes<1)
		 throw invalid_argument("\nERROR: El mes no puede ser menor a 1 ni mayor a 12\n");
}
void anioCorrecto(int anio,int mes, int dia){
	if(anio<1900){
		 throw invalid_argument("\nERROR: El anio no puede ser menor a 1900\n");
    }else if(mes==2 && dia==29){
        if(anio % 4!=0 || (anio % 100==0 && anio % 400!=0)){
            throw invalid_argument("\nERROR: EL anio que ingreso no es bisiesto por lo tanto febrero tiene 28 dias ese anio\n");

        }
    }

}
Barco* obtenerBarco(string idBarco){
    Barco* barco;
    int i=0;
    bool encontre=false;
    while((i<colBarcos.topeBarco) && (!encontre)){
        if(colBarcos.b[i]->getId()==idBarco){
            barco=colBarcos.b[i];
            encontre=true;
        }else
            i++;
    }
    return barco;
}

Puerto* obtenerPuerto(string idPuerto){
    Puerto* puerto;
    bool encontre=false;
    int i=0;
    while(i<colPuertos.topePuerto && !encontre){
        if(colPuertos.p[i]->getId() == idPuerto){
            puerto=colPuertos.p[i];
            encontre=true;
        }else
            i++;
    }
    return puerto;
}

void tieneArribos(string idPuerto){
    Puerto* p = obtenerPuerto(idPuerto);
    if(p->getCantArribos()==0)
        throw invalid_argument("\nEl puerto no tiene arribos\n");
}



void cargarDatos(){
    DtFecha f1 = DtFecha(11,5,2021);
    DtFecha f2 = DtFecha(21,11,2011);
    DtFecha f3 = DtFecha(31,8,1999);
    
    agregarPuerto("1","hola",f1);
    agregarPuerto("2","nada",f2);
    agregarPuerto("3","coso",f3);
    
    DtBarcoPasajero a=DtBarcoPasajero("hola","1",55,TRANSATLANTICO);
    DtBarcoPasajero a1=DtBarcoPasajero("algo","2",50,GALEON);
    
    DtBarcoPesquero b= DtBarcoPesquero("coso","3",45,25);
    DtBarcoPesquero b1= DtBarcoPesquero("nada","4",32,5);
    
    agregarBarco(a);
    agregarBarco(a1);
    agregarBarco(b);
    agregarBarco(b1);

    agregarArribo("1","1",f1,33);
    agregarArribo("1","1",f1,53);
    agregarArribo("2","3",f3,33);
    system("clear");
    cout<<"Se cargaron correctamente los datos"<<endl;
    system("read x");

}

void menu(){
   system("clear");
		cout <<"_____________________________________________" <<endl;
		cout <<"________________BIENVENIDO________________"<< endl;
		cout <<"1. Agregar Puerto"<<endl;
		cout <<"2. Agregar Barco"<<endl;
		cout <<"3. Listar Puertos"<<endl;
		cout <<"4. Agegar Arribo"<<endl;
		cout <<"5. Obtener informacion de Arribos de un Puerto"<<endl;
		cout <<"6. Eliminar Arribos de un Puerto"<<endl;
		cout <<"7. Listar Barcos"<<endl;
		cout <<"8. Cargar datos"<<endl;
		cout <<"9. Salir"<<endl;
		cout <<"_____________________________________________" <<endl;
		cout <<"OPCION: ";
}

int main(){
    colBarcos.topeBarco=0;
    colPuertos.topePuerto=0;
    int opcion;
    menu();
    cin>>opcion;
    while(opcion!=9){
        switch(opcion){
            case 1:menuAgregarPuerto();break;
            case 2:menuAgregarBarco();break;
            case 3:listarPuertos();break;
            case 4:agregarArribos();break;
            case 5:listarArribos();break;
            case 6:menuEliminarArribos();break;
            case 7:listarBarcos();break;
        	case 8:cargarDatos();break;
		}
    menu();
    cin>>opcion;
    } 
	cout<<"Saliendo......."<<endl;
	sleep(5);
	return 0;
}
