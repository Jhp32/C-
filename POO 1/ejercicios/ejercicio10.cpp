#include <iostream>
using namespace std;
int main(){
	int x, y, suma;
	cout<<"Digito inicial de X: ";
	cin>>x;
	cout<<"Digito final de Y: ";
	cin>>y;
	if(x<=y)
	{
		suma=0;
		if(x%2!=0)
			x++;		
		for(int i=x; i<=y; i+=2)
		{
			suma=suma+i;
		}
		cout<<"Tu suma de pares es: "<<suma<<endl;
	}
	else
		cout<<"X debe ser menor o igual que Y";
}
