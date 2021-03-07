#include<iostream>

using namespace std;

void linearSearch(int a[], int n) {
	int temp = -1;
	for(int i=0; i<5; i++) {
		if(a[i]==n) {
			cout<<"Elements found at location : "<<i<<endl;
			temp = 0;
		}

	}
	if(temp == -1) {
		cout<<"No Element found ";
	}

}



int main() {
	int arr[5]= {1,38,78,55,7};
	cout<<"Please Enter an element to search : "<<endl;
	int num;
	cin>>num;
	linearSearch(arr,num);
	return 0;
}

