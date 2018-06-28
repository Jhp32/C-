#include <iostream>
using namespace std;

class ShopingMall{
protected:
	string nombre;
	string IDproduct;
	
public:
	ShopingMall(string nombre, string IDproduct){
		this->nombre=nombre;
		this->IDproduct=IDproduct;
	}
	
	void setNombre(string n){
		n=nombre;
	}
	void setIDproduct(string IDp){
		IDp=IDproduct;
	}
	string  getNombre(){
		 return nombre;
	}
	string getIDproduct(){
		return IDproduct;
	}
	void Asignar(){
		cout<<"Nombre del Producto: ";
		cin>>nombre;
		setNombre(nombre);
		cout<<"\nID del Producto: ";
		cin>>IDproduct;
		setIDproduct(IDproduct);
		cout<<endl;
	}
	
	
	void mostrar(){
		cout<<"Nombre: "<<this->nombre<<endl
			<<"ID del producto: "<<this->IDproduct<<endl;
	}
	 

	
};

class UtilityItems:public ShopingMall{
private:
	double descuento;
	
public:
	UtilityItems(string nombre, string IDproduct, double descuento):ShopingMall(nombre,IDproduct){
		this->descuento=descuento;
	}
	void setDescuento(double d){
		d=descuento;
	}
	double getDescuento(){
		return descuento;
	}
	
	void Asignar(){
		ShopingMall::Asignar();
		cout<<"Cual es el descuento del producto: ";
		cin>>descuento;
		setDescuento(descuento);
		cout<<endl;
	}
	void mostrar(){
		ShopingMall::mostrar();
		cout<<"Descuento: "<<this->descuento<<"%"<<endl;
	}
	
	
	
};

class FoodItems:public ShopingMall{
private:
	string FechaExpired;
	
public:
	FoodItems(string nombre, string IDproduct, string FechaExpired):ShopingMall(nombre, IDproduct){
		this->FechaExpired=FechaExpired;
	}
	void setFechaExpired(string fe){
		fe=FechaExpired;
	}
	string getFechaExpired(){
		return FechaExpired;
	}
	void Asignar(){
		ShopingMall::Asignar();
		cout<<"Ingresa Fecha de Expiracion "
			<<endl<<"Ejem. : (31/01/2016): ";
		cin>>FechaExpired;
		setFechaExpired(FechaExpired);
		cout<<endl;
	}
	
	void mostrar(){
		ShopingMall::mostrar();
		cout<<"Fecha de Expiracion: "<<this->FechaExpired<<endl;
	}
};


int main(int argc, char *argv[]) {
	cout<<"Supermercado..."<<endl;
	ShopingMall ven("xxx","0000");
	ven.Asignar();
	ven.mostrar();
	
	cout<<"\nUtility Items..."<<endl;
	UtilityItems ven1("xxx", "000", 0.0);
	ven1.Asignar();
	ven1.mostrar();
	
	cout<<"\nFood Items..."<<endl;
	FoodItems ven2("xxx","000", "00/00/0000");
	ven2.Asignar();
	ven2.mostrar();
		
	
	
	return 0;
}

