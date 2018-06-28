#include <iostream>
using namespace std;
class Estudiante{
private:
	string nombre;
	int matricula;
	double *marks;
	int tamano;
	float porcentaje;
		
public:
	Estudiante(){
		nombre="";
		matricula=0;
		tamano=5;
		marks=new double [tamano];
		porcentaje=0.0;
	}
	
		Estudiante(string nombre, int matricula, int tamano, float porcentaje){
			this->nombre=nombre;
			this->matricula=matricula;
			this->tamano=tamano=5;
			
			marks=new double[tamano];
			this->porcentaje=porcentaje;			
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
		}
				
		double CalcularPorcentaje(){
			double s;
			for(int i=1; i<=5; i++){
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
};



int main(int argc, char *argv[]) {
	
	Estudiante est1;
	est1.mostrar();
	
	
	return 0;
}

