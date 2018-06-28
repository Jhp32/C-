#include <iostream>
#include <stdio.h>
using namespace std;

class Nodo{
public:
	int dato;
	Nodo *izq;
	Nodo *der;
	//Nodo *padre;
	
	Nodo();
	Nodo(int d);
};
Nodo::Nodo(){
	dato=0;
	izq=NULL;
	der=NULL;
	//padre=NULL;
}
Nodo::Nodo(int d){
	this->dato=d;
	izq=NULL;
	der=NULL;
	//padre=NULL;
}

class arbolAVL{
private: 
		Nodo *arbol;
public:
	arbolAVL();
	Nodo *getArbol();
	Nodo *crearNodo(int dato);
	//Nodo *crearNodo(int dato, Nodo *Spadre);
	//void insertar(Nodo **raiz, int d, Nodo *Spadre);
	void insertar(Nodo **raiz, int d);
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
	
	void mostrarNodo(Nodo *t, int h);
	void mostrar(Nodo *t, int h);
	int profundidad(Nodo *raiz);
	int altura(Nodo *raiz);
	Nodo *desequilibrio(Nodo *raiz);
	
	Nodo *rotacionIzq(Nodo *raiz);
	Nodo *rotacionDer(Nodo *raiz);
	
	Nodo *rotDerIzq(Nodo *raiz);
	Nodo *rotIzqDer(Nodo *raiz);
};
arbolAVL::arbolAVL(){
	arbol=NULL;
}
Nodo* arbolAVL::getArbol(){
	return arbol;
}
/*
Nodo* arbolAVL::crearNodo(int d, Nodo *Spadre) {
	Nodo *nuevo=new Nodo();
	
	nuevo->dato=d;
	nuevo->izq=NULL;
	nuevo->der=NULL;
	nuevo->padre=Spadre;
	if(arbol==NULL){
		arbol=nuevo;
		arbol->padre=arbol;
	}
	
	return nuevo;
}
void arbolAVL::insertar(Nodo **raiz, int d, Nodo *Spadre){
	if(*raiz==NULL){
		Nodo *nuevo=crearNodo(d, Spadre);
		*raiz=nuevo;
	}
	else{
		if( d < (*raiz)->dato )
				insertar(&(*raiz)->izq, d, *raiz);
		else
				insertar(&(*raiz)->der, d, *raiz);
	}
}
*/
Nodo* arbolAVL::crearNodo(int d) {
	Nodo *nuevo=new Nodo();
	
	nuevo->dato=d;
	nuevo->izq=NULL;
	nuevo->der=NULL;
	//nuevo->padre=Spadre;
	if(arbol==NULL){
		arbol=nuevo;
		//arbol->padre=arbol;
	}
	
	return nuevo;
}
void arbolAVL::insertar(Nodo **raiz, int d){
	if(*raiz==NULL){
		Nodo *nuevo=crearNodo(d);
		*raiz=nuevo;
	}
	else{
		if( d < (*raiz)->dato )
				insertar(&(*raiz)->izq, d);
		else
				insertar(&(*raiz)->der, d);
	}
}
bool arbolAVL::estadoArbol(){
	if(arbol==NULL){
		return false;
	}
	else{
		return true;
	}
}
void arbolAVL::inOrden(Nodo *raiz){
	if(raiz!=NULL){
		inOrden(raiz->izq);
		cout<<raiz->dato<<" - ";
		inOrden(raiz->der);
	}
}
void arbolAVL::preOrden(Nodo *raiz){
	if(raiz!=NULL){
		cout<<raiz->dato<<" - ";
		preOrden(raiz->izq);
		preOrden(raiz->der);
	}
}
void arbolAVL::postOrden(Nodo *raiz){
	if(raiz!=NULL){
		postOrden(raiz->izq);
		postOrden(raiz->der);
		cout<<raiz->dato<<" - ";
	}
}
void arbolAVL::borrado(Nodo *raiz, int d){
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
void arbolAVL::eliminarNodo(Nodo *raiz){
	if( raiz->izq && raiz->der ){
		Nodo *menor=minimo( raiz->der );
		raiz->dato=menor->dato;
		eliminarNodo(menor);
	}
	else if(raiz->izq){
		//reemplazar(raiz, raiz->izq);
		delete raiz;
	}
	else if(raiz->der){
		//reemplazar(raiz, raiz->der);
		delete raiz;
	}
	else{
		//reemplazar(raiz, NULL);
		delete raiz;
	}
}
Nodo* arbolAVL::minimo(Nodo *base){
	if(base!=NULL){
		if(base->izq){
			minimo(base->izq);
		}
		else{
			return base;
		}
	}
}
/*
void arbolAVL::reemplazar(Nodo *raiz, Nodo *nuevo){
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
*/
void arbolAVL::busqueda(Nodo *raiz, int d){
	if(raiz!=NULL){
		if( d < raiz->dato){
			busqueda(raiz->izq, d);
		}
		else if(d > raiz->dato){
			busqueda(raiz->der, d);
		}
		else{
			cout<<"Si Existe El Dato: "<<raiz->dato<<endl
				<<"Altura: "<<altura(raiz)<<endl
				<<"Profundidad: "<<profundidad(raiz)<<endl
				<<"Factor Equilibrio: "<<altura(raiz->der)<<" - "<<altura(raiz->izq)<<" == "<<altura(raiz->der)-altura(raiz->izq)<<endl<<endl;
			
		}
	}
}
void arbolAVL::esHoja(Nodo **raiz, int d){
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

void arbolAVL::mostrarNodo(Nodo *t, int h){ 
	for(int i=0; i<h; i++)
		putchar('\t'); //se emplean tabs para desplegar niveles.
	
	if(t==NULL){
		putchar('*');
		putchar('\n');
	}
	else 
	   cout<<t->dato<<'\n';
}
void arbolAVL::mostrar(Nodo *t, int h){
	if(t==NULL) 
		mostrarNodo(t, h);
	else {
		mostrar(t->der, h+1) ; 
		mostrarNodo(t, h); 
		mostrar(t->izq, h+1);
	}
}


int arbolAVL::profundidad(Nodo *t){
 int left=0, right = 0;
 	if(t==NULL) 
 		return 0; //Si árbol vacío, profundidad 0
 	if(t->izq != NULL) 
 		left = profundidad(t->izq); //calcula profundidad subárbol izq.
 	if(t->der != NULL) 
 		right = profundidad(t->der); //calcula profundidad subárbol der.
 	if( left > right) //si el izq tiene mayor profundidad
 		return left+1; //retorna profundidad del subárbol izq + 1
 	else
 		return right+1; //retorna profundidad del subárbol der + 1
}


int arbolAVL::altura(Nodo *T){ 
	int h, max;
	if (T == NULL) 
		return -1;
	else {
		h = altura (T->izq);
		max = altura (T->der);
		if (h > max) max = h;
		return(max+1);
	}
}

Nodo* arbolAVL::desequilibrio(Nodo *raiz){
	if(raiz!=NULL){
		desequilibrio(raiz->izq);		
		if(  (altura(raiz->der)-altura(raiz->izq)) < -1 ){
			cout<<"Arbol Desequilibrado Por la Izquierda!!!: 	"<<raiz->dato<<endl;
			rotacionDer(raiz);
		}		
		desequilibrio(raiz->der);
		if(  (altura(raiz->der)-altura(raiz->izq)) > 1 ){
			cout<<"Arbol Desequilibrado Por la Derecha!!!"<<raiz->dato<<endl;
				rotacionIzq(raiz);
		}
	}
}
Nodo* arbolAVL::rotacionIzq(Nodo *raiz){
	Nodo *temp=raiz->der;
	raiz->der=temp->izq;
	temp->izq=raiz;
	return temp;
}
Nodo* arbolAVL::rotacionDer(Nodo *raiz){
	Nodo *temp=raiz->izq;	
	raiz->izq=temp->der;	
	temp->der=raiz;
	//temp->padre=raiz->padre;
	//raiz->padre=temp;

	cout<<endl
		<<endl<<temp->dato<<endl
		<<endl<<temp->der->dato<<endl
		<<endl<<temp->izq->dato<<endl
		<<endl<<endl;
		/*
		<<endl<<temp->padre->dato<<endl
		<<endl<<temp->izq->padre->dato<<endl
		<<endl<<temp->der->padre->dato<<endl
		<<endl<<raiz->padre->dato<<endl;
		*/
	return temp;
}
Nodo *arbolAVL::rotDerIzq(Nodo *raiz){
	raiz->der=rotacionDer(raiz->der);
	return rotacionIzq(raiz);
}
Nodo *arbolAVL::rotIzqDer(Nodo *raiz){
	raiz->izq=rotacionIzq(raiz->izq);
	return rotacionDer(raiz);
}

int main(int argc, char *argv[]) {
	arbolAVL mary;
	Nodo *joel=mary.getArbol();
	int opc;
	int  d;
	do{
		cout<<"Ingrese Opcion:"<<endl
			<<"***************************"<<endl
			<<"1. Insertar Nodo"<<endl
			<<"2. Mostrar Arbol"<<endl
			<<"3. In-Orden"<<endl
			<<"4. Pre-Orden"<<endl
			<<"5. Post-Orden"<<endl			
			<<"6. Estado"<<endl
			<<"7. Eliminar Nodo"<<endl
			<<"8. Busqueda De Nodo"<<endl
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
				mary.mostrar(joel,0);
				mary.desequilibrio(joel);
				cout<<endl;
				break;
		case 2:
				cout<<endl;
				mary.mostrar(joel, 0);
				cout<<endl<<endl;
				break;
		case 3:
				cout<<endl<<"*** In-Orden ***"<<endl;
				mary.inOrden(joel);
				cout<<endl;
				break;
		case 4:
				cout<<endl<<"*** Pre-Orden ***"<<endl;
				mary.preOrden(joel);
				cout<<endl;
				break;
		case 5:
				cout<<endl<<"*** Post-Orden ***"<<endl;
				mary.postOrden(joel);
				cout<<endl;
				break;
		case 6:
				if(mary.estadoArbol()==true){
					cout<<endl<<"El Arbol Esta Ocupado"<<endl;
				}
				else{
					cout<<endl<<"El Arbol Esta Vacio"<<endl;
				}
				break;
				
		case 7:
				cout<<"Ingrese Dato A Eliminar: ";
				cin>>d;
				cout<<endl;
				mary.borrado(joel, d);
				break;
		case 8:
				cout<<"Ingrese Dato A Buscar: ";
				cin>>d;
				cout<<endl;
				mary.busqueda(joel, d);
				cout<<endl;
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
