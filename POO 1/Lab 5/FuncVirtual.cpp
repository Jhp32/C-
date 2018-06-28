#include <iostream>
using namespace std;

class abc{
	public: 
	void func(){
		//Es una Funcion abstracta y las funciones abstractas no se pueden instanciar
		//=0;
	}
};

class xyz:public abc{ 
	public:
	void func(){ 
	cout << "this is function of xyz";
	}
};


int main(){
	abc obj1;
	xyz obj2;
	obj1.func();
	obj2.func();
	return 0;
} 

