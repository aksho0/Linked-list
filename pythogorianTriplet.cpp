#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

bool check(int a, int b, int c) {

    int maxi = max(a, max(b, c));
    int x, y;

    if(maxi == a ) {
        x = b;
        y = c;
    }
    else if(maxi == b) {
        x = a;
        y = c;
    }
    else {
        x = a;
        y = b;
    }

    if(pow(maxi, 2) == (pow(x, 2) + pow(y, 2))) {
        return 1;
    }

    return 0;
}

int main() {

    int x, y, z;
    cout<<"Enter three numbers : ";
    cin>>x>>y>>z;

    if(check(x,y,z)) {
        cout<<"Entered numbers are triplet";
    }
    else {
        cout<<"Entered numbers are not triplet";
    }

    return 0;
}