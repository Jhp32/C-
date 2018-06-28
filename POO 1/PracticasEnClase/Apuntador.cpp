#include <iostream>
using namespace std;
//ANSI C---- C++Standar
/*
void cubo(int *c){
    *c=(*c)*(*c)*(*c);
}

int main(){
    int x=3;
    cubo(&x);

    cout<<"x^ 3= "<<x<<endl;

    return 0;
}
*/

//Referencias
void cubo(int&c){
c=c*c*c;
}
int main(){
int x=3;
cubo(x);
cout<<"x^3= "<<x<<endl;

return 0;
}
