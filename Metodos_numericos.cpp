#include<iostream>
#include"matrix.hpp"

using std::cout;
using std::cin;
using std::endl;


int main(int argc, const char *argv[])
{
    int rows,columns;
    cout<<"introducir el grado del polinomio"<<endl;
	polinomio A(0),B(0);
	cin>>A;
	cout<<A;
	cout<<endl;
	B=derivada(A);
	cout<<B;
    system("pause");
	cout<<"evaluacion de los polinomios";
	cout<<A.evaluar(1)<<endl;
	cout<<B.evaluar(1);
	system("pause");
    return 0;
}
