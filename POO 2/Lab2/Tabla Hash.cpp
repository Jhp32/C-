#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
class tablaHash{
private:
	char palabra[10];
	char taHash[16][10];
	
public:
	tablaHash(){
		llenarTabla();
	}
	void llenarTabla(){
		for (int i=0; i<=16; i++){
			for (int j=0; j<=10; j++){
				taHash[i][j]='-';
			}
		}
	}	
	
	void ingresaPalabra(){
		cout<<"Ingresa Palabra: ";
		cin>>palabra;
		valorPalabra(palabra);
		mapeo(palabra);
	}
	
	int valorPalabra(char*palabra){
		int suma, inicio, fin;
		inicio=palabra[0];
		fin=palabra[strlen(palabra)-1];
		suma=inicio+fin;
		suma=suma%16;
		return suma;
	}
	
	void mapeo(char*palabra){
		if(taHash[valorPalabra(palabra)][1] != '-'){
			char des;
			cout<<"Este Espacio Se Encuentra Ocupado!!!"<<endl
				<<"Desea Modificarlo? s) n) --->";
			cin>>des;
			cout<<endl;
				if(des=='s'){
					for(int i=1; i<=10; i++){
						taHash[valorPalabra(palabra)][i]=palabra[i-1];
					}
					for(int j=strlen(palabra)+1; j<10; j++){
						taHash[valorPalabra(palabra)][j+1]=' ';
					}
				}
				else{
					cout<<"No se modifico"<<endl;
				}
		}
		else{
			for(int i=1; i<=10; i++){
				taHash[valorPalabra(palabra)][i]=palabra[i-1];
			}
			for(int j=strlen(palabra)+1; j<10; j++){
				taHash[valorPalabra(palabra)][j+1]=' ';
			}
		}
	}
	
	void mostrar(){
		for(int i=1; i<=16; i++){
			cout<<"Palabra "<<i<<" : ";
			for(int j=1; j<=10; j++){
				cout<<taHash[i][j];
			}
			cout<<endl;
		}
	}
};

int main(int argc, char *argv[]) {
	tablaHash obj;
	int opc;
	do{
		cout<<"Ingrese Opcion:"<<endl
			<<"***************************"<<endl
			<<"1. Insertar Palabra"<<endl
			<<"2. Mostrar"<<endl
			<<"3. Salir"<<endl
			<<"**************************"<<endl
			<<"Opcion: ";
		cin>>opc;
		cout<<endl;
		switch(opc){
		case 1:
			obj.ingresaPalabra();
			obj.mostrar();
			break;
		case 2:
			obj.mostrar();
			break;
		case 3:
			cout<<"SALIENDO..."<<endl;
			break;
		}
	} while(opc!=3);
	return 0;
}

