#include<iostream>
using namespace std;

void swap(int *p,int *q)
{
	int temp;
	temp=*p;
	*p=*q;
	*q=temp;
}

int main()
{
	int a,b;
	cout<<"Enter any two Numbers: a:";
	cin>>a;
	cout<<"b:";
	cin>>b;
	cout<<"Before Swapping: \na: "<<a<<"\nb: "<<b<<"\n";
	swap(&a,&b);
	cout<<"After Swapping: \na: "<<a<<"\nb: "<<b<<"\n";
	
	return 0;
}
