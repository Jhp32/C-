#include <iostream>
#include <math.h>

using namespace std;



class SobreCFraccion{
private:
	int numerador;
	int denominador;
	
public:
	SobreCFraccion(int numerador=0, int denominador=1){
		this->numerador=numerador;
		this->denominador=denominador;
	}
	
	void setNume(int n){n=numerador;}
	void setDenom(int d){d=denominador;}
	
	SobreCFraccion operator+(SobreCFraccion f){
		SobreCFraccion s;
		s.numerador=numerador*f.denominador+denominador*f.numerador;
		s.denominador=denominador*f.denominador;
		return s;
	}
	SobreCFraccion operator-(SobreCFraccion f){
		SobreCFraccion s;
		s.numerador=numerador*f.denominador-denominador*f.numerador;
		s.denominador=denominador*f.denominador;
		return s;
	}
	SobreCFraccion operator*(SobreCFraccion f){
		SobreCFraccion s;
		s.numerador=numerador*f.numerador;
		s.denominador=denominador*f.denominador;
		return s;
	}
	SobreCFraccion operator/(SobreCFraccion f){
		SobreCFraccion s;
		s.numerador=numerador*f.denominador;
		s.denominador=denominador*f.numerador;
		return s;
	}
		
	SobreCFraccion Potencia(int n){
		SobreCFraccion p;
		p.numerador=pow(numerador,n);
		p.denominador=pow(denominador,n);
		return p;
	}
	
	int Mcd(int a, int b){
		int resultado=1;	
		if(a<b){
			int intermedio;
			intermedio=a;
			a=b;
			b=intermedio;
		}
		for(int i=2; i<=b; i++){
			if( ( (a%i)==0 ) && (b%i==0) ){
				resultado=i;
			}
		}
		return resultado;
	}
	
	
	SobreCFraccion Simplificar(SobreCFraccion f){
		SobreCFraccion resultado;
		int MaxComDiv=Mcd(f.numerador, f.denominador);
		int num=f.numerador/MaxComDiv;
		int den=f.denominador/MaxComDiv;
		resultado.numerador=num;
		resultado.denominador=den;
		
		return resultado;
	}
	
	float Decimales(SobreCFraccion f){
		return( (float)f.numerador/(float)f.denominador );
	}
	
	
	friend ostream &operator<<(ostream &salida, SobreCFraccion &f){
		salida<<f.numerador<<"/"<<f.denominador<<endl;
		return salida;
	}
	
	friend istream &operator>>(istream &entrada, SobreCFraccion &f){
		entrada>>f.numerador>>f.denominador;
		return entrada;
	}
	
	
};


/*
int main() {
	SobreCFraccion X;
	
	cin>>X;
	cout<<endl<<X;

	
	return 0;
}
*/
