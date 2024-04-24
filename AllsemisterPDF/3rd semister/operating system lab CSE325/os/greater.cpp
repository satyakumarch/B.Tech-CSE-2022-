#include<iostream>
using namespace std;
template<class t>
t square(t num)
{
	return (num*num);
}
int main()

{
	int num1=13;
	cout<<"square of:"<<num1<<"="<<square<int>(num1)<<endl;
	float num2=5.6;
	cout<<"square of"<<num2<<"="<<square<float>(num2)<<endl;
	double num3=123.456;
	cout<<"square of"<<num3<<"="<<square<double>(num3)<<endl;
	return 0;
}

#include<io>
