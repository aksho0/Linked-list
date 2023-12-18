#include<iostream>
using namespace std;

/*
    The approach here is to check if the bitwise AND oprtation between n nad n-1 is 0 or not.
    
    See the bitwise AND operation will always return 0 if its power of 2 otherwise the number 
    is not a powert of two.

    For instance, n = 8 = (1000)
                  (n-1) = 7 (0111)

    The And operation between them will gives us 

            1 0 0 0
            &
            0 1 1 1
            --------
            0 0 0 0 

    So, 8 & 7 = 0 in binary, that means 8 is power of 2.

    Let's take another example, n = 98 = (1100010)
                                (n-1) = 97  = (1100001)

    The And operation between them will gives us 

            1 1 0 0 0 1 0
            &
            1 1 0 0 0 0 1
            -------------
            1 1 0 0 0 0 0

    So, 98 & 97 = 11000 in binary, that means 98 is not power of 2.
    */

bool powerOfTwo(long long n) {

    if(n <= 0) {
        return 0;
    }

    return (n & (n-1)) == 0 ? 1 : 0;
}

int main() {

    cout<<"Enter a number\n";
    int n;
    cin >> n;

    if(powerOfTwo(n)) {
        cout << "Number is power of two" << endl;
    }
    else{
        cout << "Number is not power of two" << endl;
    }

    return 0;
}