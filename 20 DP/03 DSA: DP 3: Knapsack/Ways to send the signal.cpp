// https://www.scaler.com/academy/mentee-dashboard/class/297905/homework/problems/4806?navref=cl_tt_lst_sl

// Problem Description

// You are trying to send signals to aliens using a linear array of A laser lights. You don't know much about how the aliens are going to percieve the signals, but what you know is that if two consecutive lights are on then the aliens might take it as a sign of danger and destroy the earth.

// Find and return the total number of ways in which you can send a signal without compromising the safty of the earth. Return the ans % 109 + 7.



// Problem Constraints

// 1 <= A <= 105



// Input Format

// The only argument given is integer A.



// Output Format

// Return the ans%(109+7).



// Example Input

// Input 1:

//  A = 2
// Input 2:

//  A = 3


// Example Output

// Output 1:

//  3
// Output 2:

//  5


// Example Explanation

// Explanation 1:

//  OFF OFF
//  OFF ON 
//  ON OFF
// All lights off is also a valid signal which probably means 'bye'

// Explanation 2:

//  OFF OFF OFF
//  OFF OFF ON
//  OFF ON OFF 
//  ON OFF OFF
//  ON OFF ON


#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solve(int A) {
    int mod = 1e9+7;
    vector<int> dp(A+1, 0);
    if (A==1) return 2;
    if (A==2) return 3;

    dp[1]=2;
    dp[2]=3;
    for (int i = 3; i<=A; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % mod;
    }

    return dp[A];
}
