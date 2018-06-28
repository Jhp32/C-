#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
class tablaHash{
private:	
	char palabra[10];
	char taHash[16][10];
	
public:
	tablaHash();
	tablaHash(char*palabra);
	void llenarTabla();
	void ingresaPalabra();
	int valorPalabra(char*palabra);
	void mostrar();
	void mapeo(char*palabra, int x, int intento);
	void buscarVacio(char*palabra, int intento);
	void ingresaPalabraBA();
	void busqueda(char*palabra, int pos, int intento);
	void eliminar(int posicion);	
};
tablaHash::tablaHash(){
	llenarTabla();
}
void tablaHash::llenarTabla(){
	for (int i=0; i<=16; i++){
		int j=0;
		do{
			taHash[i][j]='-';
			j++;
		}while(j<=10);
					
		}
}	
void tablaHash::ingresaPalabra(){
	cout<<"Ingresa Palabra: ";
	cin>>palabra;
	int x;
	x=valorPalabra(palabra);
	mapeo(palabra,x, 0);
}
int tablaHash::valorPalabra(char*palabra){
	int suma, inicio, fin;
	inicio=palabra[0];
	fin=palabra[strlen(palabra)-1];
	suma=inicio+fin;
	suma=suma%16;
	return suma;
}

void tablaHash::mostrar(){
	for(int i=0; i<=16; i++){
		cout<<"Slot "<<i<<" : ";
		for(int j=1; j<=10; j++){
			cout<<taHash[i][j];
		}
		cout<<endl;
	}
}
void tablaHash::mapeo(char*palabra, int var, int intento){
	if(taHash[var][1]=='-'){
		for(int i=1; i<=10; i++){
				taHash[var][i]=palabra[i-1];
				
			}
		for(int j=strlen(palabra)+1; j<10; j++){
				taHash[var][j+1]=' ';
			}
	}
	else{
		intento=intento+1;
		buscarVacio(palabra, intento);
	}
}
void tablaHash::buscarVacio(char*palabra, int intento){
	int valor2;
	int suma, inicio, fin;
	inicio=palabra[0];
	fin=palabra[strlen(palabra)-1];
	suma=inicio+fin;
	fin=suma%16;
	inicio=16-intento;
	if(inicio==0){
		cout<<"NO SLOT'S VACIOS!!!"<<endl;
	}
	valor2=1+(suma%inicio);
	valor2=valor2*intento;
	valor2=fin+valor2;
	valor2=valor2%16;
	mapeo(palabra, valor2, intento);
}

void tablaHash::ingresaPalabraBA(){
	cout<<"Ingresa Palabra: ";
	cin>>palabra;	
	int var;
	var=valorPalabra(palabra);
	busqueda(palabra,var,0);
}

void tablaHash::busqueda(char*palabra, int pos, int intento){
	int aux=0;
	bool comp;
	for(int i=1; i<=10; i++){
		if(taHash[pos][i]==palabra[i-1]){
			aux=aux+1;
		}
		aux=aux-1;
	}
	if(aux==strlen(palabra) ){
				comp=true;
	}
	else
	   comp=false;
	
	if(comp==true){
		char desi;
		cout<<"Palabra Encontrada en la posicion: "<<pos<<endl
			<<"**************"<<endl
			<<"Desea Eliminar La Palabra "<<taHash[pos]<<" : s) o n) --> ";
		cin>>desi;
		cout<<endl;
		if(desi=='s'){
			eliminar(pos);
		}
	}
	else{
		int valor2;
		int suma, inicio, fin;
		intento=intento+1;
		inicio=palabra[0];
		fin=palabra[strlen(palabra)-1];
		suma=inicio+fin;
		fin=suma%16;
		inicio=16-intento;
		
		if(inicio==0){
			cout<<"NO SE ENCUENTRA LA PALABRA!!!"<<endl;
			
		}
		else{
			valor2=1+(suma%inicio);
			valor2=valor2*intento;
			valor2=fin+valor2;
			valor2=valor2%16;
			busqueda(palabra, valor2, intento);
		}
		
	}

}

void tablaHash::eliminar(int posicion){
	cout<<"Se ha eliminado la palabra: "<<taHash[posicion]<<endl;
	for(int i=1; i<=10; i++){
		taHash[posicion][i]='-';
	}
}

int main(int argc, char *argv[]) {
	tablaHash obj;
	//obj.mostrar();
	
	int opc;
	do{
		cout<<"Ingrese Opcion:"<<endl
			<<"***************************"<<endl
			<<"1. Insertar Palabra"<<endl
			<<"2. Mostrar"<<endl
			<<"3. Buscar/Eliminar"<<endl
			<<"4. Salir"<<endl
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
			obj.ingresaPalabraBA();
			obj.mostrar();
			break;
		case 4:
			cout<<"SALIENDO..."<<endl;
			break;
		}
	} while(opc!=4);


	return 0;
}

