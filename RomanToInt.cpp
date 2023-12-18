#include<iostream>
#include<string>
using namespace std;

int getValue(char c) {

    switch(c) {
        case 'I' : return 1;
        case 'V' : return 5;
        case 'X' : return 10;
        case 'L' : return 50;
        case 'C' : return 100;
        case 'D' : return 500;
        case 'M' : return 1000;
    }
}

int RomanToInt(string str) {

    int r1, r2;
    int ans = 0;

    for(int i=0; i<str.length(); i++) {

        r1 = getValue(str[i]);
        if(i+1 < str.length()) {
            r2 = getValue(str[i+1]);
        }
        else {
            r2 = 0;
        }

        if(r1 > r2) {
            ans += r1;
        }
        else if(r1 == r2) {
            ans += r1 + r2;
            i++;
        }
        else {
            ans = ans - r1;
        }
    }
    return ans;
}

int main() {

    string str;

    cout << "Enter a Roman number : ";
    cin >> str;

    cout << "Integer : " << RomanToInt(str) << endl;

    return 0;
}

/*
DRY RUN

let str = XIV(14),
    r1 = X        r2 = I
    
    clearly r1 > r2, therefor we'll add X to the ans,
        ans = 10

    i++, r1 = I        r2 = V

    clearly r1 < r2, therefor we'll subtract r1 ans
        ans = 10 - 1 = 9

    i++, r1 = V         r2 = 0

    clearly r1 < r2, therefor we'll add r1 to ans
        ans = 9 + 5 = 14


let str = XX(20)

    r1 = X           r2 = X

    clearly r1 == r2, therefor we'll add r1 and r2 then add the sum to ans
        ams = 10 + 10 = 20;

*/