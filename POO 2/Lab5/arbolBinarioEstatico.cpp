#include <iostream>
using namespace std;

class Nodo{
public:
	int dato;
	Nodo *izq;
	Nodo *der;
	Nodo *padre;
	
	Nodo();
	Nodo(int d);
};
Nodo::Nodo(){
	dato=0;
	izq=NULL;
	der=NULL;
	padre=NULL;
}
Nodo::Nodo(int d){
	this->dato=d;
	izq=NULL;
	der=NULL;
	padre=NULL;
}

class arbolEst{
private: 
	Nodo arre[11];
public:
	arbolEst(Nodo *arre);
	arbolEst();
	Nodo *getArbol();
	void insertar(Nodo **raiz, int d);
	int buscar(int d);
	void mostrar();
};

arbolEst::arbolEst(Nodo *arre){
	this->arre[11]=*arre;
}
arbolEst::arbolEst(){
	*arre=NULL;
}
Nodo* arbolEst::getArbol(){
	for(int i=0; i<=10; i++){
		return &arre[i];
	}
}
void arbolEst::insertar(Nodo **raiz, int d){
	if(*raiz==NULL && (*raiz)->dato==0 ){
		*raiz=new Nodo(d);
		int p=buscar((*raiz)->padre->dato);
		arre[ 2*(p)+1 ]=*(*raiz);
	}
	else{
		char opc;
		cout<<"Insertar Izq. o Der. (L) (R): ";
		cin>>opc;
		cout<<endl;
		if(opc=='L'){
				(*raiz)->padre=*raiz;
				insertar(&(*raiz)->izq, d);
				
		}
		else if(opc=='R'){
				(*raiz)->padre=*raiz;
				insertar(&(*raiz)->der, d);
		}
		else{
			cout<<"Opcion no disponible!!!"<<endl;
		}
	}
}
int arbolEst::buscar(int d){
		for(int i=0; i<=10; i++){
			if(arre[i].dato==d){
				return i;
			}
		}
}

void arbolEst::mostrar(){
	for(int i=0; i<=10; i++){
		cout<<arre[i].dato<<" - ";
	}
}

int main(){
	arbolEst arb;
	Nodo *nod=arb.getArbol();
	
	arb.insertar(&nod, 7);
	arb.mostrar();
	
	return 0;
}
