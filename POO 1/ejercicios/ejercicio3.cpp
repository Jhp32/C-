#include <iostream>
using namespace std;
int main() {
	int  num, ceros, dig;	
	cout << "Cuantos digitos tienes: ";
	cin >> dig;
	ceros = 0;
	for(int i=0; i<dig; i++)
	{
		cout << "Ingresa tu digito " << i+1 << ": ";		
		cin >> num;
		if(num==0)
			ceros++;
	}
	cout << "Se encuentran esta cantidad de ceros: " <<ceros<< endl;
	return 0;
}
