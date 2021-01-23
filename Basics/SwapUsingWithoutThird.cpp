

//8. WAP to Swap two numbers without using temporary


#include<iostream>  
 int main()    
{    
int a=10, b=20;      
cout<<"Before swap a & b"<<a<<b<<endl;       
a=a+b;
b=a-b;
a=a-b;
cout<<"After swap a & b"<<a<<b<<endl;    
return 0;  
}   

