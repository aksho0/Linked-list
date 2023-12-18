/*
    Find the last occurance of x in a vector
    print the index of the last occurence of the value
*/

#include<iostream>
#include<vector>
using namespace std;

int lastOccurence(vector<int> v, int x) {

    int ans = 0;

    //traversing from the start
    // for(int i = 0; i < v.size(); i++) {
    //     if(v[i] == x) {
    //         ans = i;
    //     }
    // }

    //trversing from the end
    for(int i = v.size()-1; i > 0; i--) {
        if(v[i] == x) {
            ans = i;
            break;
        }
    }
    return ans;
}

int main() {

    vector<int> v(6);
    for(int i = 0; i < 6; i++) {
        cin>>v[i];
    }

    int x, occurence = 0;
    cout<<"Enter x : ";
    cin>>x;

    cout<<lastOccurence(v,x)<<endl;

    return 0;
}