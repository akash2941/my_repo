#include<iostream>

using namespace std;
void BubbleSort(int a[] , int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j] > a[j+1])  //for desending prenting ( < )
            {
                int temp = a[j];
                    a[j] =  a[j+1];
                    a[j+1]=temp;
            }
        }
    }

}

int main()
{
    int i;
    int a[] = {56,38,15,27,3,88,95};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<"Before sorting Array : \n";
    for( i=0;i<n;i++)
    {
      cout<<a[i]<<" ";

      cout<<endl;
    }
    BubbleSort(a ,n);  //Sorting

    cout<<"Sorted Array : \n";

    for( i=0;i<n;i++)
    {
      cout<<a[i]<<" ";

      cout<<endl;
    }
}