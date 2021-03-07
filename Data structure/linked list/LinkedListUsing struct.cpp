#include<iostream>
#include<stdlib.h>
using namespace std;
 class demo
 {
 	public:
	 int data;
 	 demo * next;
 };
 int main()
 {
 	class demo d,d1,d2;
 	d.data=10;
 	d.next=&d1;
 	
	cout<<"\nData of first is:"<<d.data;
 	cout<<"\nAddr for 1 is:"<<d.next;
 	
	d1.data=20;
 	d1.next=&d2;
 	
	cout<<"\nData of second is:"<<d1.data;
 	cout<<"\nAddr for 2 is:"<<d1.next;
 	 	
 	d2.data=30;
 	d2.next=NULL;
 	
	cout<<"\nData of third is:"<<d2.data;
 	cout<<"\nAddr for 3 is:"<<d2.next;
 }
