#include <iostream>
#include <math.h>
using namespace std;
class Complex_No{
private:
	double reales;
	double imaginarios;
	
public:
	Complex_No(double reales, double imaginarios){
		this->reales=reales;
		this->imaginarios=imaginarios;
	}
	Complex_No(){
		reales=0;
		imaginarios=0;
	}
	Complex_No(double Complex_No);
	
	double Magnitud(){
		double r;
		r=sqrt( (reales*reales)+(imaginarios*imaginarios) );
		return r;
	}
	
	Complex_No suma(Complex_No c1){
		Complex_No c2;
		c2.reales=reales+c1.reales;
		c2.imaginarios=imaginarios+c1.imaginarios;
		
		return c2;
	}
	
	
	void mostrar(){
		if(imaginarios>0){
		cout<<reales<<"+"<<imaginarios<<"i";
		}
		else if(imaginarios<0){
			cout<<reales<<imaginarios<<"i";
		}
		else{
			cout<<reales<<"+0i";
			
		}
	}
	
	
};



int main(int argc, char *argv[]) {
	double x1, y1;
	double x2, y2;
	cout<<"Asigna los valores del Numero complejo 1: ";
	cin>>x1>>y1;
	cout<<"\nAsigna los valores del Numero complejo 2: ";
	cin>>x2>>y2;	
	Complex_No Comp1(x1,y1), Comp2(x2,y2);
	cout<<"\n\nNumeros Complejos: "<<endl;
	Comp1.mostrar();
	cout<<endl;
	Comp2.mostrar();
	cout<<endl;
	
	
	cout<<"\n\n---Magnitud---"<<endl;
	Complex_No r;
	cout<<Comp1.Magnitud();
	//r.mostrar();
	cout<<endl;
	
	cout<<Comp2.Magnitud();
	//r.mostrar();
	cout<<endl;
	
	
	cout<<"\n\n---SUMA---"<<endl;
	cout<<"(";
	Comp1.mostrar();
	cout<<") + (";
	Comp2.mostrar();
	cout<<")";
	cout<<"=";
	r=Comp1.suma(Comp2);
	r.mostrar();
	cout<<endl;
	
	
	
	return 0;
}

