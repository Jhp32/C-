#include <iostream>
#include <math.h>

using namespace std;

template <typename T>

void Power(T x, T y){
	
	cout << pow(x, y) << endl;
}

int main(int argc, char *argv[]) {
	int a=3;
	int b=2;
	float c=3.2;
	float d=5.6;
	
	Power(a, b);
	Power(c, d);
}