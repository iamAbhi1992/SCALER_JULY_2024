// https://www.scaler.com/academy/mentee-dashboard/class/297881/assignment/problems/4111?navref=cl_tt_nv

// Problem Description

// Given three integers A, B, and C, where A represents n, B represents r, and C represents m, find and return the value of nCr % m where nCr % m = (n!/((n-r)!*r!))% m.




// x! means factorial of x i.e. x! = 1 * 2 * 3... * x.






// Problem Constraints

// 1 <= A * B <= 106

// 1 <= B <= A

// 1 <= C <= 106



// Input Format

// The first argument given is integer A ( = n).
// The second argument given is integer B ( = r).
// The third argument given is integer C ( = m).



// Output Format

// Return the value of nCr % m.



// Example Input

// Input 1:

//  A = 5
//  B = 2
//  C = 13
// Input 2:

//  A = 6
//  B = 2
//  C = 13


// Example Output

// Output 1:

//  10
// Output 2:

//  2


// Example Explanation

// Explanation 1:

//  The value of 5C2 % 11 is 10.
// Explanation 2:

//  The value of 6C2 % 13 is 2.

int Solution::solve(int A, int B, int C) {
    vector<vector<int> > ans(A+1, vector<int>(B+1, 0));

    for (int i = 0; i <= A; i++) {
        for (int j = 0; j <= min(i, B); j++) {
            if (j == 0 || j == i) {
                ans[i][j] = 1;
            } else {
                ans[i][j] = (ans[i-1][j-1] % C + ans[i-1][j] % C) % C;
            }
        }
    }

    return ans[A][B] % C;
}
