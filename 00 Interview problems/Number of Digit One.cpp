// https://www.scaler.com/academy/mentee-dashboard/class/236112/homework/problems/4099?navref=cl_tt_nv

// Problem Description

// Given an integer A, find and return the total number of digit 1 appearing in all non-negative integers less than or equal to A.



// Problem Constraints

// 0 <= A <= 109



// Input Format

// The only argument given is the integer A.



// Output Format

// Return the total number of digit 1 appearing in all non-negative integers less than or equal to A.



// Example Input

// Input 1:

//  A = 10
// Input 2:

//  A = 11


// Example Output

// Output 1:

//  2
// Output 2:

//  4


// Example Explanation

// Explanation 1:

// Digit 1 appears in 1 and 10 only and appears one time in each. So the answer is 2.
// Explanation 2:

// Digit 1 appears in 1(1 time) , 10(1 time) and 11(2 times) only. So the answer is 4.

int Solution::solve(int A) {
    if (A <= 0) return 0;
    
    int count = 0;
    for (long long i = 1; i <= A; i *= 10) {
        long long divider = i * 10;
        count += (A / divider) * i + min(max(A % divider - i + 1, 0LL), i);
    }
    
    return count;

}
