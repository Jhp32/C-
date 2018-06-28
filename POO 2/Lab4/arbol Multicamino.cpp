#include <iostream>
using namespace std;
class Nodo{
public:
	int dato;
	Nodo *hijo;
	Nodo *hermano;

	Nodo();
	Nodo(int d);
	int getDato();
};

Nodo::Nodo(){
	dato=0;
	hijo=NULL;
	hermano=NULL;
}
Nodo::Nodo(int d){
	this->dato=d;
	hijo=NULL;
	hermano=NULL;
}

class arbolMulticamino{
private:
	Nodo *raiz;
public:
	arbolMulticamino();
	Nodo *getRaiz();
	void crearArbol(int d);
	void insertar(Nodo *nuevo, int d);
	void buscarRef(Nodo *arbol, int d, int aux);
	bool estadoArbol();
	void preOrden(Nodo *arbol);
	void postOrden(Nodo *arbol);
	void niveles(Nodo *arbol);
	void borrado(Nodo *arbol, int d);
};
arbolMulticamino::arbolMulticamino(){
	raiz=NULL;
}
Nodo* arbolMulticamino::getRaiz(){
	return raiz;
}
void arbolMulticamino::crearArbol(int d){
	Nodo *p=new Nodo (d);
		raiz=p;
}
void arbolMulticamino::insertar(Nodo *nuevo, int d){
	Nodo *p=new Nodo(d);
	if (nuevo->hijo==NULL){
		nuevo->hijo=p;
	}
	else{
		Nodo *x=nuevo->hijo;
		while(x->hermano!=NULL){
				x=x->hermano;
		}
		x->hermano=p;
	}
}
void arbolMulticamino::buscarRef(Nodo *arbol, int d, int aux){
	if(arbol!=NULL){
		Nodo *p;
		if(arbol->dato!=d){
			buscarRef(arbol->hijo, d, aux);
			p=arbol->hermano;
			while(p!=NULL){
				buscarRef(p, d, aux);
				p=p->hermano;
			}
		}
		else{
            insertar(arbol, aux);
		}
	}
}
bool arbolMulticamino::estadoArbol(){
	Nodo *p=raiz;
	if(p==NULL){
		return false;
	}
	else{
		return true;
	}
}
void arbolMulticamino::preOrden(Nodo *arbol){
	if(arbol!=NULL){
		cout<<arbol->dato<<" - ";
		preOrden(arbol->hijo);
		preOrden(arbol->hermano);
	}
}
void arbolMulticamino::postOrden(Nodo *arbol){
	if(arbol!=NULL){
		postOrden(arbol->hijo);
		postOrden(arbol->hermano);
		cout<<arbol->dato<<" - ";
		
	}
}
void arbolMulticamino::niveles(Nodo *arbol){
	if(arbol!=NULL){
		cout<<arbol->dato<<" - ";
		niveles(arbol->hermano);
		niveles(arbol->hijo);
	}
}
void arbolMulticamino::borrado(Nodo *arbol, int d){
	if(arbol!=NULL){
		Nodo *p;
		if(arbol->dato!=d){
			borrado(arbol->hijo, d);
			p=arbol->hermano;
			while(p!=NULL){
				borrado(p, d);
				p=p->hermano;
			}
		}
		else{
			delete(arbol->hijo);
			Nodo *temp=arbol;
			arbol=arbol->hermano;
			delete temp;
		}
	}
}
int main(int argc, char *argv[]) {
	arbolMulticamino mar;

	int ct=0, d, padre;
	int opc;

	do{
		cout<<"Ingrese Opcion:"<<endl
			<<"***************************"<<endl
			<<"1. Insertar Nodo"<<endl
			<<"2. Pre-Orden"<<endl
			<<"3. Post-Orden"<<endl
			<<"4. Niveles"<<endl
			<<"5. Estado"<<endl
			<<"6. Borrado"<<endl
			<<"7. Salir"<<endl
			<<"**************************"<<endl
			<<"Opcion: ";
		cin>>opc;
		cout<<endl;
		switch(opc){
		case 1:
			if(ct==0){
				cout<<"Ingrese Raiz: ";
				cin>>d;
				cout<<endl;
				mar.crearArbol(d);
				ct++;
			}
			else{
				cout<<"Ingrese Dato: ";
				cin>>d;
				cout<<endl;
				Nodo *joe=mar.getRaiz();
				cout<<"Ingrese Padre: ";
				cin>>padre;
				cout<<endl;
				mar.buscarRef(joe, padre, d);
				ct++;
			}
			break;

		case 2:{
			cout<<endl;
			Nodo *joe=mar.getRaiz();
			mar.preOrden(joe);
			cout<<endl;
			}
			break;
		case 3:{
			cout<<endl;
			Nodo *joe=mar.getRaiz();
			mar.postOrden(joe);
			cout<<endl;
		}
			break;
		case 4:{
			cout<<endl;
			Nodo *joe=mar.getRaiz();
			mar.niveles(joe);
			cout<<endl;
		}
			break;
		case 5:{
			if(mar.estadoArbol()==false){
				cout<<"El Arbol Esta Vacio"<<endl;
			}
			else{
				cout<<"El Arbol Esta Ocupado"<<endl;
			}
		}
			break;

		case 6:{
				cout<<"Ingrese Dato A Borrar: ";
				cin>>d;
				cout<<endl;
				Nodo *joe=mar.getRaiz();
				mar.borrado(joe, d);
		}
		break;

		case 7:
			cout<<"SALIENDO..."<<endl;
			break;
		}
	}while(opc!=7);

	return 0;
}

