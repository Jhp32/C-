#include <iostream>
using namespace std;
int main(){
	int i, x;	
	cout<<"Mostrar los primeros 20 terminos de la" << endl;
	cout<<"serie:  2, 5, 7, 10, 12, 15, 17, ..." << endl << endl;
	i=1;
	x=2;
	while (i<20)
	{		
		cout<<x<<" ";
		if(i%2!=0)
			x=x+3;
		else
			x=x+2;
		i++;
	}
	cout<<endl;
}
