#include<iostream>
using namespace std;
void divide(int[],int,int);
void merge(int[],int,int,int);//merge(int *,int,int,int);

int main()
{
	int N;
	cin>>N;
	int arr[N];
	for(int i=0;i<N;i++){
		cin>>arr[i];
	}
	cout<<"Before sort"<<endl;
	for(int i=0;i<N;i++){
		cout<<arr[i]<<" ";
	}
	
	divide(arr,0,N);
	cout<<endl;
	cout<<"After sort"<<endl;
	for(int i=0;i<N;i++){
		cout<<arr[i]<<" ";
	}
return 0;
}  

void divide(int arr[],int B,int E){
	int mid;
	mid=(B+E)/2;
	
	if(B<E){
		divide(arr,B,mid);
		divide(arr,mid+1,E);
		merge(arr,B,mid,E);
	}
}

void merge(int arr[], int B, int mid, int E) 
{ 
    int i, j, k; 
    int n1 = mid - B + 1; 
    int n2 =  E - mid; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[B + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[mid + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = B; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
