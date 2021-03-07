#include<iostream>

using namespace std;

//merge function (comparing each elements)
void merge(int arr[], int left , int m, int right)
{
    int i= left; //starting index for left sub array
    int j=m+1;    //starting index for Right sub array
    int k= left;    //starting index of temporary array
    
    int temp[5];  //temp array

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


//MergeSort Function
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
    int i;
    int arr[5] = {56,38,15,27,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Before sorting Array : \n";
    for( i=0;i<n;i++)
    {
      cout<<arr[i]<<" ";

      cout<<endl;
    }
    MergeSort(arr,0,4);  //pass array left index and right index

    cout<<"After merge Sort: \n";
    for( i=0;i<n;i++)
    {
      cout<<arr[i]<<" ";

      cout<<endl;
    }
}
