#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
using namespace std;

class Nodo{	
	public:
		string palabra;
		Nodo *sig;
		Nodo *ant;
		
		Nodo(){
			palabra="";
			sig=NULL;
			ant=NULL;
		}
		
		Nodo(string palabra){
			this->palabra=palabra;
			sig=NULL;
			ant=NULL;
		}
		
		void ingresaPalabra(){
			cout<<"Ingresa Palabra: ";
			cin>>palabra;
			cout<<endl;
		}
		string getPalabra(){
			return palabra;
		}
		
		int valorPalabra(string palabra){
			int suma, inicio, fin;
			inicio=palabra[0];			
			fin=palabra[palabra.length()-1];
			suma=inicio+fin;
			suma=suma%16;
			return suma;
		}
};

class listaLigadaDoble{
	private:
		int size;
		Nodo *head;
		Nodo *tail;
		
	public:
		listaLigadaDoble(){
			size=0;
			head=NULL;
			tail=NULL;
		}
		int getSize(){
			return size;
		}
		
		void insertarFinal(string palabra){
			Nodo *p=new Nodo (palabra);
			if(head==NULL){
				p->getPalabra();
				head=p;
				tail=p;
				size=1;
			}			
			else{
				p->getPalabra();
				tail->sig=p;
				p->ant=tail;
				tail=p;
				size++;
			}
		}
		void agregarPalabra(){
			Nodo *p=new Nodo;
			int valor;
			string palx;
			p->ingresaPalabra();
			valor=p->valorPalabra( p->getPalabra() );
			palx=p->getPalabra();
			
			cout<<valor<<"-----"<<palx;
		}

		void eliminarFinal(){
			Nodo *aux=head;			
			while(aux->sig != tail){
				aux=aux->sig;
			}
			tail=aux;			
			tail->sig=NULL;
			size--;
		}
		
		void mostrarLista(){
			Nodo *p=head;
			while(p!=NULL){
				cout<< p->palabra <<" --> ";
				p=p->sig;				
			if(p==NULL){
			break;	
			p=p->sig;
			cout<< p->palabra <<" --> ";
			}
			}			
			
			cout<<endl;
		}
		
};


class tablaHash{
private:
	listaLigadaDoble taHash[16];
	
public:
	tablaHash(){
		llenarTabla();
	}
	void llenarTabla(){
		for (int i=0; i<16; i++){
			taHash[i]=NULL;
		}
	}
	
	void agregarPalabra(){
		Nodo *p=new Nodo;
		int valor;
		string palx;
		p->ingresaPalabra();
		valor=p->valorPalabra( p->getPalabra() );
		palx=p->getPalabra();
		mapeo(palx,valor);
		
	}
	
	
	void mapeo(string palabra, int posTabla){
		if(taHash[posTabla].getSize()<0){
			char des;
			cout<<"Este Espacio Se Encuentra Ocupado!!!"<<endl
				<<"Desea Modificarlo? s) n) --->";
			cin>>des;
			cout<<endl;
			if(des=='s'){
				taHash[posTabla].eliminarFinal();
				taHash[posTabla].insertarFinal(palabra);
				taHash[posTabla].mostrarLista();
			}
			else{
				cout<<"No se modifico"<<endl;
				taHash[posTabla].mostrarLista();
			}
		}
		else{
			taHash[posTabla].insertarFinal(palabra);
			taHash[posTabla].mostrarLista();
			}
		}

	void mostrar(){		
		for(int i=0; i<=16; i++){
			cout<<"Slot "<<i<<" :-> ";
			taHash[i].mostrarLista();
			cout<<endl;
		}
	}

};

int main(){
	tablaHash obj;
	obj.mostrar();
	
	int opc;
	do{
		cout<<"Ingrese Opcion:"<<endl
			<<"***************************"<<endl
			<<"1. Insertar Palabra"<<endl
			<<"2. Mostrar"<<endl
			<<"3. Salir"<<endl
			<<"**************************"<<endl
			<<"Opcion: ";
		cin>>opc;
		cout<<endl;
		switch(opc){
		case 1:
			obj.agregarPalabra();
			//obj.mostrar();
			break;
		case 2:
			obj.mostrar();
			break;
		case 3:
			cout<<"SALIENDO..."<<endl;
			break;
		}
	} while(opc!=3);

	return 0;
}
