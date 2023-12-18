#include<iostream>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    for(int i = 2; i < sqrt(num); i++) {
        if(num%i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {

    int a, b;
    cout<<"Enter the range : ";
    cin>>a>>b;

    for(int i = a; i < b; i++) {
        if(isPrime(i)==1) {
            cout<<i<<endl;
        }
    }

    cout<<"The above numbers are prime numbers from "<<a<<"to "<<b;
 
    return 0;
}