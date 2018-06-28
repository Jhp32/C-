#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Correo{
private:
	string nombre;
	string dominio;
	string pass;
public:
	Correo(string nombre, string dominio, string pass){
		this->nombre=nombre;
		this->dominio=dominio;
		this->pass=pass;
	}
	Correo(){
		
	}
	
	setNombre(string n){
		n=nombre;		
	}
	setDominio(string d){
		d=dominio;		
	}
	setPass(string p){
		p=pass;		
	}
	getNombre(){
		return nombre;
	}
	
	void IngresC(){
		int n;		
		string auxPass, *arr;
		cout<<"Cuantos correos desea ingresar: ";
		cin>>n;
		arr[n];
		for(int i=1; i<=n; i++){
			cout<<"USUARIO "<<i<<endl
				<<"************"<<endl
				<<"Ingrese Su Nombre De Usuario: ";
			cin>>nombre;
			getNombre( nombre);
			cout<<endl<<"Ingrese El Dominio: ";
			cin>>dominio;
			getDominio(dominio);
			cout<<endl<<"Ingrese La Contraseña: ";
			cin>>pass;
			do{			
				cout<<endl<<"Repita La COntraseña: ";
				cin>>auxPass;
				if( pass!=auxPass ){
					cout<<"Contraseña ERRONEA!!"<<endl;
				}				
			} while(pass!=auxPass);
			getPass(pass);
		arr[i]=(setNombre() );
		}
		for(int i=1; i<=n; i++){
			arr[i];
			cout<<"USUARIO "<<i<<endl
				<<nombre<<setw(5)<<dominio<<setw(5)<<endl
				<<"PASSWORD: "<<pass<<endl<<endl;
				
		}
		
	}

};

int main(int argc, char *argv[]) {
	Correo obj;
	obj.IngresC();
	
	return 0;
}

