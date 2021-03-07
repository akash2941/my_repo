#include<iostream>
#include<stdlib.h>
using namespace std;
 struct demo
 {
 	int data;
 	struct demo * next;
 };
 int main()
 {
 	struct demo *d = (struct demo *)malloc (sizeof(struct demo));
 	d->data=10;
 	d->next=NULL;

 	struct demo *d1 = (struct demo *)malloc (sizeof(struct demo));
 	d->next=d1;
	d->next->data=20;
 	d->next->next=NULL;
 	
 	struct demo *d2 = (struct demo *)malloc (sizeof(struct demo));
 	d->next->next=d2;
 	d->next->next->data=30;
 	d->next->next->next=NULL;
 	
 	while(d != NULL)
 		{
 			cout<<"\n\n1.Data:"<<d->data;
 			cout<<"\n2.Addr:"<<d->next;
 			d=d->next;
		}

 }
