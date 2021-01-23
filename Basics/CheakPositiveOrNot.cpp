//2. WAP to Check if a Number is Positive or Negative

#include<iostream>
using namespace std;
int main ()
{
    int num;
    cout << "Enter the number : ";
    cin >> num;
    if (num >= 0)
        cout << num << " is a positive number.";
    else 
        cout << num << " is a negative number.";
    return 0;
}

