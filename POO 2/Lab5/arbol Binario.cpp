#include <iostream>
using namespace std;

class Nodo{
public:
	int dato;
	Nodo *izq;
	Nodo *der;
	
	Nodo();
	Nodo(int d);
};
Nodo::Nodo(){
	dato=0;
	izq=NULL;
	der=NULL;
}
Nodo::Nodo(int d){
	this->dato=d;
	izq=NULL;
	der=NULL;
}

class arbolBi{
private: 
		Nodo *arbol;
public:
	arbolBi();
	Nodo *getArbol();
	void insertar(Nodo **raiz, int d);
	bool estadoArbol();
	void inOrden(Nodo *raiz);
	void preOrden(Nodo *raiz);
	void postOrden(Nodo *raiz);
	Nodo *borrado(Nodo **raiz, int d);
	void busqueda(Nodo **raiz, int d);
	Nodo *modificar(Nodo **raiz, int d, int nuevo);
	void esHoja(Nodo **raiz, int d);
};
arbolBi::arbolBi(){
	arbol=NULL;
}
Nodo* arbolBi::getArbol(){
	return arbol;
}
void arbolBi::insertar(Nodo **raiz, int d){
	if(*raiz==NULL){
		*raiz=new Nodo(d);
		if(arbol==NULL)arbol=*raiz;
	}
	else{
		char opc;
		cout<<"Insertar Izq. o Der. (L) (R): ";
		cin>>opc;
		cout<<endl;
		if(opc=='L'){
				insertar(&(*raiz)->izq, d);
				
		}
		else if(opc=='R'){
				insertar(&(*raiz)->der, d);
		}
		else{
			cout<<"Opcion no disponible!!!"<<endl;
		}
	}
}
bool arbolBi::estadoArbol(){
	if(arbol==NULL){
		return false;
	}
	else{
		return true;
	}
}
void arbolBi::inOrden(Nodo *raiz){
	if(raiz!=NULL){
		inOrden(raiz->izq);
		cout<<raiz->dato<<" - ";
		inOrden(raiz->der);
	}
}
void arbolBi::preOrden(Nodo *raiz){
	if(raiz!=NULL){
		cout<<raiz->dato<<" - ";
		preOrden(raiz->izq);
		preOrden(raiz->der);
	}
}
void arbolBi::postOrden(Nodo *raiz){
	if(raiz!=NULL){
		postOrden(raiz->izq);
		postOrden(raiz->der);
		cout<<raiz->dato<<" - ";
	}
}
Nodo* arbolBi::borrado(Nodo **raiz, int d){
	if(*raiz!=NULL){
		if((*raiz)->dato!=d){
			borrado(&(*raiz)->izq, d);
			borrado(&(*raiz)->der, d);
		}
		else{
			delete *raiz;
			*raiz=NULL;
		}
	}
}
void arbolBi::busqueda(Nodo **raiz, int d){
	if(*raiz!=NULL){
		if((*raiz)->dato!=d){
			busqueda(&(*raiz)->izq, d);
			busqueda(&(*raiz)->der, d);
		}
		else{
			cout<<"Si Existe El Dato: "<<(*raiz)->dato;
		}
	}
}
Nodo *arbolBi::modificar(Nodo **raiz, int d, int nuevo){
	if(*raiz!=NULL){
		if((*raiz)->dato!=d){
			modificar(&(*raiz)->izq, d, nuevo);
			modificar(&(*raiz)->der, d, nuevo);
		}
		else{
			(*raiz)->dato=nuevo;
		}
	}
}
void arbolBi::esHoja(Nodo **raiz, int d){
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
	arbolBi mary;
	Nodo *joel=mary.getArbol();
	int opc;
	int  d, nuevoVa;
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
			<<"8. Modificar De Nodo"<<endl
			<<"9. Es Hoja? "<<endl
			<<"10. Salir"<<endl
			<<"**************************"<<endl
			<<"Opcion: ";
		cin>>opc;
		cout<<endl;
		switch(opc){
			case 1:
				cout<<"Ingrese Dato: ";
				cin>>d;
				cout<<endl;
				mary.insertar(&joel, d);
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
				mary.borrado(&joel, d);
				break;
		case 7:
				cout<<"Ingrese Dato A Buscar: ";
				cin>>d;
				cout<<endl;
				mary.busqueda(&joel, d);
				cout<<endl;
				break;
				
		case 8:
				cout<<"Ingrese Dato A Modificar: ";
				cin>>d;
				cout<<endl;
				cout<<"Ingrese El Nuevo Dato: ";
				cin>>nuevoVa;
				cout<<endl;
				mary.modificar(&joel, d, nuevoVa);
				break;
				
		case 9:
				cout<<"Ingrese Dato A Saber Estado: ";
				cin>>d;
				cout<<endl;
				mary.esHoja(&joel, d);
				break;
				
		case 10:
			cout<<endl<<"SALIENDO..."<<endl;
			break;
		}
	}while(opc!=10);
	
	return 0;
}

