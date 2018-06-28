#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

class nodo{
public:
	int valor;
	nodo *hijo;
	nodo *hermano;
	
	nodo(int a){
		valor=a;
		hijo=NULL;
		hermano=NULL;
	}
};
class Arbol{
private:
	nodo *raiz;
public:
	Arbol(){
		raiz=NULL;
	}
	void inser_raiz(int x){
		nodo *p=new nodo(x); //creo mi raiz con un nuevo nodo
		raiz = p;
		
	}
	void insertar(nodo *w,int x)	{
		nodo *p=new nodo(x);
		if(w->hijo== NULL){  //inserta como raiz
			
			w->hijo=p;  //igualo mi nuevo nodo con mi w->hijo
		}
		else{
			nodo *l=w->hijo; //crear un nodo del mismo padre 
			while(l->hermano!=NULL){
				l=l->hermano;
			}
			l->hermano=p; 
		}
	}
	
	void buscaref(nodo *head, int e,int y){
		if(head!=NULL){
			nodo *aux;
			if(head->valor!= e){
				buscaref(head->hijo,e,y); //Vuelvo a llamar a la funcion si no lo encuentra el dato
				aux=head->hermano;
				while(aux!=NULL){
					buscaref(aux,e,y);//
					aux=aux->hermano;
				}
				
			}
			else {
				insertar(head,y);
				
			}
		}
	}
	
	void preorden(nodo *head)	{
		if(head!=NULL){
			cout<<head->valor<<"-"; //empiezo a buscar desde mi inicio
			preorden(head->hijo);
			preorden(head->hermano);
		}
	}
	void postOrden(nodo *head)	{
		if(head!=NULL) {
			postOrden(head->hijo);
			postOrden(head->hermano);
			cout<<head->valor<<"-"; //termino buscando con mi inico
		}
	}
	void Eliminar(nodo *head, int e,nodo *y){
		if(head!=NULL){
			nodo *aux;
			if(head->valor!= e){
				Eliminar(head->hijo,e,head);
				aux=head;
				while(aux!=NULL){
					Eliminar(aux->hermano,e,aux);
					aux=aux->hermano;
				}
				
			}
			else {
				if (y->hijo==head){
					y->hijo=head->hermano;
				}
				else{
					y->hermano=head->hermano;
				}
			}
			
			
		}
	}
	
	
	
	nodo* getHead(){
		return raiz;
	}
	
};
int main() {
	Arbol AN;
	int x,y,z,op,cont=0;
	do
	{	    cout<<" ---------------Menu---------------"<<endl;
	cout<<" 1. INSERTAR              "<<endl;
	cout<<" 2. PREORDEN              "<<endl;
	cout<<" 3. POSTORDEN             "<<endl;
	cout<<" 4. ELIMINAR NODO         "<<endl;
	cout<<" 5. SALIR                            "<<endl;
	
	
	cout<<"\n INGRESE OPCION: ";
	cin>> op;
	
	switch(op)
	{		
	case 1:{
		if(cont==0){
			cout<<"Ingrese el dato"<<endl;
			cin>>x;
			
			AN.inser_raiz(x);
			cont++;
		}
		else{
			cout<<"Ingrese el dato"<<endl;
			cin>>x;
			nodo *m=AN.getHead();
			cout<<"Ingrese el padre"<<endl;
			cin>>z;
			AN.buscaref(m,z,x);
			cont++;
		}
		break;
	}
	case 2:{
			cout<<"PreOrden"<<endl;
			nodo *n=AN.getHead();
			AN.preorden(n);
			cout<<endl;
			break;
		}
	case 3:{
				cout<<"PostOrden"<<endl;
				nodo *n=AN.getHead();
				AN.postOrden(n);
				cout<<endl;
				break; 
			}
	case 4:{
					cout<<"Ingrese el dato a elminar"<<endl;
					cin>>x;
					AN.Eliminar(AN.getHead(),x,0);
					break;
				}
	}
	getch();
	system("cls");	
	}while(op!=5);
	return 0;
}
