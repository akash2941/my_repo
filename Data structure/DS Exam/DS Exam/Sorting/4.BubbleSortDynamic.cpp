#include<iostream>

using namespace std;
void swaparray(int *a, int *b)
{
    int ptr = *a;
    *a =*b;
    *b=ptr;
}
void BubbleSort(int a[] , int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j] > a[j+1])  //for desending prenting ( < )
            {
                swaparray(&a[j], &a[j+1]);
            }
        }
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
    BubbleSort(a ,size);  //Sorting

    cout<<"After Sorting Array : \n";

    for( i=0;i<size;i++)
    {
      cout<<a[i]<<" ";

      cout<<endl;
    }
}