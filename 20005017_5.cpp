//Experiment 1.
//Aim  - Write a program to perform addition of two complex numbers.


#include<iostream>
using namespace std;

class complex
{
		int real;
		int imag;
	public:
		void showComplex()
		{
			cout<<real<<"+"<<imag<<"i"<<endl;
		}
		void getComplex()
		{
			cout<<"Enter real and Imaginary parts of Complex No."<<endl;
			cout<<"real: ";cin>>real;
			cout<<"Imaginary: ";cin>>imag;
		}	
		complex addComplex(complex X);
		
};

complex complex::addComplex(complex X)
{
	complex T;
	T.real=real+X.real;
	T.imag=imag+X.imag;
	return T;
}

int main()
{
	complex A,B,C;
	A.getComplex();
	B.getComplex();
	C=A.addComplex(B);
	cout<<"A: ";A.showComplex();
	cout<<"B: ";B.showComplex();
	cout<<"C: ";C.showComplex();
	return 0;
}
