



#include<iostream>
using namespace std;

int meth1(int a, int b)
{
	return a+b;
}
void meth1(int a, int b, int c)
{
	cout<<a+b+c<<endl;
}
double meth1(double a, double b)
{
	return a+b;
}
int main()
{
	meth1(101,102,103);
	cout<<meth1(101, 102)<<endl;
	cout<<meth1(10.5, 20.7)<<endl;

	return 0;
}