 #include <iostream>
#include <math.h>
using namespace std;

class Nodo{
	public:
		int dato;
		Nodo *sig;
		
		Nodo(){
			dato=0;
			sig=NULL;
		}
		
		Nodo(int d){
		this->dato=d;
		sig=NULL;
		}
};


class listaLigada{
	private:
		int size;
		Nodo *head;
		Nodo *tail;
		
	public:
		listaLigada(){
			size=0;
			head=NULL;
			tail=NULL;
		}
		
		
		void insertarInicio(int d){
			Nodo *p=new Nodo (d);			
			if(head==NULL){
				head=p;
				tail=p;
				size=1;
			}			
			else{
				p->sig=head;
				head=head->sig;
				head=p;
				size++;
			}
		}
		
		void insertarFinal(int d){
			Nodo *p=new Nodo (d);			
			if(head==NULL){
				head=p;
				tail=p;
				size=1;
			}			
			else{
				tail->sig=p;
				tail=p;
				size++;
			}
		}
		
		void inserEntreNodosAtras(int d, int y){
			Nodo *p=new Nodo (d);
			Nodo *aux=head;
			while(aux->sig != NULL && aux->sig->dato != y){
				aux=aux->sig;
			}			
			if(aux->sig != NULL){
				p->sig=aux->sig;
				aux->sig=p;
				p=aux;
				size++;
			}
			else
			   cout<<"No Se Encuentra El Dato: "<< y <<endl;		
		}
		
		void inserEntreNodosAdelante(int d, int y){
			Nodo *p=new Nodo (d);
			Nodo *aux=head;
			while(aux != NULL && aux->dato != y){
				aux=aux->sig;
			}			
			if(aux->dato == y){
				p->sig=aux->sig;
				aux->sig=p;
				size++;
			}
			else
			   cout<<"No Se Encuentra El Dato: "<< y <<endl;
		}
		
		void eliminarInicio(){
			Nodo *p=head;			
			head=head->sig;
			delete p;
			size--;
		}

		void eliminarFinal(){
			Nodo *aux=head;			
			while(aux->sig != tail)
			aux=aux->sig;			
			tail=aux;			
			tail->sig=NULL;
			size--;
		}
		
		void eliminar(int d){
			if(head->dato==d){
				eliminarInicio();
			}			
			else if(d==tail->dato){
				eliminarFinal();
			}			
			else{
				Nodo *temp=head->sig;
				Nodo *ant=head;				
				while(temp!=NULL && temp->dato != d){
					ant=ant->sig;
					temp=temp->sig;
					}
				if(temp!=NULL){
					ant->sig=temp->sig;
					if(temp==tail){
						tail=ant;
					}
					size--;
				}
				else{
					cout<<"No existe el Valor: "<<d<<endl;
				}
			}
		}
		
		void ordenar(){
			Nodo *aux1=head;
			Nodo *aux2=head->sig;
			int t;	
		while(aux1->sig != NULL){
			aux2=aux1->sig;
			while(aux2 != NULL){
				if(aux1->dato >= aux2->dato){
					t=aux2->dato;
					aux2->dato=aux1->dato;
					aux1->dato=t;
				}
				aux2=aux2->sig;
			}
			aux1=aux1->sig;
			aux2=aux1->sig;
		}
		cout<<"Lista Ordenada: "<<endl;
		mostrar();
		}

		void mostrar(){
			Nodo *p=head;
			while(p!=NULL){
				cout<< p->dato <<" --> ";
				p=p->sig;
			}
			cout<<endl;
		}
		
		void buscar(int dat){
			Nodo *aux=head;
			int pos=1;
			while(aux!=NULL && aux->dato!=dat){
				aux=aux->sig;
				pos=pos+1;
			};
			if(aux != NULL){
				cout<<"Se Encuentra El Dato En La Posicion: "<<pos<<endl;
			}
			else{				
			   cout<<"No Existe El Dato: "<<dat<<endl;
			}
		}
};


int main(){
	listaLigada obj;
	
	int opc, opc2;
	int valor1, valor2;
	do{
		cout<<"Ingrese Opcion:"<<endl
			<<"***************************"<<endl
			<<"1. Insertar Inicio"<<endl
			<<"2. Insertar Final"<<endl
			<<"3. Insertar Entre Nodos"<<endl
			<<"4. Eliminar Inicio"<<endl
			<<"5. Eliminar Final"<<endl
			<<"6. Eliminar"<<endl
			<<"7. Ordenar"<<endl
			<<"8. Buscar"<<endl
			<<"9. Salir"<<endl
			<<"**************************"<<endl
			<<"Opcion: ";
		cin>>opc;
		cout<<endl;		
	switch(opc){	
	case 1:
		cout<<"Ingresa Valor A Insertar: ";
		cin>>valor1;
		cout<<endl;
		
		obj.insertarInicio(valor1);
		obj.mostrar();
		break;
	case 2:
		cout<<"Ingresa Valor A Insertar: ";
		cin>>valor1;
		cout<<endl;
		
		obj.insertarFinal(valor1);
		obj.mostrar();
		break;
	case 3:
		do{
			cout<<"Ingrese Opcion:"<<endl
				<<"***************************"<<endl
				<<"1. Insertar Antes"<<endl
				<<"2. Insertar Despues"<<endl
				<<"3. Regresar"<<endl
				<<"**************************"<<endl
				<<"Opcion: ";
			cin>>opc2;
			cout<<endl;
			switch(opc2){
			case 1:
				cout<<"Ingresa Valor A Insertar: ";
				cin>>valor1;
				cout<<endl;
				cout<<"Ingresa Detras De Que Valor Insertar: ";
				cin>>valor2;
				cout<<endl;				
				obj.inserEntreNodosAtras(valor1,valor2);
				obj.mostrar();
				break;				
			case 2:
				cout<<"Ingresa Valor A Insertar: ";
				cin>>valor1;
				cout<<endl;
				cout<<"Ingresa Adelante De Que Valor Insertar: ";
				cin>>valor2;
				cout<<endl;				
				obj.inserEntreNodosAdelante(valor1,valor2);
				obj.mostrar();
				break;
			}
		} while(opc2!=3);		
		break;
	case 4:
		cout<<"Eliminando Inicio..."<<endl;
		obj.eliminarInicio();
		obj.mostrar();
		break;
	case 5:
		cout<<"Eliminando Final..."<<endl;
		obj.eliminarFinal();
		obj.mostrar();
		break;
	case 6:
		cout<<"Valor A Eliminar: ";
		cin>>valor1;
		cout<<endl;
		cout<<"Eliminando "<<valor1<<"..."<<endl;
		obj.eliminar(valor1);
		obj.mostrar();
		break;		
	case 7:
		cout<<"Ordenando..."<<endl;
		obj.ordenar();
		break;
	case 8:
		cout<<"Ingresa Valor A Buscar: ";
		cin>>valor1;
		obj.buscar(valor1);
		break;	
	case 9:
		cout<<"SALIENDO..."<<endl;
		break;
	}	
	} while(opc!=9);
	return 0;
}
