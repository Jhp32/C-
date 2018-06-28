#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

int main(int argc, char *argv[]) {
	ifstream entrada("Investigacion.txt");
	
	string palabraBuscar;
	cout<<"Ingresa la palabra a buscar: ";
	cin>>palabraBuscar;
	cout<<endl;
	
	
	string palabra;
	int contador=0;
	
	//FILE * f=NULL;
	
	while(!entrada.eof() ){
		entrada.get(palabra);
		//fsets(entrada, palabra);
		cout<<palabra;
		
		if(palabraBuscar==palabra){
			contador++;
		}

	}
	cout<<"La cantidad de repeticiones de la palabra: "<<palabraBuscar
		<<"es :"<<contador<<endl;
	

	
	
	
	
	entrada.close();
	return 0;
}

