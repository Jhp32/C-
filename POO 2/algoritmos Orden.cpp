#include <iostream>
using namespace std;

class arreglo{
private:
	int tam;
	int *arre;
	
public:
	arreglo(){
		
	}
	arreglo(int tam){		
		this->tam=tam;
	}
	
	void recibir(){
		for(int i=1; i<=tam; i++){
			cout<<"Ingrese el valor "<<i<<" : ";
			cin>>arre[i];
			cout<<endl;
		}
	}
	void mostrar(){
		for(int i=1; i<=tam; i++){
			cout<<"Valor ["<<i<<"]: "<<arre[i]<<endl;
		}
	}
	
	void ordenarBurbuja(){
		cout<<endl<<"BURBUJA"<<endl;
		int temporal;
		for(int i=0; i<tam-1; i++){
			for(int j=1; j<tam; j++){
				if(arre[j]>arre[j+1]){
					temporal=arre[j];
					arre[j]=arre[j+1];
					arre[j+1]=temporal;
				}
			}
		}
		mostrar();
	}
	
	void ordenarSeleccion(){
		cout<<endl<<"SELECCION"<<endl;
		int temporal, menor;
		
		for(int i=1; i<tam; i++){
			menor=i;
			for(int j=menor+1; j<=tam; j++){
				if(arre[menor]>arre[j]){
					menor=j;
				}
			}
				temporal=arre[menor];
				arre[menor]=arre[i];
				arre[i]=temporal;	
		}
		mostrar();
	}
	

	void ordenarInsercion(){
		cout<<endl<<"INSERCION"<<endl;
		int temporal;
			int j;
		for(int i=1; i<tam; i++){
			temporal=arre[i];
			j=i-1;
			while( (arre[i]<arre[j]) &&  (j>=0) ){
				//temporal=arre[i];
				//arre[i]=arre[j-1];
				arre[j+1]=arre[j];
				j--;
			}
			arre[j+1]=temporal;
		}
		mostrar();
	}
};


int main(int argc, char *argv[]) {

	int x;
	cout<<"Ingrese el tamaño: ";
	cin>>x;
	arreglo ar1(x), ar2(x), ar3(x);
	ar3=ar2=ar1;
	
/*	
	ar1.recibir();
	ar1.mostrar();
	ar1.ordenarBurbuja();
	cout<<"****************"<<endl;
	
	ar2.recibir();
	ar2.mostrar();
	ar2.ordenarSeleccion();	
	cout<<"****************"<<endl;
*/
	ar3.recibir();
	ar3.mostrar();
	ar3.ordenarInsercion();
	
	
	return 0;
}

