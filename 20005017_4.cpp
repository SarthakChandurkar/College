#include<iostream>
using namespace std;

void fibo(int n)
{
	int a=0,b=1;
	if(n==1)
	{
		cout<<0;
	}
	else if(n==2)
	{
		cout<<0<<" "<<1;
	}
	else
	{
		cout<<0<<" "<<1<<" ";
		for(int i=0;i<n-2;i++)
		{
			int c;
			c=a+b;
			cout<<c<<" ";
			a=b;
			b=c;
		}
	}
}

int main()
{
	int n;
	cout<<"Enter any Number: ";
	cin>>n;
	cout<<"Fibonacci series: ";
	fibo(n);
	
	return 0;
}
