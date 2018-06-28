#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;


class funcion{
private:
	string signo;
	float coeficioente;
	string variable;
	float exponente;
	
public:
	funcion(string signo="+", float coeficioente=1, string variable=" ", float exponente=1){
		this->signo=signo;
		this->coeficioente=coeficioente;
		this->variable=variable;
		this->exponente=exponente;
	}
	
	bool gradoExponente(){
	string opcion;
	cout<<"Tiene exponente: "<<endl
		<<"No ( n )    Si ( s )  ---> ";
	cin>>opcion;
	cout<<endl;
	if(opcion=="n"){
	return false;
	}
	else {
	return true;	
	}
	
	}
	
	
	void ingresaMonomio(){
		cout<<"Ingrese su Monomio "<<endl
			<<"Ingrese signo: ";
		cin>>signo;
		cout<<endl<<"Ingrese coeficioente: ";
		cin>>coeficioente;
		
		if(gradoExponente()==true ){
		cout<<endl<<"Ingrese exponente: ";
		cin>>exponente;
		}
		else{
			exponente=1;
		}
		
		cout<<endl<<endl<<endl;
	}
	
	void ingreseVar(){
		cout<<"Ingrese una variable: "<<endl
			<<"Por ejemplo...  \"F(x)\" ";
		cin>>variable;
		cout<<endl<<endl;
	}
	
	
	float cambioDeSigno(){
		if(signo=="-"){
			return coeficioente=coeficioente* (-1);
		}
		else 
		   return coeficioente;
	}
	
	void mostrarMonomio(){
		cambioDeSigno();
		if(signo=="+"){
			cout<<signo<<coeficioente<<" "<<variable<<"^"<<exponente;
		}
		else
		cout<<coeficioente<<" "<<variable<<"^"<<exponente;
	}
	
	
	funcion crearFuncion(int numFunciones, float valorConstante){
		ingreseVar();
		
		funcion *funcionCompleta=new funcion [numFunciones];
			
		for(int i=1; i<=numFunciones; i++){
		funcionCompleta[i].ingresaMonomio();
		
		}
		cout<<endl<<endl;
	 }
	
	
	 float evaluacionDeFuncionRango(int inicioRango, int finalRango ){
		 float resultado=0;
		 for(int i=inicioRango; i<=finalRango; i++){
			 mostrarMonomio();
			 resultado=coeficioente* pow(exponente, i);
			 cout<<"<---------->"<<variable<<"=="<<i<<"				"<<resultado<<endl;
		 }
		//return resultado;
	 }
};

int main(int argc, char *argv[]) {
	funcion fun1;
	
	fun1.ingresaMonomio();
	fun1.ingreseVar();
	
	fun1.mostrarMonomio();
	cout<<endl<<endl;
	
	
	int numTerminos=0;
	float valorConstante=0;
	cout<<"Ingresa cuantos terminos con incognita tiene la funcion: ";
	cin>>numTerminos;
	cout<<endl<<"Ingresa el valor constante: ";
	cin>>valorConstante;
	cout<<endl<<endl;
	//fun1.crearFuncion(numTerminos, valorConstante);
	
	int inicioR, finR;
	cout<<"Ingrese inicio Y final del rango a evaluar: ";
	cin>>inicioR>>finR;
	cout<<endl<<endl;
	
	fun1.evaluacionDeFuncionRango(inicioR, finR);
	
	
	return 0;
}

