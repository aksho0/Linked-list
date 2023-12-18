#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int const s,int const mid, int const e) {
    
    //finding lengths
    int const len1 = mid - s + 1;
    int const len2 = e - mid;

    //declaring arrays to copy the values
    // int first[len1];
    // int second[len2];
    
    // initializing arrays in this way 
    //bz delete[] cannot be used without new
    int *first= new int[len1], 
        *second = new int[len2];


    //copying the values in the arrays
    for(auto i = 0; i < len1; i++) {
        first[i] = arr[s + i];
    }

    for(auto i = 0; i < len2; i++) {
        second[i] = arr[mid + 1 + i];
    }

    //merging while sorting the arrays 
    auto index1 = 0, index2 = 0, mainIndex = s;

    while(index1 < len1 && index2 < len2) {
        if(first[index1] <= second[index2]) {
            arr[mainIndex++] = first[index1++];
        }
        else {
            arr[mainIndex++] = second[index2++];
        }
    }

    //checking if any values is remaining 
    while(index1 < len1) {
        arr[mainIndex++] = first[index1++];
    }
    while(index2 < len2) {
        arr[mainIndex++] = second[index2++];
    }

    // free(first);
    // free(second);
    //using delete bz delete[] function is faster than free()
	delete[] first;
    delete[] second;
}

void mergeSort(int arr[], int s, int e) {

    //base case
    if(s >= e) {
        return;
    }

    int const mid = s + (e - s) / 2;
    
    //call for left part
    mergeSort(arr, s, mid);

    //call for right part
    mergeSort(arr, mid+1, e);

    //merging 
    merge(arr, s, mid, e);

}

int main() {

    int arr[] = {9, 5, 3, 1, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "initial array " << endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    } cout << endl;

    //the code lines are not working after this function call just like in dectectAndRemoveLoop.cpp file
    mergeSort(arr, 0, n-1);

    cout << "array after sorting" << endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}