// https://www.scaler.com/academy/mentee-dashboard/class/236130/homework/problems/4679?navref=cl_tt_nv

// Problem Description

// Given a binary search tree of integers. You are given a range B and C.

// Return the count of the number of nodes that lie in the given range.



// Problem Constraints

// 1 <= Number of nodes in binary tree <= 100000

// 0 <= B < = C <= 109



// Input Format

// First argument is a root node of the binary tree, A.

// Second argument is an integer B.

// Third argument is an integer C.



// Output Format

// Return the count of the number of nodes that lies in the given range.



// Example Input

// Input 1:

//             15
//           /    \
//         12      20
//         / \    /  \
//        10  14  16  27
//       /
//      8

//      B = 12
//      C = 20
// Input 2:

//             8
//            / \
//           6  21
//          / \
//         1   7

//      B = 2
//      C = 20


// Example Output

// Output 1:

//  5
// Output 2:

//  3


// Example Explanation

// Explanation 1:

//  Nodes which are in range [12, 20] are : [12, 14, 15, 20, 16]
// Explanation 2:

//  Nodes which are in range [2, 20] are : [8, 6, 7]

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void countrange(TreeNode* head, int B, int C, int &count){
    if (head==NULL){
        return;
    }

    if (head->val > B ) {
        countrange(head->left, B, C, count);
    }

    if (head->val >= B && head->val <=C) {
        count++;
    }

    if (head->val < C){
        countrange(head->right, B, C, count);
    }
}

int Solution::solve(TreeNode* A, int B, int C) {
    int count=0;
    countrange(A, B, C, count);
    return count;
}
