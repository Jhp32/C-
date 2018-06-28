#include <iostream>
#include <windows.h>
//#include <conio2.h>
using namespace std;

class DateTime{
private:
	int anio;
	int mes;
	int dia;
	int hora;
	int minuto;
	int segundo;
	
public:
	DateTime(){
		anio=0;
		mes=0;
		dia=0;
		hora=0;
		minuto=0;
		segundo=0;
	}
	
	DateTime(int anio, int mes, int dia, int hora, int minuto, int segundo){
		this->anio=anio;
		this->mes=mes;
		this->dia=dia;
		this->hora=hora;
		this->minuto=minuto;
		this->segundo=segundo;
	}
	
	void SetValue(int dia, int mes, int anio){
		for( anio=anio; anio<=3000; anio++){
			for(mes=mes; mes<=12; mes++){
				for(dia=dia; dia<=30; dia++){


					for(int ms=0; ms<100; ms++){


					cout<<"Dia: "<<dia<<"  /Mes: "<<mes<<"  /Anio: "<<anio<<endl;

					}


				}
			}
		}
		
	}
	
	void SetValue(int dia, int mes, int anio, int hora){
		for( anio=anio; anio<=3000; anio++){
			for(mes=mes; mes<=12; mes++){
				for(dia=dia; dia<=30; dia++){
					for(hora=hora; hora<=24; hora++){


					for(int ms=0; ms<100; ms++){


					cout<<"Dia: "<<dia<<"  /Mes: "<<mes<<"  /Anio: "<<anio<<endl
						<<"Hora: "<<hora<<endl;

						}


					}
				}
			}
		}
		
	}
	
	void SetValue(int dia, int mes, int anio, int hora, int minuto){
		for( anio=anio; anio<=3000; anio++){
			for(mes=mes; mes<=12; mes++){
				for(dia=dia; dia<=30; dia++){
					for(hora=hora; hora<=24; hora++){
						for(minuto=minuto; minuto<=59; minuto++){


							for(int ms=0; ms<100; ms++){


						cout<<"Dia: "<<dia<<"  /Mes: "<<mes<<"  /Anio: "<<anio<<endl
							<<"Hora: "<<hora<<"   /Minutos: "<<minuto<<endl;

							}

						}
					}
				}
			}
		}
		
	}
	
	void SetValue(int dia, int mes, int anio, int hora, int minuto, int segundo){
		for( anio=anio; anio<=3000; anio++){
			for(mes=mes; mes<=12; mes++){
				for(dia=dia; dia<=30; dia++){
					for(hora=hora; hora<=24; hora++){
						for(minuto=minuto; minuto<=59; minuto++){
							for(segundo=segundo; segundo<=59; segundo++){


								for(int ms=0; ms<100; ms++){


							cout<<"Dia: "<<dia<<"  /Mes: "<<mes<<"  /Anio: "<<anio<<endl
								<<"Hora: "<<hora<<"   /Minutos: "<<minuto<<"   /Segundos: "<<segundo<<endl;

								}


							}
						}
					}
				}
			}
		}
		
	}
	
	
};

int main(int argc, char *argv[]) {
	DateTime tiempo;
	//tiempo.SetValue(5,4,2001);

	int opcion;

	int Dia, Mes, Anio, Hora, Minutos, Segundos;

	do{
		cout<<"\n\n"
		<<"*-*-*-*-*-*-*-*-*-*-*TIEMPO*-*-*-*-*-*-*-*-*-*-*"
		<<endl
		<<endl
		<<"********************************"
		<<endl
		<<"1. ASIGNAR(Dia/Mes/Anio)"<<endl
		<<"2. ASIGNAR(Dia/Mes/Anio/Hora)"<<endl
		<<"3. ASIGNAR(Dia/Mes/Anio/Hora/Minutos)"<<endl
		<<"4. ASIGNAR(Dia/Mes/Anio/Hora/Minutos/Segundos)"<<endl
		<<"5. Salir\n==>"
		<<"********************************"
		<<endl
		<<"		Opcion--> ";
	cin>>opcion;
	cout<<endl;
	switch(opcion){
		case 1:
		cout<<"ASIGNAR(Dia/Mes/Anio)"
			<<endl<<"Dia: ";
			cin>>Dia;
			cout<<endl<<"Mes: ";
			cin>>Mes;
			cout<<endl<<"Anio: ";
			cin>>Anio;
			cout<<endl;
			tiempo.SetValue(Dia, Mes, Anio);
		break;
		case 2:
		cout<<"ASIGNAR(Dia/Mes/Anio/Hora)"
			<<endl<<"Dia: ";
			cin>>Dia;
			cout<<endl<<"Mes: ";
			cin>>Mes;
			cout<<endl<<"Anio: ";
			cin>>Anio;
			cout<<endl<<"Hora: ";
			cin>>Hora;
			cout<<endl;
			tiempo.SetValue(Dia, Mes, Anio, Hora);
		break;
		case 3:
		cout<<"ASIGNAR(Dia/Mes/Anio/Hora/Minutos)"
			<<endl<<"Dia: ";
			cin>>Dia;
			cout<<endl<<"Mes: ";
			cin>>Mes;
			cout<<endl<<"Anio: ";
			cin>>Anio;
			cout<<endl<<"Hora: ";
			cin>>Hora;
			cout<<endl<<"Minutos: ";
			cin>>Minutos;
			cout<<endl;
			tiempo.SetValue(Dia, Mes, Anio, Hora, Minutos);
		break;
		case 4:
		cout<<"ASIGNAR(Dia/Mes/Anio/Hora/Minutos/Segundos)"
			<<endl<<"Dia: ";
			cin>>Dia;
			cout<<endl<<"Mes: ";
			cin>>Mes;
			cout<<endl<<"Anio: ";
			cin>>Anio;
			cout<<endl<<"Hora: ";
			cin>>Hora;
			cout<<endl<<"Minutos: ";
			cin>>Minutos;
			cout<<endl<<"Segundos: ";
			cin>>Segundos;
			cout<<endl;
			tiempo.SetValue(Dia, Mes, Anio, Hora, Minutos, Segundos);
		break;
		case 5:
		cout<<"ELIMINADO TU LINEA DE TIEMPO...";
		break;

	}

	}while(opcion!=5);
	

	
	return 0;
}

