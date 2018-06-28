#include <iostream>
using namespace std;
int main(){
	float x,y;
	cout<<"Dame el valor a dividir: "<<endl;
	cin>>x;
	cout<<"Dame el valor por el que voy a dividir: "<<endl;
	cin>>y;
	if(y==0)
	 {
		cout<<"El valor no es divisible entre 0, es una inconsistencia";
	 }
	 else
	 {
		cout<<"Tu resultado es: "<<x/y;
	 }
}
