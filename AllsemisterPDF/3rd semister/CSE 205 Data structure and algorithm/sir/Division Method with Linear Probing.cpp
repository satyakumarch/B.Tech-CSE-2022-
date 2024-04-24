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
           //Hashing the keys using Division Method
           int key;
           cin>>key;
           
           int index = key % size;
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
       }
       
       //Printing the keys index-wise
       
       for(int i=0; i<10; i++)
       {
           if(hashtable[i] != -1) cout<<"\nIndex "<<i << " : Key = " << hashtable[i];
       }
    return 0;
}
