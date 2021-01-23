21. WAP to Convert Octal to Decimal
#include <iostream>
using namespace std;
int main()
{
    long int octal, decimal = 0;
    int i = 0;
 
    cout<<"Enter any octal number";
    cin>>octal;
    while (octal != 0)
    {
        decimal =  decimal +(octal % 10)* pow(8, i++);
        octal = octal / 10;
    }
    cout<<"Equivalent decimal value:"<<decimal;
    return 0;
}

