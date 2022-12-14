#include<iostream>

using namespace std;

int converter(int n)
{
   if(n==0)
   {
    return 0;
   }
   if(n==1)
   {
    return 1;
   }
   if(n==2)
   {
    return 10;
   }
   if(n==3)
   {
    return 11;
   }
   if(n==4)
   {
    return 100;
   }
   if(n==5)
   {
    return 101;
   }
   if(n==6)
   {
    return 110;
   }
   if(n==7)
   {
    return 111;
   }
    return -1;
}


int main()
{   
    int n;
    int bin_int;
    int b1,b2,b3;
    cin>>n;

    bin_int=converter(n);
    cout<<bin_int<<endl;

    b3=bin_int%10;
    b2=(bin_int%100-b3)/10;
    b1=(bin_int%1000)/100;

    cout<<b1<<"  "<<b2<<"  "<<b3;

    return 0;
}