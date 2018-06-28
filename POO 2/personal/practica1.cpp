#include <iostream>
using namespace std;

class Calcula{
private:
	int Mat[3];
	
public:

	Calcula(){
		
	}
	
	void recibir(){
		cout<<"Ingresa sus valores: "<<endl;
		
		for(int i=1; i<=3; i++){
			cout<<"Ingresa su valor "<<i<<" : ";
			
			cin>>Mat[i];
			cout<<endl;
		}
	}
	
	void mostrarV(){
		for(int i=1; i<=3; i++){
			cout<<"Valor "<<i<<": "<<Mat[i]<<endl;
		}
	}
	
	int suma(){
		int suma=0;
		for(int i=1; i<=3; i++){
			suma=suma+Mat[i];
		}
		return suma;
	}
	
	int producto(){
		int producto=1;
		for(int i=1; i<=3; i++){
			producto=producto*Mat[i];
		}
		return producto;
	}
	
	double promedio(){
		float promedio=suma();
		promedio=promedio/3;
		return promedio;
	}
	
	void menor(){		
		int menor, aux;
		for(int i=1; i<=3; i++){
			if(i>3){
				
			}
				
			Mat[i];
			
				if( aux <= Mat[j] ){
					menor=Mat[i];
				}
				else
				   menor=Mat[j];
			
		}
		cout<<"Menor: "<<menor;
	}
};


int main(int argc, char *argv[]) {
	Calcula obj;
	obj.recibir();
	obj.mostrarV();
	
	cout<<"Suma: "<<obj.suma()<<endl
		<<"Producto: "<<obj.producto()<<endl
		<<"Promedio: "<<obj.promedio()<<endl;
	
	obj.menor();
	return 0;
}
