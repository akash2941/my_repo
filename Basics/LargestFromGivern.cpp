10. WAP to Find the largest number among the given
Numbers
#include <iostream>

using namespace std;

int main()
{
    int a=3,b=4,c=10;
    if(a>b && a>c){
        cout<<"is greatest among three numbers"<<a;
    }
    else if(b>a && b>c){
        cout<<"is greatest among three numbers"<<b;
    }
    else if(c>a && c>b){
        
        cout<< "is greatest among three numbers"<<c;
    }
    return 0;
}

