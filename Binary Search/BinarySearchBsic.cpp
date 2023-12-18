#include<iostream>
using namespace std;

int BinarSearch(int* arr, int key, int n) {

    int st = 0, en = n;
    
    while(st <= en) {
    
        //in special case the sum of st+en can go higher than the range of int, that's why we used this formula to calulate mid
        int mid = st + (en - st) / 2; // st + (en - st)/2 = st + en/2 - st/2 = (2st-st+en)/2 = (st+en)/2

        if(arr[mid] == key) {
            return mid;
        }
        
        else if(arr[mid] < key) {
            st = mid+1;
        }
        
        else {
            en = mid-1;
        }
    } 

    return -1;
}

int main() {

    int *ar, n, key;
    cout<<"Enter thr size of the array : ";
    cin>>n;
    ar = (int*) malloc(sizeof(int)*n);
    cout<<"Enter elements :-\n";
    for(int i = 0; i < n; i++) {
        cin>>ar[i];
    }
    cout<<"Enter key : ";
    cin>>key;

    cout<<BinarSearch(ar, key, n);

    return 0;
}