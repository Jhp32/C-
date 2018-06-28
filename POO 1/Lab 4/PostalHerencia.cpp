#include <iostream>
using namespace std;
 
 class Post{
        protected:
        string name;
		string to;
        float stampcost;
                 
        public:
        	Post(string name, string to, float stampcost){
        		this->name=name;
        		this->to=to;
        		this->stampcost=stampcost;
			}	
            Post(){
                stampcost =1.0;
                to = "";                
            }            
       virtual void Read(){
            cout<<"Ingresa Nombre: ";
            cin>>name;
            cout<<"\nIngresa La Direccion: ";
            cin>>to;
            cout<<"\nIngrese El Costo De La Stampilla: ";
            cin>>stampcost;
            cout<<endl;
        } 
       	
       virtual float Totalcost (){
            return stampcost;
        }     

       virtual void Print(){
            
            //Read();
            
            cout<<endl
            <<"Nombre: "<<name<< endl
            <<"Direccion: "<<to<< endl
            <<"Costo Total: "<<Totalcost()<<"$"<< endl;
            
            }
			
			
        };
        
        
        class registeredPost: public Post{
            protected:
                float weight;
                float costReistration;
                
                public:
                	
                	registeredPost(string name, string to, float stampcost, float weight, float costReistration):Post(name, to, stampcost){
                		weight=weight;
                		costReistration=costReistration;
					}
                	
                    registeredPost(){
                    weight=20;
                    costReistration=10;
					}
                
                virtual void Read(){
                	Post::Read();
                	cout<<"\nPeso En Gramos: ";
                	cin>>weight;
                	cout<<"\nGastos De Registro: ";
                	cin>>costReistration;
                	cout<<endl;
				}
                                
            virtual float Totalcost(){
                return Post::Totalcost()+costReistration;
            }
            
            virtual void print(){
            	Post::Print();
            	cout<<endl
            		<<"Peso En Gramos: "<<weight<<"gr"
            		<<endl
            		<<"Gastos De Registros: "<<costReistration<<endl;            		
			}

        };
        
         class insuredRgisteredPost: public registeredPost{
         	private:
         		double AmtInsured;
         		
            public:
            	insuredRgisteredPost(){                    
                       AmtInsured =20;
                    }

                    insuredRgisteredPost(string name, string to, float stampcost, float weight, float costReistration, double AmtInsured){
                       AmtInsured=AmtInsured;
                    }
                    
                void Read(){
                    registeredPost::Read();
                	cout<<"\nValor asegurado del correo: ";
                	cin>>AmtInsured;
                	cout<<endl;
				}
				
                float Totalcost(){
                	return registeredPost::Totalcost()+AmtInsured;
                }
                
				void print(){
            	registeredPost::Print();
            	cout<<endl
            		<<"Valor asegurado: "<<AmtInsured
            		<<endl;
			}
                    
                };
            
            int main (){
            	
                insuredRgisteredPost envelope;
                envelope.Read();
                cout<<"Pos Datails.."<<endl;
                envelope.Print();
                
                return 0;
            }