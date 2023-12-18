#include<bits/stdc++.h>
using namespace std;

int BinaryToDec(int a) {

    int i, digit, base = 1, num = 0;

    for(i = a; i > 0; i /= 10) {
        
        digit = i % 10;
        
        if(digit > 2) {
            return 0;
        }
        
        num += base * digit;
        base *= 2;
    }

    return num;
}

int OctalToDec(int a) {

    int i, digit, base = 1, num = 0;

    for(i = a; i > 0; i /= 10) {

        digit = i % 10;
        
        if(digit > 9) {
            return 0;
        }

        num += base * digit;
        base *= 8;
    }

    return num;
}

int HexaToDec(string a) {
    
    int i, base = 1, num = 0;
    int size = a.size();

    for(i = (size-1); i >= 0; i--) {

        if(a[i] >= '0' && a[i] <= '9') {
            num += base * (a[i]-'0');
        }
        else if(a[i] >= 'A' && a[i] <= 'F') {
            num += base * ((a[i]-'A') + 10);
        }
        base *= 16;
    }

    return num;

}

int DecToBinary(int a) {

    int num = 0, base = 1;
    while(base <= a) {
        base *= 2;
    }
    base /= 2;

    while(base > 0) {
        int lastDigit = a / base;
        a -= lastDigit * base;
        base /= 2;
        num = (num*10 + lastDigit);
    }

    return num;

}

int DecToOctal(int a) {

    int num = 0, base = 1;
    while(base <= a) {
        base *= 8;
    }
    base /= 8;

    while(base > 0) {
        int lastDigit = a / base;
        a -= lastDigit * base;
        base /= 8 ;
        num = (num*10 + lastDigit);
    }

    return num;

}

string DecToHexa(int a) {

    int base = 1;
    string num = "";

    while(base <= a) {
        base *= 16;
    }
    base /= 16;

    while(base > 0) {
        int lastDigit = a / base;
        a -= lastDigit * base;
        base /= 16;

        if(lastDigit <= 9) {
            num = num + to_string(lastDigit);
        }
        else {
            char c = 'A' + lastDigit - 10;
            num.push_back(c);
        }
    }

    return num;

}


int main() {

    int choice;

    cout<<"Enter your choice -\n1.Other base to Decimal\n2.Decimal to other base\n3.Other base to other base\n";
    cin>>choice;

    switch(choice) {

        int ch, x;

        case 1 :
            cout<<"Enter type of number which you want to convert into decimal -\n1.Binary\n2.Octal\n3.Hexadecimal\n";
            cin>>ch;

            if(ch == 1) {
                cout<<"Enter a binary number : ";
                cin>>x;

                cout<<BinaryToDec(x);
            }
            else if(ch == 2) {
                cout<<"Enter a Octal number : ";
                cin>>x;

                cout<<OctalToDec(x);
            }
            else {

                string n;

                cout<<"Enter a HexaDecimal number : ";
                cin>>n;

                cout<<HexaToDec(n);
            }
            break;

        case 2 :
            
            cout<<"Enter type of number which you want to convert the decimal -\n1.Binary\n2.Octal\n3.Hexadecimal\n";
            cin>>ch;

            if(ch == 1) {
                cout<<"Enter a decimal number : ";
                cin>>x;

                cout<<DecToBinary(x);

            }
            else if(ch == 2) {
                cout<<"Enter a decimal number : ";
                cin>>x;

                cout<<DecToOctal(x);
            }
            else {
                cout<<"Enter a decimal number : ";
                cin>>x;

                cout<<DecToHexa(x);
            }
            break;
            
        case 3 :

            cout<<"Enter your choice\n1.Binary to Octal\n2.Binary to HexaDecimal\n3.Octal to Binary\n4.Octal to HexaDecimal\n5.HexaDecimal to Binary\n6.HexaDecimal to Octal\n";
            cin>>ch;

            if(ch == 1) {
                cout<<"Enter a Binary number : ";
                cin>>x;

                cout<<DecToOctal(BinaryToDec(x));
            }
            else if(ch == 2) {
                cout<<"Enter a Binary number : ";
                cin>>x;

                cout<<DecToHexa(BinaryToDec(x));
            }
            else if(ch == 3) {
                cout<<"Enter an Octal number : ";
                cin>>x;

                cout<<DecToBinary(OctalToDec(x));
            }
            else if(ch == 4) {
                cout<<"Enter an Octal number : ";
                cin>>x;

                cout<<DecToHexa(OctalToDec(x));
            }
            else if(ch == 5) {

                string n;

                cout<<"Enter a HexaDecimal number : ";
                cin>>n;

                cout<<DecToBinary(HexaToDec(n));
            }
            else if(ch == 6) {

                string n;

                cout<<"Enter a HexaDecimal number : ";
                cin>>n;

                cout<<DecToOctal(HexaToDec(n));
            }
            break;
        
        default :
            cout<<"Enter vailid choice\n";
    }
    return 0;
}