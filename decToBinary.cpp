#include <iostream>
#include <string>
using namespace std;

int DecToBinary(int a) {

    int num = 0, base = 1;
    while(base <= a) {
        base *= 2;
    } 
    base /= 2; cout << "base = " << base << endl;

    while(base > 0) {
        int lastDigit = a / base;  
        a -= lastDigit * base;
        base /= 2;
        num = num*10 + lastDigit;
    }

    return num;

}


int main() {
  
  int x;
  
  cout <<"Enter a decimal number : ";
  cin >>x;

  cout<<"Binary form : "<<DecToBinary(x);
  

}