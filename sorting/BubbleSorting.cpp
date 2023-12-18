#include<iostream>
using namespace std;
/*
    Bubble sort :
        Repeatedlly swap two adjacent elements if they 
        are in wrong order
*/

int* BubbleSort(int* arr, int n) {

    int counter = 1;
    while(counter < n) {
        for(int i = 0; i < n-counter; i++) {
            if(arr[i] > arr[i+1]) {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
        counter++;
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

    ar = BubbleSort(ar, n);

    cout<<"Sorted array -\n";
    for(int i = 0; i < n; i++) {
        cout << " " << ar[i];
    }

    return 0;
}