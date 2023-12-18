#include<iostream>
using namespace std;

int main() {

    int n, reverse = 0, lastdigit;

    cout<<"Enter a number : ";
    cin>>n;

    while(n > 0) {
        lastdigit = n%10;
        reverse = reverse*10 + lastdigit;
        n /= 10;
    }

    cout<<"The reverse of the inputed number is "<<reverse;

    return 0;
}