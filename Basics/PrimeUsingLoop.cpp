//Q1  cheak prime using loop

#include <iostream>
int main() {
    int n, i, temp= 0;
    cout<<"Enter a num";
    cin>>n;

    for (i = 2; i <= n / 2; ++i) {


        if (n % i == 0) {
            temp= = 1;
            break;
        }
    }

    if (n == 1) {
        cout<<"1 is neither prime nor composite";
    }
    else {
        if (temp== 0)
            cout<<n <<" is a prime number";
        else
            cout<<n <<" is not a prime number";
    }

    return 0;
}

