#include <iostream>
#include <queue>
#include <list>
#include <stack>
using namespace std;

class Arista;
class Vertice{
public:
	Vertice *sig;
	Arista *ady;
	string nombre;
	friend class Grafo;
};
class Arista{
public:
	Arista *sig;
	Vertice *ady;
	int distancia;
	friend class Grafo;
};
class Grafo{
private:
	Vertice *primero;
public:
	Grafo();
	bool vacio();
	int tamano();
	Vertice *getVertice(string nombre);
	void insertaArista(Vertice *origen, Vertice *destino, int distancia);
	void insertaVertice(string nombre);
	void listaAdyacencia();
	void eliminarArista(Vertice *origen, Vertice *destino);
	void eliminarVertice(Vertice *vert);
	void anular();
	void recorridoAnchura(Vertice *origen);
	void recorridoProfundidad(Vertice *origen);
	void primeroAnchura(Vertice *origen, Vertice *destino);
	void primeroProfundidad(Vertice *origen, Vertice *destino);
	void primeroMejor(Vertice *origen, Vertice *destino);
};

Grafo::Grafo(){
	primero=NULL;
}
bool Grafo::vacio(){
	if(primero==NULL)
		return true;
	else
		return false;
}
int Grafo::tamano(){
	int contador=0;
	Vertice *aux=primero;
	while(aux!=NULL){
		contador++;
		aux=aux->sig;
	}
	return contador;
}
Vertice *Grafo::getVertice(string nombre){
	Vertice *aux=primero;
	while(aux!=NULL){
		if(aux->nombre==nombre)
			return aux;
		aux=aux->sig;
	}
	return NULL;
}
void Grafo::insertaVertice(string nombre){
	Vertice *nuevo=new Vertice;
	nuevo->nombre=nombre;
	nuevo->sig=NULL;
	nuevo->ady=NULL;
	if(vacio())
		primero=nuevo;
	else{
		Vertice *aux=primero;
		while(aux->sig!=NULL){
			aux=aux->sig;
		}
		aux->sig=nuevo;
	}
}
void Grafo::insertaArista(Vertice *origen, Vertice *destino, int distancia){
	 Arista *nuevo=new Arista;
	 nuevo->distancia=distancia;
	 nuevo->sig=NULL;
	 nuevo->ady=NULL;
	 
	 Arista *aux=origen->ady;
	 if(aux==NULL){
		 origen->ady=nuevo;
		 nuevo->ady=destino;
	 }
	 else{
		 while(aux->sig!=NULL){
			 aux=aux->sig;
		 }
		 aux->sig=nuevo;
		 nuevo->ady=destino;
	 }
}
void Grafo::listaAdyacencia(){
	Vertice *vertAux=primero;
	Arista *arisAux;
	
	while(vertAux!=NULL){
		cout<<vertAux->nombre<<" -> ";
		arisAux=vertAux->ady;
		while(arisAux!=NULL){
			cout<<arisAux->ady->nombre<<":"<<arisAux->distancia<<"Km"<<" -> ";
			arisAux=arisAux->sig;
		}
		vertAux=vertAux->sig;
		cout<<endl;
	}
}
void Grafo::anular(){
	Vertice *aux;
	while(primero!=NULL){
		aux=primero;
		primero=primero->sig;
		delete(aux);
	}
}
void Grafo::eliminarArista(Vertice *origen, Vertice *destino){
	Arista *actual, *anterior;
	int band=0;
	actual=origen->ady;
	if(actual==NULL){
		cout<<"El Vertice no tiene Aristas"<<endl;
	}
	else if(actual->ady==destino){
	   origen->ady=actual->sig;
	   delete(actual);
	}
	else{
		while(actual!=NULL){
			if(actual->ady==destino){
				band=1;
				anterior->sig=actual->sig;
				delete(actual);
				break;
			}
			anterior=actual;
			actual=actual->sig;
		}
		if(band==0){
			cout<<"Esos vertices no Estan conectados..."<<endl;
		}
		
	}
}
void Grafo::eliminarVertice(Vertice *vert){
	Vertice *actual=primero, *anterior;
	Arista *aux;
	while(actual!=NULL){
		aux=actual->ady;
		while(aux!=NULL){
			if(aux->ady==vert){
				eliminarArista(actual, aux->ady);
				break;
			}
			aux=aux->sig;
		}
		actual=actual->sig;
	}
	actual=primero;
	if(primero==vert){
		primero=primero->sig;
		delete(actual);
	}
	else{
		while(actual!=vert){
			anterior=actual;
			actual=actual->sig;
		}
		anterior->sig=actual->sig;
		delete(actual);
	}	
}
void Grafo::recorridoAnchura(Vertice *origen){
	int band, band2;
	Vertice *actual;
	queue<Vertice*>cola;
	list<Vertice*>lista;
	list<Vertice*>::iterator i;
	
	cola.push(origen);
	while(!cola.empty() ){
		band=0;
		actual=cola.front();
		cola.pop();
		for(i=lista.begin(); i!=lista.end(); i++){
			if(*i==actual){
				band=1;
			}
		}
		if(band==0){
			cout<<actual->nombre<<" , ";
			lista.push_back(actual);
			
			Arista *aux=actual->ady;
			while(aux!=NULL){
				band2=0;
				for(i=lista.begin(); i!=lista.end(); i++){
					if(aux->ady==*i){
						band2=1;
					}
				}
				if(band2==0){
					cola.push(aux->ady);
				}
				aux=aux->sig;
			}
		}
	}
}
void Grafo::recorridoProfundidad(Vertice *origen){
	Vertice *actual;
	int band, band2;
	stack<Vertice*>pila;
	list<Vertice*>lista;
	list<Vertice*>::iterator i;
	
	pila.push(origen);
	while(!pila.empty()){
		band=0;
		actual=pila.top();
		pila.pop();
		
		for(i=lista.begin(); i!=lista.end(); i++){
			if(*i==actual){
				band=1;
				
			}
		}
		if(band==0){
			cout<<actual->nombre<<" , ";
			lista.push_back(actual);
			Arista *aux=actual->ady;
			
			while(aux!=NULL){
				band2=0;
				for(i=lista.begin(); i!=lista.end(); i++){
					if(*i==aux->ady){
						
					}
				}
				if(band2==0){
					pila.push(aux->ady);
				}
				aux=aux->sig;
			}
		}
	}
}
void Grafo::primeroAnchura(Vertice *origen, Vertice *destino){
	typedef pair<Vertice*, Vertice*> verticeVertice;
	queue<Vertice*>cola;
	stack<verticeVertice> pila;
	list<Vertice*> lista;
	Vertice *Verticeactual, *destinoActual;
	list<Vertice*>::iterator i;
	int  band, band2, band3=0;
	Arista *aux;
	
	cola.push(origen);
	while(!cola.empty()){
		band=0;
		Verticeactual=cola.front();
		cola.pop();
		
		for(i=lista.begin(); i!=lista.end(); i++){
			if(Verticeactual==*i){
				band=1;
			}
		}
		if(band==0){
			if(Verticeactual==destino){
				band3=1;
				destinoActual=destino;
				while(!pila.empty()){
					cout<<destinoActual->nombre<<" <-- ";
					while(!pila.empty() && pila.top().second!=destinoActual){
						pila.pop();
					}
					if(!pila.empty()){
						destinoActual=pila.top().first;
					}
				}
			}
			lista.push_back(Verticeactual);
			aux=Verticeactual->ady;
			while(aux!=NULL){
				band2=0;
				for(i=lista.begin(); i!=lista.end(); i++){
					if(aux->ady==*i){
						band2=1;
					}
				}
				if(band2==0){
					cola.push(aux->ady);
					pila.push(verticeVertice(Verticeactual, aux->ady));
				}
				aux=aux->sig;
			}
		}
	}
	if(band3==0){
		cout<<"No hay una ruta entre esos dos vertices..."<<endl;
	}
}
void Grafo::primeroProfundidad(Vertice *origen, Vertice *destino){
	typedef pair<Vertice*, Vertice*> parVertice;
	stack<Vertice*> pila;
	list<Vertice*> lista;
	stack<parVertice> pilaPares;
	Vertice *verticeActual, *destinoActual;
	list<Vertice*>::iterator i;
	int band, band2, band3=0;
	Arista *aux;
	
	
	pila.push(origen);
	while(!pila.empty()){
		band=0;
		verticeActual=pila.top();
		pila.pop();
		
		for(i=lista.begin(); i!=lista.end(); i++){
			if(verticeActual==*i){
			band=1;	
			}
		}
		if(band==0){
			if(verticeActual==destino){
				band3=1;
				destinoActual=destino;
				while(!pilaPares.empty()){
					cout<<destinoActual->nombre<<" <- ";
					while(!pilaPares.empty() && pilaPares.top().second!=destinoActual){
						pilaPares.pop();
					}
					if(!pilaPares.empty()){
						destinoActual=pilaPares.top().first;
					}
				}
				break;
			}
			lista.push_back(verticeActual);
			aux=verticeActual->ady;
			while(aux!=NULL){
				band2=0;
				for(i=lista.begin(); i!=lista.end(); i++){
					if(aux->ady==*i){
						band2=1;
					}
				}
				if(band2==0){
					pila.push(aux->ady);
					pilaPares.push(parVertice(verticeActual, aux->ady));
				}
				aux=aux->sig;
			}
		}
	}
	if(band3==0){
		cout<<"No hay una ruta entre esos dos vertices..."<<endl;
	}
}
bool comparaciones(pair <Vertice*, int>a, pair<Vertice*, int >b){
	return a.second<b.second;
}
void Grafo::primeroMejor(Vertice *origen, Vertice *destino){
	typedef pair<Vertice*, int> verticeCosto;
	typedef pair<Vertice*, Vertice*> verticeVertice;
	list<verticeCosto>listaCostos;
	list<verticeCosto>listaOrdenada;
	stack<verticeVertice>pila;
	int costoActual=0;
	Vertice *verticeActual, *destinoActual;
	Arista *aux;
	list<verticeCosto>::iterator i, j;
	int band, band2=0;
	
	
	listaCostos.push_back(verticeCosto(origen, 0));
	listaOrdenada.push_back(verticeCosto(origen, 0));
	
	while(!listaOrdenada.empty()){
		verticeActual=listaOrdenada.front().first;
		costoActual=listaOrdenada.front().second;
		listaOrdenada.pop_front();
		
		if(verticeActual==destino){
			cout<<"Distancia Recorrida: "<<costoActual<<endl;
			band2=1;
			destinoActual=destino;
			while(!pila.empty()){
				cout<<destinoActual->nombre<<" <- ";
				while(!pila.empty() && pila.top().second!=destinoActual){
					pila.pop();
				}
				if(!pila.empty()){
					destinoActual=pila.top().first;
				}
			}
			break;
		}
		aux=verticeActual->ady;
		while(aux!=NULL){
			band=0;
			costoActual=costoActual+aux->distancia;
			for(i=listaCostos.begin(); i!=listaCostos.end(); i++){
				if(aux->ady==i->first){
					band=1;
					if(costoActual<i->second){
						(*i).second=costoActual;
						for(j=listaOrdenada.begin(); j!=listaOrdenada.end(); i++){
							if(j->first==aux->ady){
								(*j).second=costoActual;
							}
						}
						listaOrdenada.sort(comparaciones);
						pila.push(verticeVertice(verticeActual, aux->ady));
						costoActual=costoActual-aux->distancia;
					}
				}
			}
			if(band==0){
				listaCostos.push_back(verticeCosto(aux->ady, costoActual));
				listaOrdenada.push_back(verticeCosto(aux->ady, costoActual));
				listaOrdenada.sort(comparaciones);
				pila.push(verticeVertice(verticeActual, aux->ady));
				costoActual=costoActual-aux->distancia;
			}
			aux=aux->sig;
		}
	}
	if(band2==0){
		cout<<"No hay una ruta entre esos dos vertices..."<<endl;
	}
}

int main(){
	Grafo inicial;
	Vertice *origen, *destino;
	int  opcion, distancia;
	string ciudad1, ciudad2;
	do{
		cout<<"Ingrese Opcion:"<<endl
			<<"***************************"<<endl
			<<"1. Estado Del Grafo"<<endl
			<<"2. Tamano Del Grafo"<<endl
			<<"3. Insertar Arista"<<endl
			<<"4. Insertar Vertice/Ciudad"<<endl
			<<"5. Lista De Adyacencia"<<endl
			<<"6. Eliminar Arista"<<endl
			<<"7. Eliminar Vertice"<<endl
			<<"8. Eliminar Grafo"<<endl
			<<"9. Recorrido Por Anchura"<<endl
			<<"10. Recorrido Por Profundidad"<<endl
			<<"11. Primero Por Anchura"<<endl
			<<"12. Primero Por Profundidad"<<endl
			<<"13. Menor Distancia"<<endl
			<<"14. Salir"<<endl
			<<"**************************"<<endl
			<<"Opcion: ";
		cin>>opcion;
		cout<<endl;
		switch(opcion){
			case 1:
				if(inicial.vacio()==true){
					cout<<"El Grafo Esta vacio..."<<endl;
				}
				else{
					cout<<"El Grafo NO Esta vacio..."<<endl;
				}
				break;
			case 2:
				cout<<"El Grafo Tiene Un Tamano De: "<<inicial.tamano()<<endl;
				break;
			case 3:
				cout<<"Ingrese La Ciudad Origen: ";
				cin>>ciudad1;
				cout<<endl<<"Ingrese La Ciudad Destino: ";
				cin>>ciudad2;
				cout<<endl<<"Ingrese Distancia: ";
				cin>>distancia;
				cout<<endl;

				origen=inicial.getVertice(ciudad1);
				destino=inicial.getVertice(ciudad2);
				inicial.insertaArista(origen, destino, distancia);
				inicial.listaAdyacencia();
				break;
			case 4:
				cout<<endl<<"Ingrese La Nueva Ciudad: ";
				cin>>ciudad1;
				cout<<endl;
				inicial.insertaVertice(ciudad1);
				break;
			case 5:
				inicial.listaAdyacencia();
				cout<<endl<<endl;
				break;
			case 6:
				cout<<endl<<"Ingrese La Ciudad Origen: ";
				cin>>ciudad1;
				cout<<endl<<"Ingrese La Ciudad Destino: ";
				cin>>ciudad2;
				cout<<endl;
				
				origen=inicial.getVertice(ciudad1);
				destino=inicial.getVertice(ciudad2);
				inicial.eliminarArista(origen, destino);
				cout<<"***********************"<<endl;
				inicial.listaAdyacencia();
				cout<<endl<<endl;
				break;
			case 7:			
				cout<<endl<<"Ingrese La Ciudad: ";
				cin>>ciudad1;
				cout<<endl;

				origen=inicial.getVertice(ciudad1);
				inicial.eliminarVertice(origen);
				cout<<"***********************"<<endl;
				inicial.listaAdyacencia();
				cout<<endl<<endl;
				break;
			case 8:
				inicial.anular();
			break;
			case 9:
				cout<<endl<<"Ingrese La Ciudad Origen: ";
				cin>>ciudad1;
				cout<<endl;

				origen=inicial.getVertice(ciudad1);
				inicial.recorridoAnchura(origen);
				cout<<endl<<endl;
			break;
			case 10:
				cout<<endl<<"Ingrese La Ciudad Origen: ";
				cin>>ciudad1;
				cout<<endl;

				origen=inicial.getVertice(ciudad1);
				inicial.recorridoProfundidad(origen);
				cout<<endl<<endl;
			break;
			case 11:
				cout<<endl<<"Ingrese La Ciudad Origen: ";
				cin>>ciudad1;
				cout<<endl<<"Ingrese La Ciudad Destino: ";
				cin>>ciudad2;
				cout<<endl;

				origen=inicial.getVertice(ciudad1);
				destino=inicial.getVertice(ciudad2);
				inicial.primeroAnchura(origen, destino);
				cout<<endl<<endl;
			break;
			case 12:				
				cout<<endl<<"Ingrese La Ciudad Origen: ";
				cin>>ciudad1;
				cout<<endl<<"Ingrese La Ciudad Destino: ";
				cin>>ciudad2;
				cout<<endl;

				origen=inicial.getVertice(ciudad1);
				destino=inicial.getVertice(ciudad2);
				inicial.primeroProfundidad(origen, destino);
				cout<<endl<<endl;
			break;
			case 13:
				cout<<endl<<"Ingrese La Ciudad Origen: ";
				cin>>ciudad1;
				cout<<endl<<"Ingrese La Ciudad Destino: ";
				cin>>ciudad2;
				cout<<endl;

				origen=inicial.getVertice(ciudad1);
				destino=inicial.getVertice(ciudad2);
				inicial.primeroMejor(origen, destino);
				cout<<endl<<endl;
			break;
			case 14:
			cout<<endl<<"SALIENDO..."<<endl;
			break;

		}

	}while(opcion!=14);	
		
	return 0;
}

