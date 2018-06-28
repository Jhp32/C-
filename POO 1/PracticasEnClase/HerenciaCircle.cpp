#include <iostream>
using namespace std;
const double pi=3.1416;

class Circulo{
protected:
	float radio;
public:
	Circulo(float r){
		this->radio=r;		
	}
	Circulo(){
		radio=0.0;
	}
	float Area(){
		return pi*(radio*radio);
	}
	float perimetro(){
		return 2*(pi+radio);
	}
	
};


class Cilindro:public Circulo{
private:
	float altura;
public:
	Cilindro(float h, float radio):Circulo(radio){
		altura=h;
	}
	float Area(){
		return 5.5;
	}
	float volumen(){
		return this->Area()*altura;
	}
	
};


class Cono:public Circulo{
private:
	float altura;
public:
	Cono(float h, float radio):Circulo(radio){
		altura=h;
	}
	float Area(){
		return pi*radio*radio;
	}
	float volumen(){
		return this->Area()*altura/2.0;
	}
	
};


int main(int argc, char *argv[]) {
	/*
	Ustedes Hacen el main y creen un arreglo de 6
	objetos y envien
	*/
	float k;
	cout<<"Asigna el valor del radio: ";
	cin>>k;
	cout<<endl;
	Circulo c1(k);
	
	c1.Area();
	
	
	return 0;
}

