#include<iostream>
#include<queue>
using namespace std;

int main() {

    //max heap
    priority_queue<int> maxHeap;

    maxHeap.push(50);
    maxHeap.push(55);
    maxHeap.push(53);
    maxHeap.push(52);
    maxHeap.push(54);

    cout << "Max heap -" << endl;
    while(!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }cout << endl;

    //min heap
    priority_queue<int, vector<int>, greater<int> > minHeap;

    minHeap.push(50);
    minHeap.push(55);
    minHeap.push(53);
    minHeap.push(52);
    minHeap.push(54);

    cout << "Min Heap -" << endl;
    while(!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }cout << endl;

    return 0;
}