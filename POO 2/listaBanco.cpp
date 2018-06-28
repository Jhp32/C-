#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

class Nodo{
public:
	string nombre;
	string NoCuenta;
	int statusTime;
	Nodo *sig;
	Nodo *ant;
	
	Nodo(){
		nombre="";
		NoCuenta="";
		statusTime=1;
		
		sig=NULL;
		ant=NULL;
	}
	
	Nodo(string nombre, string NoCuenta, int statusTime){
		this->nombre=nombre;
		this->NoCuenta=NoCuenta;
		this->statusTime=statusTime;
		srand(time(NULL));
		statusTime=rand()%16+1;
		
		sig=NULL;
		ant=NULL;
	}
	
	void crearCliente(){
		cout<<"Nombre Del Cliente: ";
		cin>>nombre;
		cout<<endl<<"Numero De Cuenta: ";
		cin>>NoCuenta;
		cout<<endl<<endl;
	}
	
	
	void mostrarClienteEnCaja(){
		cout<<"Nombre: "<<nombre<<endl
			<<"No. Cuenta: "<<NoCuenta<<endl
			<<"Tiempo: "<<statusTime;
	}
	
	void mostrarClienteEnFila(){
		cout<<nombre;
	}
	
	//getters
	string getNombre(){
		return nombre;
	}
	string getNoCuenta(){
		return NoCuenta;
	}
	int getStatusTime(){
		srand(time(NULL));
		statusTime=rand()%16+1;
		return statusTime;
	}
	
};


class ListaLigadaConten{
private:
	int size;
	int sizeCaja;
	Nodo *head;
	Nodo *tail;
	
public:
	ListaLigadaConten(){
		size=0;
		head=NULL;
		tail=NULL;
	}
	//crear Fila
	void crearClienteFila(string nombre, string NoCuenta, int statusTime){
		Nodo *p=new Nodo (nombre, NoCuenta, statusTime);
		if(head==NULL){
			p->crearCliente();
			
			head=p;
			tail=p;
			size=1;
		}
		else if(size>=20){
			cout<<"No es posible agregar nuevo cliente"<<endl<<
				"	¡¡¡	FILA LLENA	!!!	"<<endl;
		}
		
		else{
			p->crearCliente();
			
			tail->sig=p;
			p->ant=tail;
			tail=p;
			size++;
		}
	}
	
	//crear Caja	
	void cajaUno(string nombre, string NoCuenta, int statusTime){
		Nodo *p=new Nodo (nombre, NoCuenta, statusTime);
		if(head==NULL){
			p->crearCliente();
			
			head=p;
			tail=p;
		}
	}
	void cajaDos(string nombre, string NoCuenta, int statusTime){
		Nodo *p=new Nodo (nombre, NoCuenta, statusTime);
		if(head->sig==NULL){
			p->crearCliente();
			
			head=p;
			tail=p;
		}
	}
	void cajaTres(string nombre, string NoCuenta, int statusTime){
		Nodo *p=new Nodo (nombre, NoCuenta, statusTime);
		if(tail==NULL){
			p->crearCliente();
			
			head=p;
			tail=p;
		}
	}
	
	void Transferir(ListaLigadaConten *fila, ListaLigadaConten *caja){
		Nodo *p=fila->head;
		
		if(caja->head==NULL){
			caja->head=p;
			fila->eliminarInicio();
			caja->mostrarClienteCaja();
		}/*
		else if(p->sig==NULL){
			p->sig=head;
			eliminarInicio();
		}
		else if(caja->tail==NULL){
			caja->tail=head;
			eliminarInicio();
		}
		else{
			cout<<"Cajas Llenas"<<endl;
		}
		//caja.mostrarClienteCaja();*/
	}
	
	
	void mostrarClienteFila(){
		Nodo *p=head;
		while(p!=NULL){
			p->mostrarClienteEnFila();
			
			cout<<" <-- ";
			p=p->sig;
		};
		cout<<endl;
	}
	
		
	void mostrarClienteCaja(){
		Nodo *p=head;
		while(p!=NULL){
			p->mostrarClienteEnCaja();		
			cout<<endl<<"|**************|	"<<endl;
			p=p->sig;
		};
		
	}
	
	void eliminarInicio(){
		Nodo *p=head;
		
		head=p->sig;
		p->sig=NULL;
		head->ant=NULL;
		
		delete p;
	}
	
};

int main(int argc, char *argv[]) {
	ListaLigadaConten filaBanco, Cajas;
	Nodo s;
	
	filaBanco.crearClienteFila(s.getNombre(), s.getNoCuenta(), s.getStatusTime());
	filaBanco.crearClienteFila(s.getNombre(), s.getNoCuenta(), s.getStatusTime());
	filaBanco.crearClienteFila(s.getNombre(), s.getNoCuenta(), s.getStatusTime());
	filaBanco.crearClienteFila(s.getNombre(), s.getNoCuenta(), s.getStatusTime());
	
	//filaBanco.mostrarClienteFila();
	
	filaBanco.Transferir(filaBanco, Cajas);
	
	//Cajas.mostrarClienteCaja();
	//filaBanco.mostrarClienteFila();
	
	return 0;
}

