
#include<iostream>

using namespace std;

class Student
{
   private:
   	int rollno;
   public:
   	double cgpa;
   	void getData()
   	{
   		cout<<"Enter rollno\n";
   		cin>>rollno;
   		cout<<"Enter Cgpa\n";
   		cin>>cgpa;
   	}
   	void print()
   	{
   		cout<<rollno<<cgpa;
   	}
   	double getCgpa();   
};

double Student :: getCgpa()
{
	return cgpa;
}

int main()
{
	Student s1;
	s1.getData();
	s1.print();
	cout<<s1.cgpa<<endl;
	cout<<s1.getCgpa()<<endl;
	//cout<<s1.rollno<<endl; // private member error
return 0;
}
