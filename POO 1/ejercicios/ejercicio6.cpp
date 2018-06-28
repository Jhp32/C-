#include <iostream>
using namespace std; 
int main(){
	int a,cal,alt;
	cout<<"Numero de alumnos: " ;
	cin>>a;	
	alt=0;
	for(int i=0; i<a; i++)
	{
		cout<<"Dame la calificacion "<< i+1 << ": ";
		cin >> cal;
		if(cal>alt)
			alt=cal;
	}	
	cout << "La calificacion alta es: "<<alt;
}
