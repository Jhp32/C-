#include <iostream>
using namespace std;

class Nodo{
	public:
	string nombre;
	int edad;
	string telefono;
	string email;
	
	Nodo *sig;
	Nodo *ant;
	
	Nodo(){
		nombre="Ninguno";
		edad=0;
		telefono="000000";
		email="Designado";
		sig=NULL;
		ant=NULL;
	}
	Nodo(string nombre, int edad, string telefono, string email){
		this->nombre=nombre;
		this->edad=edad;
		this->telefono=telefono;
		this->email=email;
		
		sig=NULL;
		ant=NULL;
	}
	
	void mostrar(){
		cout<<"Nombre: "
	}
	
};


class listaLigPersona{
	private:
		int size;
		Nodo *inicio;
		Nodo *final;
		
		public:
			listaLigPersona(){
				size=0;
				inicio=NULL;
				final=NULL;
			}
			
			void insertarFinal(string nombre, int edad, string telefono, string email){
				Nodo *p=new Nodo (nombre, edad, telefono, email);
				
				if(inicio==NULL){
					inicio=p;
					final=p;
					size=1;
				}
				else {
					final->sig=p;
					p->ant=final;
					final=p;
					size++;
				}
			}
			
			void insertarInicio{
				Nodo *p=new Nodo (nombre, edad, telefono, email);
				
				if(inicio==NULL){
					inicio=p;
					final=p;
					size=1;
				}
				else {
					p->sig=inicio;
					inicio->ant=p;
					inicio=p;
					size++;
				}
			}
			
			void mostrar(){
				Nodo *p=inicio;
				
				while(p!=NULL){
					cout<<p->nombre<<endl
						<<p->edad<<endl
						<<p->telefono<<endl
						<<p->email<<endl
						<<"------->";
						
						p=p->sig;
				}
				cout<<endl;
			}
			
};
