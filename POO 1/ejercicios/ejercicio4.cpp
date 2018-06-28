#include <iostream>
using namespace std;
int main (){
	int a,b,factorial;
	cout << "Factorial \nPor favor ingrese su valor: " <<endl;
	cin >> a;
	factorial=1;
	for (b=1 ; b<=a ; b++)
	{
		factorial=b*factorial;
	}	
	cout<<"El factorial de "<<a<<" es: "<<endl;
	cout<<factorial;
	return 0;
}
