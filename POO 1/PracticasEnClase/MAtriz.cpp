#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

class Matriz{
private:
	int Nfilas, Ncolumnas;
	int Ma[100][100];

public:
	Matriz(int nc, int nf){
		nf=Nfilas;
		nc=Ncolumnas;
		srand(time(NULL));
		for (int i = 0; i < Nfilas; i++) {
			for (int j = 0; j < Ncolumnas; j++)
				Ma[i][j] = rand() % 30;
		}

	}




	Matriz(){
	    srand(time(NULL));
		for (int i = 0; i < Nfilas; i++) {
			for (int j = 0; j < Ncolumnas; j++) {
				Ma[i][j] = rand() % 30;
			}
		}
	}




	void setMatriz(int c, int f){
		Nfilas=f;
		Ncolumnas=c;
	}

	Matriz getMatriz(){
		return Matriz();
	}





	void LlenarTeclado(){
		int valor;
		for(int i=1; i<=Nfilas; i++){
			for(int j=1; j<=Ncolumnas; j++){
				cout<<"Ingrese los valores para: ["<<i<<"]["<<j<<"] ---->";
					cin>>valor;
				cout<<endl;

			}
		}


	}









	Matriz Suma(Matriz m){
		Matriz r;
		for(int j=1; j<=Nfilas; j++){
			for(int k=1; k<=Ncolumnas; k++){

				r.Ma[j][k]=Ma[j][k]+m.Ma[j][k];

			}
		}
		return r;
	}



	void mostrar(){
		for (int i = 0; i < Nfilas; i++) {
			for (int j = 0; j < Ncolumnas; j++) {
				cout <<Ma[i][j] << " ";
			}
			cout << endl << endl;
		}
		cout << endl << endl;
	}



};



int main(int argc, char *argv[]) {


	int ficu;

	cout<<"ATENCION!!!"<<endl
		<<"las matrices tienen que ser cuadradas y "<<endl
		<<"del mismo tamaño una que otra"<<endl<<endl
		<<"Ingresa tamaño de las matrices: ";
	cin>>ficu;
	cout<<endl;

	Matriz obj1(ficu, ficu), obj2(ficu, ficu);
	Matriz r(ficu,ficu);
	int opc1;
	//int valor;
	do{
		cout<<"\n\n"
			<<"********************************"<<endl
			<<"1.Ingresar desde el teclado"<<endl
			<<"2.Llenar aleatoriamente"<<endl
			<<"********************************"
			<<endl
			<<"		Opcion--> ";

		cin>>opc1;


		switch(opc1){

		case 1:

			obj1.LlenarTeclado();
			obj1.mostrar();





			break;

		case 2:

			//cout<<obj1;






			break;


		}

	} while(opc1<2);






	return 0;
}

