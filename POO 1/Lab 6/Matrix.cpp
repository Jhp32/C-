#include <iostream>
using namespace std;

class Matrix{
private:
	int Mat;
	int tamano;
	
public:

	Matrix(int tamano=2 /*, int Mat[tamano][tamano] */){
		//this->Mat=Mat;
		this->tamano=tamano;
		
	}
	/*
	Matrix friend operator+(Matrix f){
		Matrix s;
		for(int j=1; j<=2; j++){
			for(int i=1; i<=2; i++){
				s.Mat=Mat+f.Mat;
			}
		}
		return s;
	}
	
	Matrix friend operator-(Matrix f){
		Matrix s;
		for(int j=1; j<=2; j++){
			for(int i=1; i<=2; i++){
				s.Mat=Mat-f.Mat;
			}
		}
		return s;
	}
	*/
	
	friend ostream &operator<<(ostream &out, Matrix &f){
		for(int j=1; j<=2; j++){
			for(int i=1; i<=2; i++){
				out<<f.Mat[j][i] <<"  ";
			}
			cout<<endl;
		}
		return out;
	}
	
	friend istream &operator>>(istream &entrada, Matrix &f){
		for(int j=1; j<=tamano; j++){
			for(int i=1; i<=tamano; i++){
				entrada>>f.Mat[j][i];
			}
		}
		return entrada;
	}
	
	
};

int main(int argc, char *argv[]) {
	Matrix mat1;
	
	cin>>mat1;
	cout<<endl<<mat1;
	
	return 0;
}

