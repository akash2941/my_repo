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
    int i;
    int a[]={22,36,45,11,88,95,76};
    int n = sizeof(a)/sizeof(a[0]);  //Finding Actual size of array
    cout<<"Unsorted Array :"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
        cout<<endl;
    }
    insertionSort(a ,n);

    cout<<"Sorted Array :"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
        cout<<endl;
    }

}