#include <iostream>
using namespace std;
int main(){
	int cont;
	float ci, cf, interes;
	cont=0;
		cout<<"Ingresa capital inicial: ";
		cin>>ci;
		cout<<"Ingresa interes: ";
		cin>>interes;
			interes=interes/100;
		cf=ci*2;
		while(ci<=cf)
		{
			ci=ci+(ci*interes);
			cont++;
		}
		cout<<"Toltal de años: "<<cont<<endl;
}
