#include <iostream>
using namespace std;
int main(){
	int  l, num;
	cout << "Numero de lineas: ";
	cin>>l;
	num=1;	
	for(int i=0; i<l; i++){		
		for(int x=0; x<i+1; x++){	
			cout<<num<<" ";
			num++;
		}		
		cout<<endl;
	}
}
