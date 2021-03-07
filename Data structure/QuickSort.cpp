#include<iostream>
using namespace std;

int partition(int[],int,int);
void quicksort(int[],int,int);

int main()
{
	int N;
	cin>>N;
	int *arr;
	arr=new int[N];
	for(int i=0;i<N;i++){
		cin>>arr[i];
	}
	cout<<"Before sort"<<endl;
	for(int i=0;i<N;i++){
		cout<<arr[i]<<" ";
	}
	int lb=0;
	int ub=N-1;
	
	quicksort(arr,lb,ub);
	
	cout<<"After sort"<<endl;
	for(int i=0;i<N;i++){
		cout<<arr[i]<<" ";
	}
return 0;
}

void quicksort(int arr[],int lb,int ub){
	if(lb<ub){
		int location=partition(arr,lb,ub);
		quicksort(arr,lb,location-1);
		quicksort(arr,location+1,ub);
	}
}

int partition(int arr[],int lb,int ub){
	int pivot=arr[lb];
	int start=lb;
	int end=ub;
	
	while(start<end){
		while(arr[start]<=pivot){
			start++;
		}
		while(arr[end]>pivot){
			end--;
		}
		if(start<end){
			int temp=arr[start];
			arr[start]=arr[end];
			arr[end]=temp;
		}
	}
	int temp=arr[end];
	arr[end]=arr[lb];
	arr[lb]=temp;
	return end;
}

