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

class arbolBBusqueda{
private: 
		Nodo *arbol;
public:
	arbolBBusqueda();
	Nodo *getArbol();
	void insertar(Nodo **raiz, int d, Nodo *padre);
	bool estadoArbol();
	void inOrden(Nodo *raiz);
	void preOrden(Nodo *raiz);
	void postOrden(Nodo *raiz);
	void borrado(Nodo *raiz, int d);
	void eliminarNodo(Nodo *raiz);
	Nodo *minimo(Nodo *base);
	void reemplazar(Nodo *cambiar, Nodo *nuevo);
	void busqueda(Nodo *raiz, int d);
	void esHoja(Nodo **raiz, int d);
};
arbolBBusqueda::arbolBBusqueda(){
	arbol=NULL;
}
Nodo* arbolBBusqueda::getArbol(){
	return arbol;
}
void arbolBBusqueda::insertar(Nodo **raiz, int d, Nodo *padre){
	if(*raiz==NULL){
		*raiz=new Nodo(d);
		(*raiz)->padre=padre;
		
		if(arbol==NULL)arbol=*raiz;
	}
	else{
		if( d < (*raiz)->dato ){
				insertar(&(*raiz)->izq, d, *raiz);
		}
		else{
				insertar(&(*raiz)->der, d, *raiz);
		}
	}
}
bool arbolBBusqueda::estadoArbol(){
	if(arbol==NULL){
		return false;
	}
	else{
		return true;
	}
}
void arbolBBusqueda::inOrden(Nodo *raiz){
	if(raiz!=NULL){
		inOrden(raiz->izq);
		cout<<raiz->dato<<" - ";
		inOrden(raiz->der);
	}
}
void arbolBBusqueda::preOrden(Nodo *raiz){
	if(raiz!=NULL){
		cout<<raiz->dato<<" - ";
		preOrden(raiz->izq);
		preOrden(raiz->der);
	}
}
void arbolBBusqueda::postOrden(Nodo *raiz){
	if(raiz!=NULL){
		postOrden(raiz->izq);
		postOrden(raiz->der);
		cout<<raiz->dato<<" - ";
	}
}
void arbolBBusqueda::borrado(Nodo *raiz, int d){
	if(raiz!=NULL){
		if( d < raiz->dato){
			borrado(raiz->izq, d);
		}
		else if(d > raiz->dato){
			borrado(raiz->der, d);
		}
		else{
			eliminarNodo( raiz);
		}
	}
}
void arbolBBusqueda::eliminarNodo(Nodo *raiz){
	if( raiz->izq && raiz->der ){
		Nodo *menor=minimo( raiz->der );
		raiz->dato=menor->dato;
		eliminarNodo(menor);
	}
	else if(raiz->izq){
		reemplazar(raiz, raiz->izq);
		delete raiz;
	}
	else if(raiz->der){
		reemplazar(raiz, raiz->der);
		delete raiz;
	}
	else{
		reemplazar(raiz, NULL);
		delete raiz;
	}
}
Nodo* arbolBBusqueda::minimo(Nodo *base){
	if(base!=NULL){
		if(base->izq){
			minimo(base->izq);
		}
		else{
			return base;
		}
	}
}
void arbolBBusqueda::reemplazar(Nodo *raiz, Nodo *nuevo){
	if(raiz->padre){
		if(raiz->dato == raiz->padre->izq->dato){
			raiz->padre->izq=nuevo;
		}
		else if(raiz->dato == raiz->padre->der->dato){
			raiz->padre->der=nuevo;
		}
	}
	if(nuevo){
		nuevo->padre=raiz->padre;
	}
}

void arbolBBusqueda::busqueda(Nodo *raiz, int d){
	if(raiz!=NULL){
		if( d < raiz->dato){
			busqueda(raiz->izq, d);
		}
		else if(d > raiz->dato){
			busqueda(raiz->der, d);
		}
		else{
			cout<<"Si Existe El Dato: "<<raiz->dato;
		}
	}
}
void arbolBBusqueda::esHoja(Nodo **raiz, int d){
	if(*raiz!=NULL){
		if((*raiz)->dato!=d){
			esHoja(&(*raiz)->izq, d);
			esHoja(&(*raiz)->der, d);
		}
		else{
			if( (*raiz)->izq==NULL && (*raiz)->der==NULL ){
				cout<<endl<<"Es Una Hoja"<<endl;
			}
			else{
				cout<<endl<<"No Es Una Hoja"<<endl;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	arbolBBusqueda mary;
	Nodo *joel=mary.getArbol();
	int opc;
	int  d;
	do{
		cout<<"Ingrese Opcion:"<<endl
			<<"***************************"<<endl
			<<"1. Insertar Nodo"<<endl
			<<"2. In-Orden"<<endl
			<<"3. Pre-Orden"<<endl
			<<"4. Post-Orden"<<endl			
			<<"5. Estado"<<endl
			<<"6. Eliminar Nodo"<<endl
			<<"7. Busqueda De Nodo"<<endl
			<<"8. Es Hoja? "<<endl
			<<"9. Salir"<<endl
			<<"**************************"<<endl
			<<"Opcion: ";
		cin>>opc;
		cout<<endl;
		switch(opc){
			case 1:
				cout<<"Ingrese Dato: ";
				cin>>d;
				cout<<endl;
				mary.insertar(&joel, d, NULL);
				cout<<endl;
				break;
		case 2:
				cout<<endl<<"*** In-Orden ***"<<endl;
				mary.inOrden(joel);
				cout<<endl;
				break;
		case 3:
				cout<<endl<<"*** Pre-Orden ***"<<endl;
				mary.preOrden(joel);
				cout<<endl;
				break;
		case 4:
				cout<<endl<<"*** Post-Orden ***"<<endl;
				mary.postOrden(joel);
				cout<<endl;
				break;
		case 5:
				if(mary.estadoArbol()==true){
					cout<<endl<<"El Arbol Esta Ocupado"<<endl;
				}
				else{
					cout<<endl<<"El Arbol Esta Vacio"<<endl;
				}
				break;
				
		case 6:
				cout<<"Ingrese Dato A Eliminar: ";
				cin>>d;
				cout<<endl;
				mary.borrado(joel, d);
				break;
		case 7:
				cout<<"Ingrese Dato A Buscar: ";
				cin>>d;
				cout<<endl;
				mary.busqueda(joel, d);
				cout<<endl;
				break;
				
		case 8:
				cout<<"Ingrese Dato A Saber Estado: ";
				cin>>d;
				cout<<endl;
				mary.esHoja(&joel, d);
				break;
				
		case 9:
			cout<<endl<<"SALIENDO..."<<endl;
			break;
		}
	}while(opc!=9);
	
	return 0;
}

