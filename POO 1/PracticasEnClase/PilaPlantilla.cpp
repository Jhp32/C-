#include <iostream>
#include "SobreCFraccion.cpp"
using namespace std;

template <class T, int Max>
class Stack{
private:
	int sp;
	T *pila;
	T MaxPila;
	
public:
	Stack(){
		sp=1;
		MaxPila=Max;
		pila=new T [Max];
	}
	
	~Stack(){
		delete []pila;
	}
	
	bool PilaLlena(){
		//return ( sp>=MaxPila );
		//return(sp>=Max);
		return (sp>Max);
	}
	
	bool PilaVacia(){
		//return (sp<=0);
		return(sp==1);
	}
	
	void push(T d){
		if(PilaLlena()==true){
			cout<<"La Pila Esta Llena..."<<endl;
		}
		else{
			pila[sp] = d;
			sp++;
		}
	}
	
	T pop(){
		if(!PilaVacia()){
			sp=sp-1;
		}
		return pila[sp];
	}
	
	void mostrar(){
		cout<<"Estado De La Pila: "<<endl;
		/*
		for(int i=sp-1; i>=0; i--){
			cout<<"Elemento "<<i+1<<"--->"<<pila[i]<<endl;
		}
		*/
		for(int i=sp; i==1; i--){
			cout<<"Elemento--> "<<i<<" ---> "<<pila[i]<<endl;
		}
	}
	
	/*T mostrarUltimo(){
		return ( pila[Max] ) ;
	}
	*/
	
};


int main(){
	int opcion;
	int submenu1;
	int submenu2;
	int submenu3;
	int submenu4;
	int submenu5;

	
	do{		
	cout<<"\n\n"
		<<"*-*-*-*-*-*-*PILA*-*-*-*-*-*-*-*"
		<<endl
		<<endl
		<<"********************************"
		<<endl
		<<"1. Enteros->(int)"<<endl
		<<"2. Flotantes->(float)"<<endl
		<<"3. Cadenas->(string)"<<endl
		<<"4. Caracteres->(char)"<<endl
		<<"5. Fracciones->(SobreCFraccion)"<<endl
		<<"6. Salir\n"
		<<"********************************"
		<<endl
		<<"		Opcion--> ";
	cin>>opcion;
	cout<<endl;
	
	switch(opcion){
		
		do{
	case 1:
		Stack <int, 6> enteros;		

			cout<<"\n\n"
				<<"*-*-*-*-*ENTEROS*-*-*-*-*"
				<<endl
				<<endl
				<<"************************"
				<<endl
				<<"1. PUSH->(agregar)"<<endl
				<<"2. POP->(eliminar)"<<endl
				<<"3. MOSTRAR"<<endl
				<<"4. REGRESAR"<<endl
				<<"************************"
				<<endl
				<<"		Ingresa Opcion-> ";
			cin>>submenu1;
			
			switch(submenu1){
			case 1:
				int valor;
				cout<<"Ingrese valor a agregar: ";
				cin>>valor;
				enteros.push(valor);
				break;				
			case 2:
				cout<<"Eliminando el valor... "<<enteros.pop()<<endl;
				enteros.pop();
				break;				
			case 3:
				enteros.mostrar();
				break;
			case 4:
				cout<<opcion<<endl;
				break;
			}					
		} while(submenu1!=4);
		
		break;
		
		
		do{
	case 2:
		Stack <float, 6> flotantes;
				
			cout<<"\n\n"
				<<"*-*-*-*FLOTANTES*-*-*-*"
				<<endl
				<<endl
				<<"************************"
				<<endl
				<<"1. PUSH->(agregar)"<<endl
				<<"2. POP->(eliminar)"<<endl
				<<"3. MOSTRAR"<<endl
				<<"4. REGRESAR"<<endl
				<<"************************"
				<<endl
				<<"		Ingresa Opcion-> ";
			cin>>submenu2;			
			switch(submenu2){
			case 1:
				float valor;
				cout<<"Ingrese valor a agregar: ";
				cin>>valor;
				flotantes.push(valor);
				break;				
			case 2:
				cout<<"Eliminando el valor... "<<flotantes.pop()<<endl;
				flotantes.pop();
				break;				
			case 3:
				flotantes.mostrar();
				break;
			case 4:
				cout<<opcion<<endl;
				break;
			}					
		} while(submenu2!=4);
		break;
		
		do{
	case 3:
		Stack <string, 6> cadenas;
		string valor;
		
			cout<<"\n\n"
				<<"*-*-*-*-*CADENAS*-*-*-*-*"
				<<endl
				<<endl
				<<"************************"
				<<endl
				<<"1. PUSH->(agregar)"<<endl
				<<"2. POP->(eliminar)"<<endl
				<<"3. MOSTRAR"<<endl
				<<"4. REGRESAR"<<endl
				<<"************************"
				<<endl
				<<"		Ingresa Opcion-> ";
			cin>>submenu3;
			
			switch(submenu3){
			case 1:
				
				cout<<"Ingrese valor a agregar: ";
				cin>>valor;
				cadenas.push(valor);				
				break;
				
			case 2:
						
				cout<<"Eliminando el valor... "<<cadenas.pop()<<endl;
				cadenas.pop();
							
				break;
				
			case 3:
				cadenas.mostrar();
				break;
				
			case 4:
				cout<<opcion<<endl;
				break;
			}						
		} while(submenu3!=4);
		
		break;
		
	do{
	case 4:
		Stack <char, 6> caracteres;
		
			cout<<"\n\n"
				<<"*-*-*-*-*CARACTERES*-*-*-*-*"
				<<endl
				<<endl
				<<"************************"
				<<endl
				<<"1. PUSH->(agregar)"<<endl
				<<"2. POP->(eliminar)"<<endl
				<<"3. MOSTRAR"<<endl
				<<"4. REGRESAR"<<endl
				<<"************************"
				<<endl
				<<"		Ingresa Opcion-> ";
			cin>>submenu4;
			
			switch(submenu4){
			case 1:
				char valor;
				cout<<"Ingrese valor a agregar: ";
				cin>>valor;
				caracteres.push(valor);
				break;				
			case 2:
				cout<<"Eliminando el valor... "<<caracteres.pop()<<endl;
				caracteres.pop();
				break;				
			case 3:
				caracteres.mostrar();
				break;
			case 4:
				cout<<opcion<<endl;
				break;
			}
			
		} while(submenu4<4);
		break;

	
		do{
	case 5:
		Stack <SobreCFraccion, 6> Fraccion;
		SobreCFraccion valor;
		
			cout<<"\n\n"
				<<"*-*-*-*-*FRACCION*-*-*-*-*"
				<<endl
				<<endl
				<<"************************"
				<<endl
				<<"1. PUSH->(agregar)"<<endl
				<<"2. POP->(eliminar)"<<endl
				<<"3. MOSTRAR"<<endl
				<<"4. REGRESAR"<<endl
				<<"************************"
				<<endl
				<<"		Ingresa Opcion-> ";
			cin>>submenu5;
			
			switch(submenu5){
			case 1:
				
				cout<<"Ingrese valor a agregar: ";
				cin>>valor;
				Fraccion.push(valor);
				break;				
			case 2:
				cout<<"Eliminando el valor... ";
				//cout<<Fraccion.pop()<<endl;
				Fraccion.pop();
				break;				
			case 3:
				//cout<<mostrar();
				Fraccion.mostrar();
				break;
			case 4:
				cout<<opcion<<endl;
				break;
			}					
		} while(submenu5!=4);
		break;
		
	case 6:
		cout<<"Saliendo..."<<endl;
		
		break;
		}
	} while(opcion<6);

	return 0;
}

