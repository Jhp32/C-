#include <iostream>
using namespace std;

class Counter{
private: 
	double value;
	
public: 
	Counter(double value){
		this->value=value;
	}
	Counter(){
		value=0.0;
	}
	double incrementar(){
		return value+1;
	}
	double decrementar(){
		return value-1;
	}	
	void mostrar(){
		cout<<value<<endl;
	}
	
	friend void reset(double v1, Counter &valor1){
		valor1.value=v1;
	}
};






int main(int argc, char *argv[]) {
	
	double var1;
	cout<<"Valor de la primera variable: ";
	cin>>var1;
	cout<<endl;
	Counter x(var1);
	x.mostrar();
	cout<<"Incremento: "<<x.incrementar()<<endl
		<<"Decremento: "<<x.decrementar()<<endl;
	
	cout<<endl;
	
	double var2;
	cout<<"Ingresa el nuevo valor: ";
	cin>>var2;
	cout<<endl;
	reset(var2,x);
	x.mostrar();
	cout<<"Incremento: "<<x.incrementar()<<endl
		<<"Decremento: "<<x.decrementar()<<endl;
	
	
	
	
	return 0;
}

