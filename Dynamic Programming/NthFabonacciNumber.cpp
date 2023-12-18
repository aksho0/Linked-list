#include<iostream>
#include<vector>
using namespace std;

/*
    This approach is top - down approach in DP
    viz recursion and memorization
*/

int nthFabNum(int n, vector<int> dp) {

    //base case
    if(n == 0 || n == 1)
        return n;
    
    //checking if the number is already present in the array
    //to avoid overlapping of calls and to get more optimized solution (in terms of time)
    if(dp[n] != -1) 
        return dp[n];

    //memorizing/storing the answer
    dp[n] = nthFabNum(n-1, dp) + nthFabNum(n-2, dp);
    
    return dp[n];

}

int main() {

    cout<<"Enter the position : ";
    int n;
    cin >> n;

    vector<int> dp(n+1, -1);

    cout << nthFabNum(n-1, dp);

    return 0;
}