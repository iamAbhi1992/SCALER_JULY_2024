// https://www.scaler.com/academy/mentee-dashboard/class/297865/assignment/problems/4116?navref=cl_tt_nv

// Problem Description

// Given an array of positive integers A and an integer B, find and return first continuous subarray which adds to B.






// If the answer does not exist return an array with a single integer "-1".

// First sub-array means the sub-array for which starting index in minimum.








// Problem Constraints

// 1 <= length of the array <= 100000
// 1 <= A[i] <= 109
// 1 <= B <= 109



// Input Format

// The first argument given is the integer array A.

// The second argument given is integer B.



// Output Format

// Return the first continuous sub-array which adds to B and if the answer does not exist return an array with a single integer "-1".



// Example Input

// Input 1:

//  A = [1, 2, 3, 4, 5]
//  B = 5
// Input 2:

//  A = [5, 10, 20, 100, 105]
//  B = 110


// Example Output

// Output 1:





//  [2, 3]
// Output 2:

//  [-1]






// Example Explanation

// Explanation 1:

//  [2, 3] sums up to 5.
// Explanation 2:

//  No subarray sums up to required number.


vector<int> Solution::solve(vector<int>& A, int B) {
    int n = A.size();
    int left = 0, right = 0;
    int current_sum = 0;

    while (right < n) {
        current_sum += A[right];

        while (current_sum > B && left < right) {
            current_sum -= A[left];
            left++;
        }

        if (current_sum == B) {
            return vector<int>(A.begin() + left, A.begin() + right + 1);
        }

        right++;
    }

    return {-1};
}
