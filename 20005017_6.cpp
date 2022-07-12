#include<iostream>
using namespace std;

class Employee
{
	static int count;
	int sallary;
		public:
			char name[30];
			int id;
		void getData()
		{
			cout<<"Enter the ID and Name: ";
			cin>>id>>name;
			cout<<"Enter the Sallary: ";
			cin>>sallary;
		}
		static incrementCount()
		{
			count+=1;
		}
		
};

int Employee::count=0;
class Company: public Employee
{
	
	public:
	Company()
	{
		getData();
	}
	void increment(int t)
	{
		sallary+=t;
	}
	void showData()
	{
		
	}
};

int main()
{
	Company C;
	C.increment(300);
	return 0;
}
