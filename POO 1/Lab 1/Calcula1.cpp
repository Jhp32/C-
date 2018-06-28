#include <iostream>
#include <cmath>
using namespace std;

class Calculadora{
private:
	float valor1;

public:
	Calculadora(float v1){
		this->valor1=v1;
	}
	Calculadora(){
		valor1=0;
	}
	void setValor1(float v1){
		v1=valor1;
	}
	float getValor1(){
		return valor1;
	}
	float Suma(float valor2){		
		return valor1+valor2;
	}
	float Resta(float valor2){
		return valor1-valor2;
	}
	float Multiplicacion(float valor2){
		return valor1*valor2;
	}

	float Divicion(float valor2){
		return valor1/valor2;
	}
};

int main(int argc, char *argv[]) {
	float x, y;
	cout<<"Ingrese su primer valor: ";
	cin>>x;
	cout<<"\nIngrese su segundo valor: ";
	cin>>y;
	cout<<endl;
	
	Calculadora obj1(x);
	Calculadora obj2(y);

			cout<<"----LA SUMA ES:----"<<endl
				<<obj1.getValor1()<<"+"<<obj2.getValor1()<<"="
				<<obj1.Suma(y)<<endl
				<<"\n\n----LA RESTA ES:----"<<endl
				<<obj1.getValor1()<<"-"<<obj2.getValor1()<<"="
				<<obj1.Resta(y)<<endl
				<<"\n\n----LA MULTIPLICACION ES:----"<<endl
				<<obj1.getValor1()<<"*"<<obj2.getValor1()<<"="
				<<obj1.Multiplicacion(y)<<endl
				<<"\n\n----LA DIVICION ES:----"<<endl
				<<obj1.getValor1()<<"/"<<obj2.getValor1()<<"="
				<<obj1.Divicion(y)<<endl;
	

	return 0;
}

