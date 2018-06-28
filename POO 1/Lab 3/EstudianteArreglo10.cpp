#include <iostream>
using namespace std;
class Estudiante{
private:
	string nombre;
	int matricula;
	double *marks;
	int tamano;
	float porcentaje;
	
	Estudiante *arreEst;
	int tam;
	
public:
	Estudiante(){
		nombre="";
		matricula=0;
		tamano=5;
		marks=new double [tamano];
		porcentaje=0.0;
		tam=10;
		arreEst=new Estudiante [tam];
	}
	
	Estudiante(string nombre, int matricula, int tamano, float porcentaje, int tam){
		this->nombre=nombre;
		this->matricula=matricula;
		this->tamano=tamano;
		this->tam=tam;
	
		marks=new double[tamano];
		arreEst=new Estudiante[tam];
		this->porcentaje=porcentaje;			
	}
	
	
	int getMatricula(){
		return matricula;
	}
	
	
		void PedirValores(){
			cout<<"Nombre Del Estudiante: ";
			cin>>nombre;
			cout<<"\nMatricula Del Estudiante: ";
			cin>>matricula;
			
			cout<<"\n---Ingresa los valores de Marks---"<<endl;			
			for(int i=1; i<=tamano; i++){
				cout<<"Mark "<<i<<": ";
				cin>>marks[i];
				cout<<endl;
			}
			cout<<endl;
			
			for(int i=1; i<=tamano; i++){
				cout<<"Marks "<<i<<": "<<marks[i]<<endl;
			}
			cout<<endl<<endl<<endl;
		}
			
		
		double CalcularPorcentaje(){
			double s;
			for(int i=1; i<=tamano; i++){
				s=s+marks[i];
			}
			porcentaje=(s/500)*100;
			return porcentaje;
		}
		
		double grado(){
			return CalcularPorcentaje();
		}
		
		void mostrar(){
			PedirValores();
			
			cout<<"\n\n\n\n\n";			
			cout<<"Nombre: "<<nombre<<endl
				<<"Matricula: "<<matricula<<endl;			
			CalcularPorcentaje();
			cout<<"Porcentaje Cursado: "<<grado()<<"%"<<endl;
			
		}
		
		void ArregloEstudiantes(){
			
			for(int i=1; i<=tam; i++){
				cout<<"\nPidiendo valores del alumno: "<<i<<endl;
				arreEst[i].PedirValores();
			}
			
			for(int i=1; i<=tam; i++){
				cout<<"Mostrando los valores del alumno: "<<i<<endl;
				arreEst[i].mostrar();
			}
			
			
			
		}
		
		void buscar(){
			int valorBuscar;
			cout<<"Ingrese Matricula del alumno a Buscar: ";
			cin>>valorBuscar;
			cout<<endl;
			for(int i=1; i<=tam; i++){
				arreEst[i].getMatricula();
				if(valorBuscar == arreEst[i].getMatricula() ){
					arreEst[i].mostrar();
				}
			}
			
		}
		
		
};



int main(int argc, char *argv[]) {
	/*
	int tam;
	cout<<"Tamaño de Alumnos: ";
	cin>>tam;
	cout<<endl;
	Estudiante *arreEst;
	arreEst[tam];
	for(int i=0; i<tam; i++){
		arreEst[i].mostrar();
	}
	*/
	Estudiante est1;
	est1.ArregloEstudiantes();
	est1.buscar();
	
	

	
	
	return 0;
}

