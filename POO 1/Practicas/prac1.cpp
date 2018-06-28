#include <iostream>
using namespace std;
class CalculadoraBin{
private:	
	int valorEnt;
	int boolVar;
	int ArreBi[8];
public:
	CalculadoraBin(){
		
	}
	CalculadoraBin(int valorEnt, int boolVar, int *ArreBi){
		this->valorEnt=valorEnt;
		this->boolVar=boolVar;
		this->ArreBi[8]=*ArreBi;
	}
	
	
	
	
	
};

int main(int argc, char *argv[]) {

	return 0;
}

