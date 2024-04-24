



#include<iostream>
using namespace std;

class Student
{
	
	
	public:
	int rollno;
	string name;
	static int cnt;
	Student()
	{
	   rollno=++cnt;
	}
	 void getData()
	 {
      cout<<"enter name"<<endl;
      cin>>name;
	 }

};

    int Student:: cnt=0;

    int main()
    {
    	Student s1;
    	Student s2;

    	cout<<s1.rollno<<endl;
    	cout<<s2.rollno<<endl;
    return 0;
    }


