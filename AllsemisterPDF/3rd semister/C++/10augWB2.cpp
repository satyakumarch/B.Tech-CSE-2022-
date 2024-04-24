





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
const int sz=5;
int main()
{
	Student s1[sz];
	for(int i=0; i<5;i++)
	s1[i].getData();

	for(int i=0; i<5;i++)
	s1[i].print();

	for(int i=0; i<5;i++)
	cout<<s1[i].getCgpa()<<endl;
	
return 0;
}