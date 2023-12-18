#include<iostream>
using namespace std;

/*  
    Selection sorting :
        Find the minimum element in the unsorted array and 
        swap it with element at begining
*/

int* SelectionSort(int* arr, int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[i]) {
                // int temp = arr[j];
                // arr[j] = arr[i];
                // arr[i] = temp;
                swap(arr[i], arr[j]);
            }
        }
    }
    return arr;
}

int main() {

    int *ar, n;

    cout<<"Enter size of array : ";
    cin>>n;

    ar = (int*) malloc(sizeof(int) * n);

    cout<<"Enter elements -\n";
    for(int i = 0; i < n; i++) {
        cin>>ar[i];
    }

    ar = SelectionSort(ar, n);

    cout<<"Sorted array -\n";
    for(int i = 0; i < n; i++) {
        cout << " " << ar[i];
    }

    return 0;
}