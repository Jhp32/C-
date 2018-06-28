#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) {
	string nombre;
	cout<<"Ingresa el nombre del archivo y su extencion: ";
	cin>>nombre;
	cout<<endl;
	ifstream entrada(nombre.c_str() );	
	
	if(entrada.fail() ){
		cout<<"ERROR AL INGRESAR AL FICHERO..."<<endl;
	}
	
	int numLineas;
	cout<<"Ingresa cuantas lineas mostrar: ";
	cin>>numLineas;
	cout<<endl;
	
	string renglon;
	int contador=0;
	
	while(!entrada.eof() ){
		getline(entrada, renglon);
		cout<<contador+1<<")  "<<renglon<<endl;
		contador++;
		if(contador%numLineas==0){
			system("pause");
		}
		
	}
	
	

	entrada.close();
		
	return 0;
}

