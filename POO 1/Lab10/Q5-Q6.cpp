#include <iostream>
#include "NumComplexSobre.cpp"


using namespace std;

template <class T>
class Matrix{
		public:
	
		T mat[2][2];
		
		 
		Matrix(T a, T b, T c, T d){
			mat[0][0]=a;
			mat[0][1]=b;
			mat[1][0]=c;
			mat[1][1]=d;
		}
		
		Matrix(){
			mat[0][0]=0;
			mat[0][1]=0;
			mat[1][0]=0;
			mat[1][1]=0;
		}
		
		
		void Determinant(){
			T deter;
			deter=(mat[0][0]*mat[1][1])-(mat[0][1]*mat[1][0]);
			cout<<"Determinante: "<<deter<<endl;
		}
		
		void Print(){
			for(int i=0; i<2; i++){
				for(int j=0; j<2; j++){
					cout<<mat[i][j]<<"  ";
				}
				cout<<endl;
			}
			cout<<endl; 
		}
		
		Matrix<T> operator -(Matrix<T> N){
			
			return *(new Matrix<T>(mat[0][0]-N.mat[0][0], mat[0][1]-N.mat[0][1], mat[1][0]-N.mat[1][0],  mat[1][1]-N.mat[1][1]));
		}
		
		Matrix<T> operator +(Matrix<T> N){
			
			return *(new Matrix<T>(mat[0][0]+N.mat[0][0], mat[0][1]+N.mat[0][1], mat[1][0]+N.mat[1][0],  mat[1][1]+N.mat[1][1]));
		}
};
int main(int argc, char *argv[]) {
	
	Matrix<float> M(9.3, 1.5, 7.3, 3.0);
	Matrix<float> N(5.3, 9.1, 5.3, 2.0);
	
	Complex_No a(2,5);
	Complex_No b(3,1);
	Complex_No c(2,3);
	Complex_No d(7,2);
	
	Matrix<Complex_No> C(a, b, c, d);
	Matrix<Complex_No> D(d, a, b, c);
	C.Print();
	C.Determinant();
	
	D.Print();
	D.Determinant();
	
	Matrix<float> O;
	
	M.Print();
	N.Print();
	M.Determinant();
	N.Determinant();
	
	O=M+N;
	O.Print();
	O.Determinant();
	
	return 0;
}
