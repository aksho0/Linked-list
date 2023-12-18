#include<iostream>
#include<vector>
using namespace std;

int FirstOcurance(vector<int> v, int n, int k) {

    int ans = -1, st = 0, en = n-1;
    while(st <= en) {
        int mid = st + (en - st)/2;

        if(v[mid] == k) {
            ans = mid;
            en = mid - 1;
        }
        else if(v[mid] < k) {
            st = mid + 1;
        }
        else {
            en = mid - 1;
        }
    }

    return ans;
}

int LastOcurance(vector<int> v, int n, int k) {

    int ans = -1, st = 0, en = n-1;
    while(st <= en) {
        int mid = st + (en - st)/2;

        if(v[mid] == k) {
            ans = mid;
            st = mid + 1;
        }
        else if(v[mid] < k) {
            st = mid + 1;
        }
        else {
            en = mid - 1;
        }
    }

    return ans;
}

int main() {

    vector<int> v = {1,2,3,3,3,3,4,3,5};
    int n, k = 3;
    k = v.size();

    // pair<int,int> p;

    // p.first = FirstOcurance(v, v.size(), 3);
    // p.second = LastOcurance(v, v.size(), 3);

    // cout<<"First ocurance of 3 is at index "<<p.first<<" and last ocurance is at index "<<p.second<<endl;

    int f, l;
    f = FirstOcurance(v, n, k);
    l = LastOcurance(v, n, k);

    cout<<"First ocurance of 3 is at index "<<f<<" and last ocurance is at index "<<l;


    return 0;
}