#include <iostream>
#include <cmath>
#include <windows.h>
#include <math.h>

using namespace std;

class Fraccion{
	private:
		int numerador, denominador;
	public:
		//constructor por default
		Fraccion(){
			numerador=1;
			denominador=1;
		}
		//constructor con parametros
		Fraccion(int num, int den){
			numerador=num;
			denominador=den;
		}
		//destructor
		~Fraccion(){
			//cout<<"se ejecuto el destructor"<<endl;
		}
		//getter
		int num(){return numerador;	}
		int den(){return denominador;}
        //setter
		void nume(int n){n=numerador;}
		void denom(int d){d=denominador;}
		//suma 2 fracciones
		Fraccion sumar(Fraccion f1, Fraccion f2){
			Fraccion s;
			s.numerador=f1.numerador*f2.denominador+f1.denominador*f2.numerador;
			s.denominador=f1.denominador*f2.denominador;
			return s;
		}
		Fraccion sumar(Fraccion f){
			Fraccion s;
			s.numerador=numerador*f.denominador+denominador*f.numerador;
			s.denominador=denominador*f.denominador;
			return s;
		}
		Fraccion restar(Fraccion f1, Fraccion f2){
			Fraccion s;
			s.numerador=f1.numerador*f2.denominador-f1.denominador*f2.numerador;
			s.denominador=f1.denominador*f2.denominador;
			return s;
		}
		
		Fraccion dividir(Fraccion f){
			Fraccion d;
			d.numerador=numerador*f.denominador;
			d.denominador=denominador*f.numerador;
			return d;
		}
		Fraccion multiplicar(Fraccion f1, Fraccion f2){
			Fraccion s;
			s.numerador=f1.numerador*f2.numerador;
			s.denominador=f1.denominador*f2.denominador;
			return s;
		}
		
		Fraccion Potencia(int n){
			Fraccion p;
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
		
		
		Fraccion Simplificar(Fraccion f){
			Fraccion resultado;
			 int MaxComDiv=Mcd(f.numerador, f.denominador);
			 int num=f.numerador/MaxComDiv;
			 int den=f.denominador/MaxComDiv;
			 resultado.numerador=num;
			 resultado.denominador=den;
			 
			 return resultado;
		}
		
		
		float Decimales(Fraccion f){
			return( (float)f.numerador/(float)f.denominador );
		}
		
		
		
		friend ostream &operator<<(ostream &salida, Fraccion &f){
			salida<<f.numerador<<"/"<<f.denominador<<endl;
		}
		
		
};


int main(){
	Fraccion s;
	int opcion;
	int x1,y1;
	int x2,y2;
	
	cout<<"Asigna Numerador y denominador de Fraccion 1: "<<endl
		<<"Numerador: ";
	cin>>x1;
	cout<<endl<<"Denominador: ";
	cin>>y1;
	cout<<endl;
	
	cout<<"Asigna Numerador y denominador de Fraccion 2: "<<endl
		<<"Numerador: ";
	cin>>x2;
	cout<<endl<<"Denominador: ";
	cin>>y2;
	cout<<endl;	
	
	Fraccion f1(x1,y1), f2(x2,y2);
	cout<<"Fraccion 1: ";
	f1.mostrar();
	cout<<endl<<"Fraccion 2: ";
	f2.mostrar();
	cout<<endl;
	do{
	cout<<"\n\n"
		<<"********************************"
		<<endl
		<<"1. Suma"<<endl
		<<"2. Resta"<<endl
		<<"3. Multiplicacion"<<endl
		<<"4. Division"<<endl
		<<"5. Elevar a una Potencia"<<endl
		<<"6. Reducir"<<endl
		<<"7. Convertir a Decimales"<<endl
		<<"8. Salir\n"
		<<"********************************"
		<<endl
		<<"		Opcion--> ";
	
	cin>>opcion;

	
		
		switch(opcion){
			case 1:
				cout<<"La suma es: "<<endl;
				f1.mostrar();
				cout<<" + ";
				f2.mostrar();
				cout<<" = ";
				s=f2.sumar(f1);
				s.mostrar();
		
				cout<<"\n\nLa reduccion de la suma seria: ";
				s.mostrar();
				cout<<" = ";
				s=s.Simplificar(s=s.sumar(f1,f2));
				s.mostrar();
				cout<<endl;
				break;
				
			case 2:
				cout<<"La resta es: "<<endl;
				f1.mostrar();
				cout<<" - ";
				f2.mostrar();
				cout<<" = ";
				s=s.restar(f1,f2);
				s.mostrar();
				
				cout<<"\n\nLa reduccion de la suma seria: ";
				s.mostrar();
				cout<<" = ";
				s=s.Simplificar(s=s.restar(f1,f2));
				s.mostrar();
				cout<<endl;							
				break;
				
			case 3:
				cout<<"La multiplcacion es: "<<endl;
				f1.mostrar();
				cout<<" x ";
				f2.mostrar();
				cout<<" = ";
				s=s.multiplicar(f1,f2);
				s.mostrar();
				
				cout<<"\n\nLa reduccion de la resta seria: ";
				s.mostrar();
				cout<<" = ";
				s=s.Simplificar(s=s.multiplicar(f1,f2));
				s.mostrar();
				cout<<endl;
				break;
			case 4:
				cout<<"La Division es: "<<endl;
				f1.mostrar();
				cout<<" / ";
				f2.mostrar();
				cout<<" = ";
				s=f1.dividir(f2);
				s.mostrar();
				
				cout<<"\n\nLa reduccion de la division seria: ";
				s.mostrar();
				cout<<" = ";
				s=s.Simplificar(s=f1.dividir(f2));
				s.mostrar();
				cout<<endl;
				break;
				
			case 5:
				cout<<"Elevar a una Potencia "<<endl;
				cout<<"A que potencia desea elevar: ";
				int potencia;
				cin>>potencia;
				cout<<endl;
				
				f1.mostrar();
				cout<<" ^"<<potencia<<" = ";
				s=f1.Potencia(potencia);
				s.mostrar();
				cout<<endl;
				
				f2.mostrar();
				cout<<" ^"<<potencia<<" = ";
				s=f2.Potencia(potencia);
				s.mostrar();
				cout<<endl;
				break;
				
			case 6:
				cout<<"La reduccion es:   \n\n";
				
			
				f1.mostrar();
				cout<<" = ";							
				s=s.Simplificar(f1);
				s.mostrar();
				cout<<endl;
				
				
				
				f2.mostrar();
				cout<<" = ";							
				s=s.Simplificar(f2);
				s.mostrar();
				cout<<endl;
				break;
				
			case 7:
				cout<<"Conversion a decimales: "<<endl;
				f1.mostrar();
				cout<<" = ";
				cout<<s.Decimales(f1)<<endl;
				
				f2.mostrar();
				cout<<" = ";
				cout<<s.Decimales(f2)<<endl;
				
				break;
			case 8:
				cout<<"Esta Saliendo...";
				break;
				
		}
		
	}while(opcion<8);
	
	s.~Fraccion();
	
	return 0;
}
