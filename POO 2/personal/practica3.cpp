#include <iostream>
using namespace std;

class circulos{
private:
	int CirRad[5];
	
public:
	circulos(){
		
	}
	
	void ingresaCirRad(){
		cout<<"Ingresa Los Valores De Los Radios: "<<endl;
		for(int i=1; i<=5; i++){
			cout<<"Radio "<<i<<" : ";
			cin>>CirRad[i];
			cout<<endl;			
		}
	}
	
	double diametro(double r){
		double d=r*2;
		return d; 
	}
	
	double circunferencia(double r){
		double c=diametro(r) * 3.1416;
		return c;
	}
	
	void MostrarCirRad(){
		for(int i=1; i<=5; i++){
			cout<<"Circulo"<<i<<endl
				<<"******************"<<endl
				<<"Radio: "<<CirRad[i]<<endl
				<<"Diametro: "<<diametro(CirRad[i])<<endl
				<<"Circunferencia: "<<circunferencia(CirRad[i])<<endl<<endl;
		}
	}
};

int main(int argc, char *argv[]) {
	circulos obj;
	obj.ingresaCirRad();
	obj.MostrarCirRad();
	
	return 0;
}

