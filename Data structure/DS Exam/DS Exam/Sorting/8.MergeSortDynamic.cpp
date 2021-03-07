#include<iostream>

using namespace std;

//merge function (comparing each elements)
void merge(int arr[], int left , int m, int right)
{
    int i= left; //starting index for left sub array
    int j=m+1;    //starting index for Right sub array
    int k= left;    //starting index of temporary array
    
    int size = (right -left ) + 1; //calculating the size of array
    int temp[size];  //temp array

    while (i<=m  && j<= right)
    {
        if(arr[i] <= arr[j])
        {
            temp[k]=arr[i];  //arr[i] is smaller them arr[j]
            i++;
            k++;
        }
        else
        {
            temp[k]=arr[j];  //arr[j] is smaller them arr[i]
            j++;
            k++;
        }

        while(i<=m)
        {
            temp[k]=arr[i];  //copying all elements from left subarray to temp asit is
            i++;
            k++;
        }

        
        while(j<=right)
        {
            temp[k]=arr[j];  //copying all elements from Right subarray to temp asit is
            j++;
            k++;
        }

        for(int p=left;p<=right;p++)
             {
                arr[p] = temp[p]; //Copy all elements frop temp to main array 
            }
    }

}


//MergeSort Function Recursion vala
void MergeSort(int arr[] , int left, int right)
{
   if(left<right)
   {
       int m=(left + right)/2;

       MergeSort(arr,left,m); //for left sub array

       MergeSort(arr,m+1,right); //for right sub array

       merge(arr,left,m,right);  //Merge Function
   }

}

int main()
{
    int i,size;
    cout<<"Enter a size of array : \n";
    cin>>size;
    cout<<"Enter "<<size<<"No of Elements of array : \n";
     int arr[size];

    for( i=0;i<size;i++)
    {
      cin>>arr[i];
    }
    cout<<"Before sorting Array : \n";
    for( i=0;i<size;i++)
    {
      cout<<arr[i]<<" ";

      cout<<endl;
    }
    MergeSort(arr,0,(size-1));  // right index is size-1 

    cout<<"After Sorting Array : \n";

    for( i=0;i<size;i++)
    {
      cout<<arr[i]<<" ";

      cout<<endl;
    }
}