#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int main(int argc, char *argv[]) {
	
	ofstream salida("Funcion.txt");
	
	double inicio, fin;
	cout<<"Ingresa el Inicio y final: ";
	cin>>inicio>>fin;
	cout<<endl;
	float resultado=0.0;
	cout<<"F(x)=3x^3 -5x^2 +3x -2 "<<endl;
	salida<<"F(x)=3x^3 -5x^2 +3x -2 "<<endl;
	for(int i=inicio; i<=fin; i++){
		resultado=3*pow(i,3)-(5*pow(i,2))+3*i -2 ;
		salida<<i<<"<----------->"<<resultado<<endl;
		cout<<i<<"<----------->"<<resultado<<endl;
	}
	salida.close();
		
	
	return 0;
}

