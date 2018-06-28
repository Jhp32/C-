#include <iostream>
#include <math.h>
using namespace std;

class Nodo{
	public:
		int dato;
		Nodo *sig;
		Nodo *ant;
		
		Nodo(){
			dato=0;
			sig=NULL;
			ant=NULL;
		}
		
		Nodo(int d){
		this->dato=d;
		sig=NULL;
		ant=NULL;
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
		
		void insertarFinal(int d){
			Nodo *p=new Nodo (d);
			
			if(head==NULL){
				head=p;
				tail=p;
				size=1;
			}
			else{
				tail->sig=p;
				p->ant=tail;
				tail=p;
				size++;
			}
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
				head->ant=p;
				head=p;
				size++;
			}
		}
		
		void mostrar(){
			Nodo *p=head;
			
			while(p!=NULL){
				cout<< p->dato <<" --> ";
				p=p->sig;
			}
		cout<<endl;
		}
		
		void eliminarInicio(){
			Nodo *p=head;
			
			head=p->sig;
			p->sig=NULL;
			head->ant=NULL;
			delete p;
		}
		
		void eliminarFinal(){
			Nodo *p=tail;
			
			tail=tail->ant;
			tail->sig=NULL;
			
			delete p;
		}
		
		void eliminar(int d){
			Nodo *p=head;
			
			if(head->dato==d){
				this->eliminarInicio();
			}
			
			else if(d==tail->dato){
				this->eliminarFinal();
			}
			
			else{
				while(p!=NULL){
					if(p->dato==d){
						break;
					}
					p=p->sig;
				}
				
				if(p->dato==d){
					p->ant->sig=p->sig;
					p->sig->ant=p->ant;
					p->sig=NULL;
					p->ant=NULL;
					delete p;
				}
			}
		}


};


int main(){
	listaLigada obj;
	
	
	obj.insertarInicio(7);
	obj.insertarFinal(2);
	obj.insertarFinal(3);
	obj.insertarFinal(9);
	obj.mostrar();
	
	//EL VALOR A ELIMNAR TIENE QUE EXISTIR EN LA LISTA O BOTARA UN ERROR
	obj.eliminar(2);
	
	obj.mostrar();
}
