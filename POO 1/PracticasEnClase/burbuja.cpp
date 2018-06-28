#include <iostream>
#include "TemplateFracc.cpp"
using namespace std;

template <typename type1, typename type2>

void BubbleSort(type1 *V, type2 n){
	type1 temp;
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-1; j++){
			if( V[j]>V[j+1] ){
			temp=V[j];
			V[j]=V[j+1];
			V[j+1]=temp;
			}
			
		}
	}	
	
}

template <typename type1, typename type2>
void mostrar(type1 V[], type2 n){
		for(int i=0; i<n; i++){
			cout<<V[i]<<"   ";
		}
		cout<<endl;
	}
	

int main(){
	int n=5;
	//float vect[]={5.18,10.12,-4.02,3.0,-89.,0.61,0.81,-21};
	//string vect[]={"Joel", "Patricio", "Hilario", "Luis", "Irving"};
	TemplateFraccion vect[]={TemplateFraccion(-5,2), TemplateFraccion(4,8), TemplateFraccion(1,3), TemplateFraccion(7,7), TemplateFraccion(0,9)};
	
	mostrar(vect,n);
	BubbleSort(vect, n);
	mostrar(vect,n);
	
	
	return 0;
}
