19. WAP to Represent a number as Sum of Two Prime
Numbers
Input: 34 Output: 34 = 3 + 31, 34 = 5 + 29, 34 = 11 +
23, 34 = 17 + 17

#include <iostream>
using namespace std;
int checkPrime(int n);
int main() {
    int n, i, flag = 0;
    cout<<"Enter a positive integer";
    cin>>n;
    for (i = 2; i <= n / 2; ++i) {
        if (checkPrime(i) == 1) {
            
            if (checkPrime(n - i) == 1) {
                printf("%d = %d + %d\n", n, i, n - i);
                flag = 1;
            }
        }
    }
    if (flag == 0)
        cout<<" cannot be expressed as the sum of two prime numbers."<< n;

    return 0;
}
int checkPrime(int n) {
    int i, isPrime = 1;
    for (i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            isPrime = 0;
            break;
        }
    }
    return isPrime;
}

