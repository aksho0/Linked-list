#include<iostream>
using namespace std;

int main() {

    char str[128];

    cout << "Enter a string" << endl;
    scanf("%[a-z]s", str);

    cout << "Your stirng " << str;

    return 0;
}