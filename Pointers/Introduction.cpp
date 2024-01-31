#include<iostream>
using namespace std;

/*   

    Pointers are symbolic represantaion of address

*/

int main() {

    //Pointers hold the address of any other variable
    //To declare a pointer we use astric sign or (*)
    
    int a = 7;
    int *ptr = &a;  //Here ptr is a pointer to int holding the address of variable a
    //         ^
    // we use '&' operator here viz also called the address of operator
    // by using this address of oprator we can assign the address of any variable to a pointer

    /*NOTE : 
            NEVER (only) declare a pointer variable, its considered as a bad practice 
            Always DCLARE & INITIALIZE a pointer variable

            If we olny declare a pointer variable, the compiler may assign it any garbage address,
            and it is possible that complier assign an address of ROM, and then if you try to upgrade
            or change the address, it can cause serious damage to you're computer's memory.

    */

   //We can retrive a's value with the use of pointer ptr
   cout << "Value of a is " << a << endl;
   cout << "Value of a is " << *ptr << endl;

   //We can accsess the address of a with pointer ptr
   cout << "Address of a is " << &a << endl;
   cout << "Address of a is " << ptr << endl;

   //You can accsess, upgarade and even change the value of a using ptr
   cout << "Before changing " << a << endl;
   a = a + 1;
   cout << "After changing " << a << endl;

   cout << "Before changing " << *ptr << endl;
   *ptr = *ptr + 1;
   cout << "After changing " << *ptr << endl;

   //A pointer holds 8bytes of space in memory
   cout << "Size of ptr is " << sizeof(ptr) << endl;

    return 0;
}