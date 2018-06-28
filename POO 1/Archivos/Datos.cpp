#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[]) {
	ofstream salida("DatosPersonales.txt");
	string nombre, apellido, matricula, correo;
	int edad;
	cout<<"Ingresa Nombre: ";
	cin>>nombre;
	cout<<endl<<"Ingresa Apellido: ";
	cin>>apellido;
	cout<<endl<<"Ingresa Matricula: ";
	cin>>matricula;
	cout<<endl<<"Ingresa Correo: ";
	cin>>correo;
	cout<<endl<<"Ingresa Edad: ";
	cin>>edad;
	
	cout<<setw(5)<<nombre<<setw(10)<<apellido<<setw(5)<<edad
		<<setw(15)<<matricula<<setw(25)<<correo<<endl;
	
	salida<<setw(5)<<nombre<<setw(10)<<apellido<<setw(5)<<edad
		<<setw(15)<<matricula<<setw(25)<<correo<<endl;
	
	salida.close();
	
	return 0;
}

