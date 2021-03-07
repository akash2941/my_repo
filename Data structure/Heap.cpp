#include<iostream>
using namespace std;
void MaxHeap(int *arr,int N,int i){
	int largest=i;
	int l=(i*2)+1;
	int r=(i*2)+2;
	
	if(l<N && arr[l]>arr[largest]){
		largest=l;
	}
	if(r<N && arr[r]>arr[largest]){
		largest=r;
	}
	if(largest!=i){
		int temp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;
		MaxHeap(arr,N,largest);
	}
}

void Heapyfy(int *arr,int N){
	for(int i=(N/2)-1;i>=0;i--){
		MaxHeap(arr,N,i);
	}
	for(int i=N-1;i>0;i--){
		int temp=arr[0];
		arr[0]=arr[i];
		arr[0]=temp;
		MaxHeap(arr,i,0);
	}
}

int main()
{
	int N;
	cout<<"Enter size of array"<<endl;
	cin>>N;
	int arr[N];
	for(int i=0;i<N;i++){
		cin>>arr[i];
	}
	cout<<"Before HIpiFy"<<endl;
	for(int i=0;i<N;i++){
		cout<<arr[i]<<" ";
	}
	Heapyfy(arr,N);
	cout<<"After HIpiFy"<<endl;
	for(int i=0;i<N;i++){
		cout<<arr[i]<<" ";
	}
}
