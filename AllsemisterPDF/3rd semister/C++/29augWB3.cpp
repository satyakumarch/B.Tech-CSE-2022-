


#include<iostream>
using namespace std;
// friend function and class
class Test
{
	private:
	int x=10;
	public:
   friend void f1(Test t);
   friend class A;

};
      void f1(Test t)
      {
      	cout<<t.x<<endl;
      }
class A
{
public:
	void testFriend(Test t)
	{
		cout<<t.x<<endl;
	}
};
int main()
{
	Test t;
	f1(t);
	A a;
	a.testFriend(t);
	return 0;
}