#include <iostream>
#include <math.h>
using namespace std;

class Punto{
	private:
		int x, y;
	
	public:
		Punto(){
			x=y=0;
		}
		
		Punto(int x, int y){
			this->x=x;
			this->y=y;
		}
		
		void setPunto(int a, int b){
			x=a;
			y=b;
		}
		
		int getX(){
		return x;	
		}
		
		int getY(){
		return y;
		}
		
		Punto getPunto(){
		return Punto (x,y);
		}
		
		void mostrar(){
			cout<<"("<<x<<","<<y<<")";
		}
		
		float distancia(Punto p){
			return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));
		}
	

	
		
		
};



int main(int argc, char *argv[]) {

	
	
	int NumPtos;
	cout<<"Cuantos Puntos Desea En El Plano: ";
	cin>>NumPtos;
	Punto *coords;
	coords[NumPtos];
	
	Punto p1, p2;
	
	
	for(int i=1; i<=NumPtos; i++){		
		int x, y;
		cout<<"\n Dale La Coordenada Al Punto "<<i<<": ";
		cin>>x>>y;
		p1.setPunto(x,y);		
		cout<<"Punto"<<i<<"  Coordenada: ";
		p1.mostrar();
		cout<<endl<<endl<<endl;
	}
		
	
	for(int j=1; j<=NumPtos; j++){
		for(int i=1; i<=NumPtos; i++){
			Punto p1=coords[j];
			Punto p2=coords[i+1];					
			cout<<"La Distancia Entre Los Puntos: ";			
			p1.mostrar();
			p2.mostrar();
			cout<<":  "<<p1.distancia(p2) <<endl;	

			
			
			int PMenorX, PMenorY;
			int PMayorX, PMayorY;
			
			float menor=p1.distancia(p2), 
				mayor=p1.distancia(p2);
			
			
			
			if (p1.distancia(p2) < menor){
				menor=p1.distancia(p2);
				
				PMenorX=p2.getX();
				PMenorY=p2.getY();			
			}
			
			
			else if(p1.distancia(p2) > mayor){
				mayor=p1.distancia(p2);
				
				PMayorX=p2.getX();		
				PMayorY=p2.getY();
			}
			
			cout<<endl;
			
			cout<<"El Punto Mas Cerca Es: ("<<PMenorX<<","<<PMenorY<<")"<<endl;
			cout<<"Con La Distacia De: "<<menor<<endl;
			
			cout<<"\n";
			
			
			cout<<"El Punto Mas Lejos Es: ("<<PMayorX<<","<<PMayorY<<")"<<endl;
			cout<<"La Distancia Mas Larga Es: "<<mayor<<endl;
			
			cout<<"\n\n\n\n";
			
			
			
			
			
			
		}
		cout<<"\n\n\n";				
	}


	
	/*	
		
	Punto p1(3,5), p2(7,3), p3(2,-2), p4(5,7), p5(8,-1), p6(3,0), p7(10,-1);
	
	
	Punto coords[7]={p1, p2, p3, p4, p5, p6, p7};
	
	
	float menor=p1.distancia(p2), mayor=p1.distancia(p2);
	
	int PMenorX, PMenorY;
	int PMayorX, PMayorY;
	
	for(int i=1; i<7; i++){		
	
		cout<<"Distancia Entre Los Puntos: ";
		p1.mostrar();
		coords[i].mostrar();
		cout<<":  "<<p1.distancia( coords[i] ) <<endl;	
		
		
	if (p1.distancia( coords[i] ) < menor){		
		menor=p1.distancia( coords[i] );
				
		PMenorX=coords[i].getX();
		PMenorY=coords[i].getY();			
	}
	
	
	else if(p1.distancia( coords[i] ) > mayor){
		mayor=p1.distancia( coords[i] );
		
		PMayorX=coords[i].getX();		
		PMayorY=coords[i].getY();
	}
	
	
	}
	
	cout<<endl;
	
	cout<<"El Punto Mas Cerca Es: ("<<PMenorX<<","<<PMenorY<<")"<<endl;
	cout<<"Con La Distacia De: "<<menor<<endl;
	
	cout<<"\n";
	
	
	cout<<"El Punto Mas Lejos Es: ("<<PMayorX<<","<<PMayorY<<")"<<endl;
	cout<<"La Distancia Mas Larga Es: "<<mayor<<endl;
	
	*/
	
	
	
	return 0;
}

