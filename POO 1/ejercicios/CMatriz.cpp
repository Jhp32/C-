#include<iostream>
#include<windows.h>
using namespace std;


class CMatriz{
    private:
        int f,c;
        int M[30][30];
    public:
        CMatriz(){
            f=c=2;
        }
		
    CMatriz(int n, int m){
        f=n;
        c=m;
        }


void leerMatriz(){
    cout<<"Ingresa los valores de la matriz: "<<endl;
for(int i=0; i<f; i++){
    for(int j=0; j<c; j++){
        cin>>M[i][j];
            }

        }

    }


void mostrarMatriz(){
cout<<"Los valores de la matriz son: "<<endl;
for(int k=0; k<f; k++){
    for(int p=0; p<c; p++){
        cout<<M[k][p]<<" ";
    }
    cout<<endl;
}
}


int sumarValores(){
int suma=0;
for(int i=0; i<f; i++){
    for(int j=0; j<c; j++){
        suma+=M[i][j];
    }
}
return suma;
}

void mayor(){
	int aux1, mayor;
	for(int i=0; i<f; i++){
		for(int j=0; j<c; j++){
			aux1=M[i][j];
			mayor=M[i][j++];
			if(aux1>mayor){
				mayor=aux1;
			}
			else{
				mayor=mayor;
			}
			
		}
	}	
	cout<<"El Mayor es: "<<mayor<<endl;
}


};



int main(){

    int n, m,sum;
    cout<<"Numero de renglones? ";
    cin>>n;
    cout<<"Numero de columnas? ";
    cin>>m;
    
	CMatriz m1(n,m);
	m1.mostrarMatriz();
    m1.leerMatriz();
    m1.mostrarMatriz();
    m1.sumarValores();
    sum=m1.sumarValores();
    cout<<"La suma de la matriz: "<<sum<<endl;
	m1.mayor();
	
	return 0;
}
