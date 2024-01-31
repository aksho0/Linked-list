#include<iostream>
using namespace std;

int main() {

    char ch[5] = "abcd";

    //cout works diifrently with character arrays or strings
    //unlike int array, cout will keep printing the characters untill it find '\0'
    
    cout << ch << endl;  //output - abcd

    //If you closely look, you'll notice that array ch has 4 characters
    //but its size is 5, this is bz the last sapce is occupied by the NULL character'\0'
    //this space is preoccupied, we can't change it
    //that's why cout will always print the whole array bz at the end there is a NULL charater

    //similarly, if we point the first element with a pointer cout will behave in the same manner 
    char * c = &ch[0];
    cout << c << endl; // output - abcd

    /*
        IMPORTANT :
            NEVER directly assign any charcter array to a pointer
                char *c = "abcd" DONT'T DO THIS
            bz if you try to print this or access this pointer, it will look for '\0'
            and it may possible that it will read some ROM which can cause harm to you're pc's memeory

            INSTEAD point the pointer to an alreay existing array
    */

   

    return 0;
}