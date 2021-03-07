#include<iostream>

using namespace std;

void insertionSort(int a[],int n)
{
    int i,j,temp;
    for (i=1;i<n;i++)
    {
        temp=a[i];

        for(j=i-1 ; j>=0 && temp < a[j] ; j--)
        {
            a[j+1]=a[j];
        }
        a[j+1]=temp;
    }
}

int main()
{
    int i,size;
    cout<<"Enter a size of array : \n";
    cin>>size;
    cout<<"Enter Array Elements : \n";
    int a[size];
    for( i=0;i<size;i++)
    {
      cin>>a[i];
    }
    cout<<"Before sorting Array : \n";
    for( i=0;i<size;i++)
    {
      cout<<a[i]<<" ";

      cout<<endl;
    }
    insertionSort(a ,size);  //calling Sorting fn passing arry and size

    cout<<"After Sorting Array : \n";

    for( i=0;i<size;i++)
    {
      cout<<a[i]<<" ";

      cout<<endl;
    }
}