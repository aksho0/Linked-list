#include<iostream>
#include <cmath>
using namespace std;

int main() {

    int n, i;
    cout<<"Enter a number :";
    cin>>n;

    for(i = 2; i < sqrt(n); i++) {
        if(n%i == 0) {
            cout<<n<<" is a non prime number\n";
            break;
        }
    }

    if(i == n) {
        cout<<n<<" is a Prime number\n";
    }

    return 0;
}