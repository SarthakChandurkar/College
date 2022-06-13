#include<iostream>
using namespace std;

class complex
{
	int a;
	int b;
	public:
	void add(complex t)
	{
		a=a+t.a;
		b=b+t.b;
	}
	void show_complex()
	{
		cout<<a<<"+"<<b<<"i"<<"\n";
	}
	void scan_complex()
	{
		cout<<"Enter a x-component- ";cin>>a;
		cout<<"Enter a y-component- ";cin>>b;
	}	
};

int main()
{
	complex a,b;
	cout<<"Enter first number: \n";
	a.scan_complex();
	cout<<"Enter second number: \n";
	b.scan_complex();
	cout<<"Showing complex numbers: \n";
	cout<<"First Number: ";
	a.show_complex();
	cout<<"Second Number: ";
	b.show_complex();
	cout<<"Addition of both: \n";
	a.add(b);
	a.show_complex();
	return 0;
}
