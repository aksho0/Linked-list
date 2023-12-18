#include<iostream>
using namespace std;

int main() {

    int arr[5] = {2,4,7,8,1};
    //Here arr holds the address of the first element of the array
    
    //we can retrive the address of first element(0th)
    cout << "Address of 0th element is " << arr << endl;

    //This means arr is a pointer to the first element of the array
    //Linke a pointer, we can perform pointer operation on this also
    
    //Acessing the first element
    cout << "First element is " << *arr << endl;
    //                             ^
    //By using derefrence operator we can access the first element

    //this can be done by just giving the index of any element
    cout << "First element is " << arr[0] << endl;


    //Now, if we add 1 to any pointer, it will add the no. of bits of the pointer's datatype
    //means, if a pointer is int type and we add 1 to it, it will change its address location and move to next block
    //like for e.g > ptr = 200 and if we add 1 to ptr, than ptr = 204

    cout << "2nd element is " << *(arr + 1) << endl;
    //                           ^  ^    ^
    // arr is holding the address of 1st element and by adding 1 to it
    // it will move to the next block and bz the dereference operator is outside the backet
    // it will return the value at the given address
    //This is exactly what happen when we accsess any element by giving the index
    //viz, arr[i] is exactly same to *(arr + i)

    //We can manipulate the value by performing arithemetic operations with the use of pointers
    cout << "1st element + 1 is " << *(arr) + 1 << endl;
    //                               ^  ^     ^
    // here arr is with the dereference operator, means it will retrive the value
    // by adding 1 to it means we're adding 1 to the value itself NOT with the address

    //the above line and the below line is exactly same
    cout << "1st element + 1 is " << *arr + 1 << endl;

    //we can use increment operator with the value but cann't with the address
    cout << "1st element ++ is " << (*arr)++ << endl;
    //                                 ^   ^
    //here (*arr) will give the value and ++ will increment it
    //but *arr++ will through error
    //similary arr++ or *(arr)++ will also through error
    //bz we're trying to increment the address viz not possible
    // a pointer is holding a address of any other variable and 
    // by changing the address value we'll lose the access to the variable's location
    // whose address is that pointer is holding
    // but we can access the next or prev elements 
    
    //Traversing the array -
    
    //By the usual method
    for(int i=0; i<5; i++) {
        cout << arr[i] << " "; // here arr[i] = *(arr + i)
    } cout << endl;

    //With pointers
    for(int i=0; i<5; i++) {
        cout << *(arr + i) << " ";
    } cout << endl;

    //By exchanging the positons 
    for(int i=0; i<5; i++) {
        cout << i[arr] << " "; // here i[arr] = *(i + arr)
    } cout << endl;

    // this will give the exact same output bz the functioning running behind is ecactly same
    // they all are performing *(arr + i) operation

    return 0;
}