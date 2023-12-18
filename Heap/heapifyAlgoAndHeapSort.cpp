#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i) { 

        int largest = i;
        int left = 2*i; // for 0 based indexing, for 1 based indexing the formula will be 2*i
        int right = 2*i + 1; // for 1 based indexing , 2*i + 1

        if(left <= n && arr[largest] < arr[left]) {
            largest = left;
        }
        if(right <= n && arr[largest] < arr[right]) {
            largest = right;
        }

        if(largest != i) {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }

    void Heapsort(int arr[], int size) {

        for(int i = size/2 - 1; i > 0; i--) {
            swap(arr[1], arr[i]);
            heapify(arr, i, 1);
        }

    }

int main() {

    int arr[] = {-1, 50, 55, 53, 52, 54};
    int n = 5;

    //heap craetion
    for(int i=n/2 - 1; i>0; i--) {
        heapify(arr, n, i);
    }

    cout << "heap created with heapify algo -" << endl;
    for(int i=1; i<=n; i++) {
        cout << arr[i] << " ";
    } cout << endl;

    Heapsort(arr, n);
    cout << "heap after sorting -" << endl;

    for(int i=1; i<=n; i++) {
        cout << arr[i] << " ";
    } cout << endl;

    return 0;
}