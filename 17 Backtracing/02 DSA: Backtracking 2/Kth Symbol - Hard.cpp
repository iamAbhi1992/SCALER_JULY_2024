// https://www.scaler.com/academy/mentee-dashboard/class/297913/homework/problems/31788?navref=cl_tt_lst_nm

// Problem Description

// On the first row, we write a 0. Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.

// Given row number A and index B, return the Bth indexed symbol in row A. (The values of B are 0-indexed.).



// Problem Constraints

// 1 <= A <= 105

// 0 <= B <= min(2A - 1 - 1 , 1018)



// Input Format

// First argument is an integer A.

// Second argument is an integer B.



// Output Format

// Return an integer denoting the Bth indexed symbol in row A.



// Example Input

// Input 1:

//  A = 3
//  B = 0
// Input 2:

//  A = 4
//  B = 4


// Example Output

// Output 1:

//  0
// Output 2:

//  1


// Example Explanation

// Explanation 1:

//  Row 1: 0
//  Row 2: 01
//  Row 3: 0110
// Explanation 2:

//  Row 1: 0
//  Row 2: 01
//  Row 3: 0110
//  Row 4: 01101001

int findsymbol(int n, long k){
 	if(k==0){
		return 0;
 	}
	int val = findsymbol(n- 1 , k / 2);
	if(k % 2 == 0){
		return val;
	}
	return 1 - val;
}
int Solution::solve(int A, long B) {
	return findsymbol(A, B);
}