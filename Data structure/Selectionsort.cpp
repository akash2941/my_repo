#include<iostream>
using namespace std;

int main()
{
	int j;
	int pos;
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
 	}
	cout<<"Before sort"<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
 	}
	for(int i=0;i<n;i++){
		int MIN=arr[i];
		for(j=i;j<n;j++){
			if(MIN<arr[j]) continue;
			else{
				MIN=arr[j];
				pos=j;
			}
		}
		int temp;
		temp=arr[i];
		arr[i]=arr[pos];
		arr[pos]=temp;
	}
	
	cout<<endl<<"After sort"<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
