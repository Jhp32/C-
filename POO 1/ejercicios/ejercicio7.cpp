#include <iostream>
using namespace std;
int main(){
	int dat,x,n, i;
	bool band;	
	cout<<"Datos a ingresar: ";
	cin>>dat;
	band=false;
	cout<<"Digito a buscar: ";
	cin>>x;
	i=0;
	cout<<"Ingresa Tus Valores"<<endl;
	while (i<dat)
	{
		cout<<"Ingresa un valor: ";
		cin>>n;
		if(n==x)
			band = true;
		i++;
	}
	if (band == true)
		cout<<"El valor " <<x<<" si se encunetra en la serie";
	else
		cout<<"El numero "<<x<<" no esta en la serie";
}
