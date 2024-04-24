




#include<iostream>
#include<string>

using namespace std;


int main()
{
	
     string s="australia";
     	s.insert(3,"nzl");
     	cout<<s<<endl;

      s.erase(3,3);
      cout<<s<<endl;

      s.replace(3,2,"india");
      //  it will replace starting from index 3 ,
      // total 2 chars with 3rd arguement
      cout<<s<<endl;
      s.replace(4,4,"england");
      cout<<s<<endl;
      s.append("west indies");
      cout<<s<<endl;
       s.append("west indies",6,4);
      cout<<s<<endl;

      cout<<s.size()<<endl;
      cout<<s.length()<<endl;
       cout<<s.max_size()<<endl;
       string a="ausdialia";
       string b="india";
       int x= a.compare(b);
       cout<<x<<endl;
       int y= a.compare(3,2,b,2,2);// "tr" compared with "di"
       cout<<y<<endl;
       cout<<s<<endl;
       cout<<s.at(2)<<endl;
       string s7="welcome to programming";
       cout<<s7.at(5)<<endl; // 
       cout<<s7.substr(0,4)<<endl;
       cout<<s7.find("co")<<endl;
       cout<<s7.rfind('e')<<endl;
       cout<<s7.find_first_of("g")<<endl;
       cout<<s7.find_last_of("g")<<endl;



	return 0;
}
