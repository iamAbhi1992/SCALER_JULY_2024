// https://www.scaler.com/academy/mentee-dashboard/class/297865/homework/problems/273?navref=cl_tt_nv

// Problem Description

// Given a binary array A, find the maximum sequence of continuous 1's that can be formed by replacing at-most B zeroes.

// For this problem, return the indices of maximum continuous series of 1s in order.

// If there are multiple possible solutions, return the sequence which has the minimum start index.



// Problem Constraints

// 0 <= B <= 105

// 1 <= size(A) <= 105

// 0 <= A[i] <= 1



// Input Format

// First argument is an binary array A.

// Second argument is an integer B.



// Output Format

// Return an array of integers denoting the indices(0-based) of 1's in the maximum continuous series.



// Example Input

// Input 1:

//  A = [1, 1, 0, 1, 1, 0, 0, 1, 1, 1]
//  B = 1
// Input 2:

//  A = [1, 0, 0, 0, 1, 0, 1]
//  B = 2






// Example Output

// Output 1:

//  [0, 1, 2, 3, 4]
// Output 2:

//  [3, 4, 5, 6]


// Example Explanation

// Explanation 1:

//  Flipping 0 present at index 2 gives us the longest continous series of 1's i.e subarray [0:4].
// Explanation 2:

//  Flipping 0 present at index 3 and index 5 gives us the longest continous series of 1's i.e subarray [3:6].

vector<int> Solution::maxone(vector<int> &A, int B) {
    int n = A.size();
    int i = 0, j = 0;
    int count_zeros = 0;
    
    int max_len = 0;
    int start = 0;

    while (j < n) {
        if (A[j] == 0) {
            count_zeros++;
        }

        while (count_zeros > B) {
            if (A[i] == 0) {
                count_zeros--;
            }
            i++;
        }

        if (j - i + 1 > max_len) {
            max_len = j - i + 1;
            start = i;
        }
        
        j++;
    }

    vector<int> result;
    for (int k = start; k < start + max_len; k++) {
        result.push_back(k);
    }

    return result;
}
