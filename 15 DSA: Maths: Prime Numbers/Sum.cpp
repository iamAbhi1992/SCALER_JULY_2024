// https://www.scaler.com/academy/mentee-dashboard/class/297921/homework/problems/165?navref=cl_tt_nv

// Problem Description

// Given an array A of N integers, find three integers in A such that the sum is closest to a given number B. Return the sum of those three integers.

// Assume that there will only be one solution.



// Problem Constraints

// -108 <= B <= 108
// 1 <= N <= 104
// -108 <= A[i] <= 108


// Input Format

// First argument is an integer array A of size N.

// Second argument is an integer B denoting the sum you need to get close to.



// Output Format

// Return a single integer denoting the sum of three integers which is closest to B.



// Example Input

// Input 1:

// A = [-1, 2, 1, -4]
// B = 1
// Input 2:

 
// A = [1, 2, 3]
// B = 6


// Example Output

// Output 1:

// 2
// Output 2:

// 6


// Example Explanation

// Explanation 1:

//  The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)
// Explanation 2:

//  Take all elements to get exactly 6.

int Solution::threeSumClosest(vector<int> &A, int B) {
    sort(A.begin(), A.end());

    int closest_sum = A[0] + A[1] + A[2];
    int n = A.size();

    for (int i = 0; i < n - 2; i++) {
        int b = i + 1, c = n - 1;

        while (b < c) {
            int current_sum = A[i] + A[b] + A[c];

            if (abs(current_sum - B) < abs(closest_sum - B)) {
                closest_sum = current_sum;
            }

            if (current_sum > B) c--;
            
            else if (current_sum < B) b++;

            else return current_sum;

        }
    }

    return closest_sum;
}
