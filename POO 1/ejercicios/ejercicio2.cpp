#include <iostream>
#include <windows.h>
using namespace std;
int main(){
	int num1, num2,x;
	cout<<"Ingresa el primer valor: ";
	cin>>num1;
	cout<<"Ingresa el segundo valor: ";
	cin>>num2;
	x=num2-1;
	for(int i=0; i<x; i++)
	{
		if(i!=num2){
			cout<<num1<<"+"<<num1;
		}
		else
		{
			cout<<num1;
		}
	}
	cout<<"="<<num1*num2;
	
	system ("pause");
	return 0;
}
