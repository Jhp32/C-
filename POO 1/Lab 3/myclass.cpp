#include <iostream>
using namespace std;

class myclass{
	int data[2];
	private:
	int* p;
	public:
		
	myclass(){
		p=data;
	}
	
};

int main(){ 
	myclass* cp;

	cp=new myclass[3];
	
	double valores;
	cout<<"Asignacion..."<<endl;
	for(int i=1; i<=3; i++){
		cout<<"Ingrese valor: ";
		cin>>valores;
		myclass[i]=valores;
	}
	
	
	cout<<"Mostrando..."<<endl;
	for(int i=1; i<=3; i++){
		cp=new myclass[i];
		cout<<"Mostrando valor "<<i<<": "<<myclass<<endl;
		
	}
	
return 0;
}


