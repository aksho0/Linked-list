#include<iostream>
using namespace std;

void fib(int num) {

    int nextTerm, t1 = 0, t2 = 1;
    for(int i = 0; i < num; i++) {
        cout<<t1<<endl;
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
}

int main() {

    int a;
    cout<<"Enter a number : ";
    cin>>a;

    fib(a);

    return 0;
}