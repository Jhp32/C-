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
	
	Complex_No operator+(Complex_No f){
		Complex_No s;
		s.reales=reales+f.reales;
		s.imaginarios=imaginarios+f.imaginarios;
		return s;
	}
	Complex_No operator-(Complex_No f){
		Complex_No s;
		s.reales=reales-f.reales;
		s.imaginarios=imaginarios-f.imaginarios;
		return s;
	}
	Complex_No operator*(Complex_No f){
		Complex_No s;
		s.reales=(reales*f.reales)-(imaginarios*f.imaginarios);
		s.imaginarios=(reales*f.imaginarios)+(imaginarios*f.reales);
		return s;		
	}
	Complex_No operator/(Complex_No f){
		Complex_No s;
		s.reales=( (reales*f.reales)+(imaginarios*f.imaginarios) )/pow(f.reales,2)+pow(f.imaginarios,2);
		s.imaginarios=( (imaginarios*f.reales)-(reales*f.imaginarios) )/pow(f.reales,2)+pow(f.imaginarios,2);
		return s;
	}
	Complex_No &operator++(){
		reales++;
		imaginarios++;
		return *this;
	}
	Complex_No &operator++(int){
		reales++;
		imaginarios++;
		return *this;
	}
	Complex_No &operator--(){
		reales--;
		imaginarios--;
		return *this;
	}
	Complex_No &operator--(int){
		reales--;
		imaginarios--;
		return *this;
	}
	bool operator>(Complex_No f){
		if(reales*f.imaginarios>imaginarios * f.reales){
			return true;
		}
		else
		   return false;
	}
	bool operator<(Complex_No f){
		if(imaginarios*f.reales<reales*f.imaginarios){
			return true;
		}
		else
		   return false;
	}
	bool operator==(Complex_No f){
		if(reales==f.reales && imaginarios==f.imaginarios){
			return true;
		}
		else
		   return false;
	}
		
	double Magnitud(){
		double r;
		r=sqrt( pow(reales,2)+pow(imaginarios,2) );
		return r;
	}

	
	void mostrar(){
		if(imaginarios>=0){
		cout<<"("<<reales<<" + "<<imaginarios<<"i)";
		}
		else{
			cout<<"("<<reales<<imaginarios<<"i)";
		}
	}
	
	
};


/*
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
	
	Complex_No r;
	cout<<endl<<endl<<"------SUMA------"<<endl;
	Comp1.mostrar(); cout<<" + "; Comp2.mostrar(); cout<<" = ";
	r=Comp1+Comp2;
	r.mostrar();
	
	cout<<endl<<endl<<"-----RESTA-----"<<endl;
	Comp1.mostrar(); cout<<" - "; Comp2.mostrar(); cout<<" = ";
	r=Comp1-Comp2;
	r.mostrar();
	cout<<endl<<endl<<"--MULTPLICACION--"<<endl;
	Comp1.mostrar(); cout<<" * "; Comp2.mostrar(); cout<<" = ";
	r=Comp1*Comp2;
	r.mostrar();
	cout<<endl<<endl<<"-----DIVICION-----"<<endl;
	Comp1.mostrar(); cout<<" / "; Comp2.mostrar(); cout<<" = ";
	r=Comp1/Comp2;
	r.mostrar();
	cout<<endl<<endl;
	
	cout<<"Incrementando Prefijo..."<<endl;
	Comp1.mostrar();
	cout<<" ++  = ";
	r=Comp1++;
	r.mostrar();
	cout<<endl<<endl;
	
	cout<<"Incrementando Postfijo..."<<endl;
	cout<<"++ ";
	Comp2.mostrar();
	cout<<" = ";
	r=Comp2++;
	r.mostrar();
	cout<<endl<<endl;
	
	
	cout<<"Decrementando Prefijo..."<<endl;
	Comp1.mostrar();
	cout<<" --  = ";
	r=Comp1--;
	r.mostrar();
	cout<<endl<<endl;
	
	cout<<"Decrementando Postfijo..."<<endl;
	cout<<"-- ";
	Comp2.mostrar();
	cout<<" = ";
	r=Comp2--;
	r.mostrar();
	cout<<endl<<endl;
	
	if(Comp1>Comp2){
		cout<<"El Numero Complejo: ";
		Comp1.mostrar();
		cout<<"Es Mayor Que El Complejo: ";
		Comp2.mostrar();
		cout<<endl<<endl;		
	}
	else if(Comp1<Comp2){
		cout<<"El Numero Complejo: ";
		Comp2.mostrar();
		cout<<"Es Mayor Que El Complejo: ";
		Comp1.mostrar();
		cout<<endl<<endl;
	}
	else if(Comp1==Comp2){
		cout<<"Los Numeros Complejos Son Iguales"<<endl;
		Comp1.mostrar();
		cout<<" = ";
		Comp2.mostrar();
		cout<<endl<<endl;
	}
		

	cout<<"\n\n---Magnitud---"<<endl;
	
	cout<<"| ";	
	Comp1.mostrar();
	cout<<"| =";
	cout<<Comp1.Magnitud();
	cout<<endl<<endl;
	
	
	cout<<"| ";
	Comp2.mostrar();
	cout<<"| =";
	cout<<Comp2.Magnitud();
	cout<<endl<<endl;
	
	
	
	
	
	return 0;
}
*/
