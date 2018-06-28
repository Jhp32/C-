#include <iostream>
using namespace std;

class TemplateFraccion{
	private:
		int numerador;
		int denominador;
		
	public:
	TemplateFraccion(int den=1, int num=0){
		this->denominador=den;
		this->numerador=num;
	}
	friend ostream &operator<<(ostream &salida, TemplateFraccion &f){
		cout<<f.numerador<<"/"<<f.denominador<<"::::";
		
		return salida;
	}
	
	bool operator>(TemplateFraccion f){
		return (numerador*f.denominador>denominador*f.numerador);
	}
	
	
};
template <class Type>
Type& max(Type &f1, Type &f2 ){
	return (f1>f2)?f1:f2;
}


int main(){
	TemplateFraccion f1(10,2), f2(7,1), s;
	
	cout<<f1<<f2<<endl;
	s=f1>f2;
	cout<<s.TemplateFraccion();
	
	
	return 0;
}
