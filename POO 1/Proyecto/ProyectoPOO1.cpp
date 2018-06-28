# include <iostream>

using namespace std;

class Nodo {
	public:
		Nodo *sig ;
		Nodo *ant;
		int numero;
		int suicidar;
	public:
		Nodo(int a){
			sig=NULL;
			ant=NULL;
			numero=a;
			suicidar=NULL;			
		}
};
class lista{
	private: 
		Nodo *inicio;
		Nodo *fin;
		Nodo *aux;
	public:
		
		lista(){
			inicio=aux=fin=NULL;
		}
		
		void insertar(int a){
			Nodo *n=new Nodo(a);
			if(inicio==NULL){
				inicio=n;
				fin=n;
			}
			else{
				n->ant=fin;
				fin->sig=n;
				fin=n;
				fin->sig=inicio;
				inicio->ant=fin;
			}
		}
		
		void eliminar(Nodo *a){
			a->sig->ant=a->ant;
			a->ant->sig=a->sig;
			if(inicio==a){
				inicio=inicio->sig;
			}
			else if(fin==a){
				fin=fin->ant;
			}
			delete a;
		}
		
		void mostrar(){
			aux=inicio;
			if(inicio==NULL)		
				cout<<"no hay soldados"<<endl;
			else
				do{	cout<< aux->numero <<" -> ";
						aux=aux->sig;
				}while(aux!=inicio) ;
		}
		
		void morir(int a, Nodo *b){
			mostrar();
			cout<<endl;
			while(b->sig!=b){
				for(int i=0;i<a-1;i++){
					b=b->sig;
				}	
				aux=b->sig;
				cout<<"Soldado eliminado: "<<b->numero<<endl;
				eliminar(b);
				b=aux;
				mostrar();cout<<endl;
			}
			eliminar(b);
		}
		
		Nodo *in(){
			return inicio;
		}
};
int main (){
	lista n ;
	int i,sold,dead;
	cout<<"Numero de soldados: ";
	cin>>i;
	for(sold=0;sold<i;sold++){
		n.insertar(sold+1);
	}
	cout<<"Suicidar cada: ";
	cin>>dead;
	n.morir(dead,n.in());
}
