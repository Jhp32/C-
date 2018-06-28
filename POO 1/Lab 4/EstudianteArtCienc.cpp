#include <iostream>
using namespace std;
class Estudiante{
protected:
	string nombre;
	int matricula;
	double marks[5];
	float porcentaje;
		
public:
	Estudiante(){}	
	
		Estudiante(string nombre, int matricula, double marks, float porcentaje){
			this->nombre=nombre;
			this->matricula=matricula;
			this->marks[5]=marks;
			this->porcentaje=porcentaje;			
		}
			
		void PedirValores(){
			cout<<"Nombre Del Estudiante: ";
			cin>>nombre;
			cout<<"\nMatricula Del Estudiante: ";
			cin>>matricula;
			cout<<"\n---Ingresa los valores de Marks---"<<endl;			
			for(int i=1; i<=5; i++){
				cout<<"Mark "<<i<<": ";
				cin>>marks[i];
				cout<<endl;
			}
			cout<<endl;
			for(int i=1; i<=5; i++){
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

class EstudianteScience:public Estudiante{
public:
	
	void PedirValores(){
		Estudiante::PedirValores();
	}
	
	double CalcularPorcentaje(){
		double s;
		for(int i=1; i<=5; i++){
			s=s+marks[i];
		}
		s=s+150;
		
		porcentaje=(s/650)*100;
		return porcentaje;
	}
	
	double grado(){
		return CalcularPorcentaje();
	}
	
	 void mostrar(){
		 Estudiante::mostrar();
	 }
	
};

class EstudianteArt:public Estudiante{
public:
	void PedirValores(){
		Estudiante::PedirValores();
	}
	double CalcularPorcentaje(){
		double s;
		for(int i=1; i<=5; i++){
			s=s+marks[i];
		}
		s=s+150;
		
		porcentaje=(s/600)*100;
		return porcentaje;
	}
	
	double grado(){
		return CalcularPorcentaje();
	}
	
	void mostrar(){
		Estudiante::mostrar();
	}
	
};


int main(int argc, char *argv[]) {
	
	Estudiante est1;
	//est1.mostrar();
	
	EstudianteScience est2;
	est2.mostrar();
	
	EstudianteArt est3;
	est3.mostrar();
	
	
	return 0;
}

