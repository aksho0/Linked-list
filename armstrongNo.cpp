#include<iostream>
#include <math.h>
using namespace std;

int main() {

    int n, sum = 0;
    cout<<"Enter a number :";
    cin>>n;

    // **Code from ApnaCollege -->
    // while(n > 0) {
    //     int lastdigit = n%10;
    //     sum += pow(lastdigit,3);
        /*  this gives an strange output as 27 + 125 + 1= 152
            instead of 153, every other case is tru but only 
            in case 153 , its sowing that */
    //     n /= 10;
    // } **

    for(int i = n; i != 0; i/=10) {
        int lg = i%10;
        sum += (lg*lg*lg);
        // bz of the above gllitch , I used (lg*lg*lg) istead of pow function
    }

    if(sum == n) {
        cout<<"The number is an armstrong number";
    }
    else {
        cout<<"The number is not an armstrong number\n";
    }

    return 0;
}
