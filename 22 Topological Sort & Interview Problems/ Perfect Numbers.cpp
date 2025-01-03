// https://www.scaler.com/academy/mentee-dashboard/class/297857/homework/problems/3297?navref=cl_tt_lst_sl

// Problem Description

// Given an integer A, you have to find the Ath Perfect Number.

// A Perfect Number has the following properties:

// It comprises only 1 and 2.
// The number of digits in a Perfect number is even.
// It is a palindrome number.
// For example, 11, 22, 112211 are Perfect numbers, where 123, 121, 782, 1 are not.





// Problem Constraints

// 1 <= A <= 100000



// Input Format

// The only argument given is an integer A.



// Output Format

// Return a string that denotes the Ath Perfect Number.



// Example Input

// Input 1:

//  A = 2
// Input 2:

//  A = 3


// Example Output

// Output 1:

//  22
// Output 2:

//  1111


// Example Explanation

// Explanation 1:

// First four perfect numbers are:
// 1. 11
// 2. 22
// 3. 1111
// 4. 1221
// Return the 2nd Perfect number.
// Explanation 2:

// First four perfect numbers are:
// 1. 11
// 2. 22
// 3. 1111
// 4. 1221
// Return the 3rd Perfect number.

#include <queue>
#include <algorithm>
#include <string>
using namespace std;

string solve(int A) {
    queue<string> q;
    q.push("1");
    q.push("2");

    int count = 0;
    while (!q.empty()) {
        string num = q.front();
        q.pop();

        string reverse_num = num;
        reverse(reverse_num.begin(), reverse_num.end());
        string perfect_number = num + reverse_num;

        count++;
        if (count == A) return perfect_number;

        q.push(num + "1");
        q.push(num + "2");
    }

    return "";
}
