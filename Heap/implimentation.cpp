#include<iostream>
#include<vector>
using namespace std;

class heap {
public:

    vector<int> v;

    heap() {
        v.push_back(-1);
    }

    void insert(int val) {

        if(v.size() == 1) {
            v.push_back(val);
            return;
        }

        //insert at end
        int idx = v.size();
        v.push_back(val);

        //taking the element to it's correvt positon
        while(idx > 1) {
            int parent = idx/2;

            if(v[parent] < v[idx]) {
                swap(v[parent], v[idx]);
                idx = parent;
            }
            else {
                return;
            }
        }

    }

    void print() {

        for(int i=1; i<v.size(); i++) {
            cout << v[i] << " ";
        } cout << endl;
    }

    void deltetion() {

        if(v.size() == 1) {
            cout << "Heap is empty" << endl;
            return ;
        }

        int idx = v.size()-1;

        //replacing last element with root element
        v[1] = v[idx];

        //removing last element
        v.pop_back();

        int i = 1;

        //taking the root element to it's right positon
        while(i <= idx) {

            int leftIdx = 2*i;
            int rightIdx = 2*i+1;
            
            if(leftIdx < v.size() && v[i] < v[leftIdx]) {
                swap(v[i], v[leftIdx]);
                i = leftIdx;
            }

            else if(rightIdx < v.size() && v[i] < v[rightIdx]) {
                swap(v[i], v[rightIdx]);
                i = rightIdx;
            }
            else {
                return ;
            }
        }
    }
};

int main() { 

    heap h; 
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    h.deltetion();
    h.print();

    return 0;
}