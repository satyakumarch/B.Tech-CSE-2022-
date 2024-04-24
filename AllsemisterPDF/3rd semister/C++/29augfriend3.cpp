// C++ program to create a member function of another class
// as a friend function
#include <iostream>
using namespace std;

class A; // forward definition needed
// another class in which function is declared
class B {
public:
	void memberFunction(A obj);
};
// A class for which friend is declared
class A {
private:
	int private_variable=20;

public:
	// friend function declaration
	friend void B::memberFunction(A);
};

// friend function definition
void B::memberFunction(A obj)
{
	cout << "Private Variable: " << obj.private_variable
		<< endl;
	
}

// driver code
int main()
{
	A object1;
	B object2;
	object2.memberFunction(object1);

	return 0;
}
