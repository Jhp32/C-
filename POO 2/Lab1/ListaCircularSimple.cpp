#include <iostream>
using namespace std;

class Nodo{
public:
	int dato;
	Nodo *sig;
	
	Nodo(){
		dato=0;
		sig=NULL;
	}

	Nodo(int dato){
		this->dato=dato;
		sig=NULL;
	}
	
};

class listaLigadaCircular{
private:
	int size;
	Nodo *primero;
	Nodo *ultimo;
	
public:
		listaLigadaCircular(){
			size=0;
			primero=NULL;
			ultimo=NULL;
	}

	
	void ingresaInicio(int d){
		Nodo *p=new Nodo(d);
		
		if(primero==NULL){
			primero=ultimo=p;
			ultimo->sig=primero;
		}
		else{
			p->sig=primero;
			primero=primero->sig;
			primero=p;						
		}
	}
	
	void ingresarFinal(int d){
		Nodo *p=new Nodo(d);
		if(primero==NULL){
			primero=ultimo=p;
			ultimo->sig=primero;
		}
		else{
			ultimo->sig=p;
			ultimo=p;
			p->sig=primero;			
		}
		
	}
	
	void inserEntreNodosAtras(int d, int y){
		Nodo *p=new Nodo (d);
		Nodo *aux=primero;
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
		Nodo *aux=primero;
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
	
	void borrarInicio(){
		if(primero==NULL){
				cout<<"No Se Puede Eliminar... Lista Vacia."<<endl;
		}
		else{
			if(primero==ultimo){
				ultimo=primero=NULL;
				cout<<"Elemento Eliminado..."<<endl;
			}
			else{
				Nodo *temp=primero;
				primero=primero->sig;
				ultimo->sig=primero;
				cout<<"Eliminado: "<<temp->dato<<endl;
				delete temp;
			}
		}
		
	}
	
	void borrarFinal(){
		if(primero==NULL){
			cout<<"No Se Puede Eliminar... Lista Vacia."<<endl;
		}
		else if(primero==ultimo){
			primero=ultimo=NULL;
		}
		else{
			bool seguir=true;
			Nodo *aux=primero;
			
			while(seguir){
				if(aux->sig==ultimo){
					Nodo *temp=ultimo;
					ultimo=aux;
					ultimo->sig=primero;
					delete temp;
					
					seguir=false;
				}
				else{
					aux=aux->sig;
				}
			}
				
		}
		
	}
	
	void mostrar(){
		if(primero==NULL){
			cout<<"Lista Vacia."<<endl;
		}
		else{
			Nodo *aux=primero;
			bool seguir=true;
			
			while(seguir){
				cout<<aux->dato<<"--->";
				if(aux==ultimo){
					seguir=false;
				}
				aux=aux->sig;
			}
		}
		cout<<endl;
	}
	
	void eliminar(int d){
		if(primero->dato==d){
			borrarInicio();
		}		
		else if(d==ultimo->dato){
			borrarFinal();
		}		
		else{
			Nodo *temp=primero->sig;
			Nodo *aux=primero;			
			while(temp!=NULL && temp->dato != d){
				aux=aux->sig;
				temp=temp->sig;
			}
			if(temp!=NULL){
				aux->sig=temp->sig;
				if(temp==ultimo){
					ultimo=aux;
				}
				size--;
			}
			else{
				cout<<"No existe el Valor: "<<d<<endl;
			}
		}
	}
	
	void ordenar(){
		Nodo *aux1=primero;
		Nodo *aux2=primero->sig;
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
	
	void buscar(int dat){
			Nodo *aux=primero;
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
		
		void mostrarCir(int ciclos){
			if(primero==NULL){
				cout<<"Lista Vacia."<<endl;
			}
			else{
				for(int i=0; i<ciclos; i++){
					mostrar();
					cout<<endl;
				}
				
			}
			cout<<endl;
		}
};

int main(int argc, char *argv[]) {
	
	listaLigadaCircular obj;
	
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
			<<"9. Mostrar Lista Circulo"<<endl
			<<"10. Salir "<<endl
			<<"**************************"<<endl
			<<"Opcion: ";
		cin>>opc;
		cout<<endl;
		
		switch(opc){
			
			
		case 1:
			cout<<"Ingresa Valor A Insertar: ";
			cin>>valor1;
			cout<<endl;
			
			obj.ingresaInicio(valor1);
			obj.mostrar();
			break;
		case 2:
			cout<<"Ingresa Valor A Insertar: ";
			cin>>valor1;
			cout<<endl;
			
			obj.ingresarFinal(valor1);
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
			obj.borrarInicio();
			obj.mostrar();
			break;
		case 5:
			cout<<"Eliminando Final..."<<endl;
			obj.borrarFinal();
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
			cout<<"Cuantas Veces Desea Mostrar: ";
			cin>>valor1;
			obj.mostrarCir(valor1);
		break;
		case 10:
			cout<<"SALIENDO..."<<endl;
			break;
			
			
			
		}
		
	} while(opc!=10);
	
	return 0;
}
