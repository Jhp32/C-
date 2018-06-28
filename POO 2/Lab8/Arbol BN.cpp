#include <iostream>
using namespace std;

class Nodo{
public:
	int dato;
	Nodo *hermano;
	Nodo *izq;
	Nodo *der;

	Nodo();
	Nodo(int d);
};

Nodo::Nodo(){
	dato=0;
	hermano=NULL;
	izq=NULL;
	der=NULL;
}
Nodo::Nodo(int d){
	this->dato=d;
	hermano=NULL;
	izq=NULL;
	der=NULL;
}

class arbolBusquedaN{
private:
	Nodo *raiz;
	int size;
	int maximo;
public:
	arbolBusquedaN();
	arbolBusquedaN(int size, int maximo);
	Nodo *getRaiz();
	int asignarOrden(int tam);
	void insertar(Nodo *nuevo, int d);
	void insertarAtras(int mayor, int d);
};

arbolBusquedaN::arbolBusquedaN(){
	raiz=NULL;
	size=0;
	maximo=0;
}
arbolBusquedaN::arbolBusquedaN(int size, int maximo){
	this->size=size;
	this->maximo=maximo;
}

Nodo* arbolBusquedaN::getRaiz(){
	return raiz;
}
int arbolBusquedaN::asignarOrden(int tam){
	maximo=tam;
	return maximo;
}
void arbolBusquedaN::insertar(Nodo *nuevo, int d){
	Nodo *p=new Nodo(d);
	if(raiz==NULL){
		p->dato=d;
		p->der=NULL;
		p->izq=NULL;
		raiz=p;
		size=1;
		cout<<raiz->dato;
	}
	else if(size>0 && size<=maximo && raiz->dato>d){
        p->hermano=raiz;
        raiz=raiz->hermano;
        raiz=p;
        size++;
        cout<<"---"<<raiz->dato;
	}
	else if(size>0 && size<=maximo && raiz->dato<d){
        Nodo *tail=raiz;
        while(tail->hermano!=NULL){
           tail=raiz->hermano;
        }
        p->hermano=tail->hermano;
        tail->hermano=p;
        p=tail;
        size++;
        cout<<"---"<<raiz->hermano->hermano->dato;
	}
	else if(size>0 && size<=maximo){
        Nodo *aux=raiz;
        Nodo *aux2;
		while(aux!=NULL){
            if(aux->dato<d){
                aux=aux->hermano;
            }
            else{
                break;
            }
		}
		p->hermano=aux;
        aux->hermano=p;
        p=aux;
        size++;
	}
}
int main(int argc, char *argv[]) {
	arbolBusquedaN mar;
	Nodo *joe=mar.getRaiz();
	mar.asignarOrden(4);

	mar.insertar(joe, 19);
	mar.insertar(joe, 9);
    mar.insertar(joe, 22);
    mar.insertar(joe, 20);
	return 0;
}

