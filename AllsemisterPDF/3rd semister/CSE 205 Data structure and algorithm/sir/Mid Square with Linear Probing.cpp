// You are using GCC

#include<iostream>
using namespace std;

int main()
{
    int k, size = 10;
    cin>>k;
    int hashtable[size];
    for(int i=0; i<size; i++) hashtable[i] = -1;
    
    for(int i=0; i<k; i++)
       {
           //Hashing the keys using Mid-Square Method
           int key;
           cin>>key;
           
           int index = key*key;
           
           while(index >= size)
           {
               //Discard from RIGHT
              index = index/10;
               
               //Discard from Left
               if(index >= size)
               {
                   int n;
                   if(index > 1000) n = 1000;
                   else if(index > 100) n = 100;
                   else n = 10;
                   
                   index = index % n;
               }
           }
           
           
           //Linear Probing
           if(hashtable[index] == -1)   //No Collision
              hashtable[index] = key;
           else                         //Collision
           {
               while(hashtable[index] != -1)
               {
                   index++;
                   if(index == 10) index = 0;
               }
               hashtable[index] = key;
           }
           cout<<"\nAddress of "<<key <<" is: "<<index;
       }
       
       //Printing the keys index-wise
       
  /*     for(int i=0; i<10; i++)
       {
           if(hashtable[i] != -1) cout<<"\nIndex "<<i << " : Key = " << hashtable[i];
       }
*/
    return 0;
}
