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
		cout<<"Nombre Del Cliente: "<<nombre
			<<endl
			<<"Numero De Cuenta: "<<NoCuenta
			<<endl
			<<"Status De Tiempo: "<<statusTime
			<<endl<<endl;

	}

	void mostrarCliente(){
		cout<<nombre;
	}

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
		size=3;
		head=NULL;
		tail=NULL;
	}

	void NewCliente(string nombre, string NoCuenta, int statusTime){
		Nodo *p=new Nodo (nombre, NoCuenta, statusTime);
		if(head==NULL){
			p->crearCliente();

			head=p;
			tail=p;
			size=1;
		}
		else if(size==20){
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

	void mostrarClienteFila(){
		Nodo *p=head;
		while(p!=NULL){
			Nodo aux;
			p->mostrarCliente();
			cout<<" <-- ";
			p=p->sig;
		};
		cout<<endl;
	}

	void mostrarClienteCaja(){
			Nodo *p=head;
			while(p!=NULL){
				p->mostrarClienteEnCaja();
				cout<<"		^"<<endl
					<<"		|"<<endl;
				p=p->sig;
			};
	}



ListaLigadaConten enviarCaja(ListaLigadaConten Fila, ListaLigadaConten cajas){
Nodo *p=head;

	
	
}

};

int main(int argc, char *argv[]) {
	ListaLigadaConten FilaBanco, cajas;
	Nodo s;



	FilaBanco.NewCliente(s.getNombre(), s.getNoCuenta(), s.getStatusTime() );
	FilaBanco.mostrarClienteFila();



	return 0;
}

