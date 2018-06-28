#include <iostream>
using namespace std;

class Employee{
protected:
	int NumberEmployee;
	string NameEmployee;
	
	float pagaTotal;
	float deducciones;
	float pagoBancario;
	float salario;
	
	int dia;
	int mes;
	int anio;
	
public:
	Employee(){
	NumberEmployee=0;
	NameEmployee=" ";
	
	pagaTotal=0.0;
	deducciones=0.0;
	pagoBancario=0.0;
	salario=0.0;
	
	dia=0;
	mes=0;
	anio=0;
		
	}
	
	Employee(int NumberEmployee, string NameEmployee, float pagaTotal, float deducciones, float pagoBancario, float salario, int dia, int mes, int anio){
		this->NumberEmployee=NumberEmployee;
		this->NameEmployee=NameEmployee;
		this->pagaTotal=pagaTotal;
		this->deducciones=deducciones;
		this->pagoBancario=pagoBancario;
		this->salario=salario;
		this->dia=dia;
		this->mes=mes;
		this->anio=anio;
	}
	float salarioTFinal(){
		pagaTotal=pagoBancario-deducciones;
		salario=pagaTotal;
		return salario;
	}
	void pedir(){
		cout<<"Datos Del Empleado: "<<endl
			<<"Numero ID: ";
		cin>>NumberEmployee;
		cout<<endl<<"Nombre: ";
		cin>>NameEmployee;
		cout<<endl;
		//pedirFecha();
		//pedirSalario();
		
		
	}
	void mostrar(){
		cout<<"Nombre: "<<NameEmployee<<endl
			<<"Numero ID: "<<NumberEmployee<<endl;
		//mostrarFecha();
		//mostrarSalario();
	}
};

class Fecha:public Employee{

public:
	Fecha(int dia, int mes, int anio):Employee(dia, mes, anio){
		
	}
	
	void pedirFecha(){
		cout<<"Ingrese Fecha: "<<endl
			<<"Dia: ";
		cin>>dia;
		cout<<endl<<"Mes: ";
		cin>>mes;
		cout<<endl<<"Anio: ";
		cin>>anio;
		cout<<endl;
	}
	void mostrarFecha(){
		cout<<"		Mostrando Fecha"<<endl
			<<"(Dia, Mes, Anio)-> "
			<<dia<<" / "<<mes<<" / "<<anio<<endl;
	}
};

class PagoFinal:public Employee{
	
public:
	PagoFinal(float pagaTotal, float deducciones, float pagoBancario, float salario):Employee(pagaTotal, deducciones, pagoBancario, salario){
		
	}
	
	void pedirSalario(){
		cout<<"Ingrese Detalles De Salario: "<<endl
			<<"Salario Bruto: ";
		cin>>pagaTotal;
		cout<<endl<<"Deducciones: ";
		cin>>deducciones;
		cout<<endl<<"Pago En Coins: ";
		cin>>pagoBancario;
		cout<<endl<<"Calculando..."<<endl
			<<"Salario Total: "<<salarioTFinal()<<endl;
	}
	
	void mostrarSalario(){
		cout<<"Salario: "<<salarioTFinal()<<endl;
	}
};

int main(int argc, char *argv[]) {
	
	return 0;
}

