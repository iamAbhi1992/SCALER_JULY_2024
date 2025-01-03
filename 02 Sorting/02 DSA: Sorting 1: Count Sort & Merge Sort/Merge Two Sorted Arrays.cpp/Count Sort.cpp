// https://www.scaler.com/academy/mentee-dashboard/class/236086/homework/problems/21391?navref=cl_tt_nv

// Problem Description

// Given an array A. Sort this array using Count Sort Algorithm and return the sorted array.


// Problem Constraints

// 1 <= |A| <= 105
// 1 <= A[i] <= 105


// Input Format

// The first argument is an integer array A.


// Output Format

// Return an integer array that is the sorted array A.


// Example Input

// Input 1:
// A = [1, 3, 1]
// Input 2:
// A = [4, 2, 1, 3]


// Example Output

// Output 1:
// [1, 1, 3]
// Output 2:
// [1, 2, 3, 4]


// Example Explanation

// For Input 1:
// The array in sorted order is [1, 1, 3].
// For Input 2:
// The array in sorted order is [1, 2, 3, 4].

vector<int> Solution::solve(vector<int> &A) {
    int max_val = *max_element(A.begin(), A.end());
    int min_val = *min_element(A.begin(), A.end());

    int range = max_val - min_val + 1;
    vector<int> count(range, 0);

    // Count the frequency of each element in A
    for (int i = 0; i < A.size(); i++) {
        count[A[i] - min_val]++;
    }

    // Reconstruct the sorted array
    int k = 0;
    for (int i = 0; i < range; i++) {
        while (count[i] > 0) {
            A[k++] = i + min_val;
            count[i]--;
        }
    }

    return A;
}
