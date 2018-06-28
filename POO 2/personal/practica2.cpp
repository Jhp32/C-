#include <iostream>
using namespace std;

class Transaccion{
private:
	float saldo=0;
	
public:
	Transaccion(float saldo){
		this->saldo=saldo;
	}
	Transaccion(){
		
	}
	
	void mostrarSaldo(){
		cout<<"Saldo: "<<saldo<<endl;
	}
	
	float retiro(){
		float r;
		cout<<"Ingrese Cuanto Desea Retirar: ";
		cin>>r;
		cout<<endl;
		if(r>saldo){
			cout<<"No es posible hacer Accion"<<endl
				<<"Saldo Disponible: "<<saldo<<endl;
			return false;
		}
		else
		   saldo=saldo-r;
		   return saldo;
	}
	
	float deposito(){
		float d;
		cout<<"Ingrese Cuanto Desea Depositar: ";
		cin>>d;
		saldo=saldo+d;
		return saldo;
	}
	
};

int main(int argc, char *argv[]) {
	
	Transaccion obj;
	int op;
	cout<<"\n\n * Bienvenido * ";
	do {
		cout<<"\n==========================\n";
		cout<<"Seleccione Opción\n";
		cout<<"\n==========================\n";
		cout<<"1.Mostrar Saldo\n";
		cout<<"2.Retirar\n";
		cout<<"3.Depositar\n";
		cout<<"4.Salir\n=>";
		cin>>op;
		switch(op){
		case 1: 
			obj.mostrarSaldo();					
			break;									
		case 2: 			
			obj.retiro();
		break;
		case 3: 			
			obj.deposito();
		break;
		case 4:
			cout<<"\nGracias Por Su Preferencia\n\n"	;
			break;
		}
	}while (op!=4);
	
	return 0;
}

