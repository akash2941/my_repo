#include<iostream>

using namespace std;

int binarySearch(int arr[] ,int left ,int right ,int x)
{
    int mid =  (right+left)/2;
    while(left<=right)
    {
        
        if(arr[mid]==x)
        {
            return mid;
        }
        else if(arr[mid] < x)
        {
            left = mid +1;
        }
        else 
        {
            right = mid - 1;
        }
        mid=(right+left)/2;
    }

    return -1;
}



int main()
{
    int num;
    int arr[10];
    int output;

    cout<<"Enter 10 int in assending Order : ";
    for(int i=0;i<10;i++)
    {
        cin>>arr[i];
    }

    cout<<"Enter Search element ";
    cin>>num;

    output=binarySearch(arr,0,9,num);

    if(output == -1)
    {
        cout<<"no match found"<<endl;
    }
    else
    {
        cout<<"match found at index "<<output<<endl;
    }

}