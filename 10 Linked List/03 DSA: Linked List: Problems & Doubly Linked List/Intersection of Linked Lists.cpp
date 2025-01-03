// https://www.scaler.com/academy/mentee-dashboard/class/297893/assignment/problems/44?navref=cl_tt_crd_nm

// Problem Description

// Write a program to find the node at which the intersection of two singly linked lists, A and B, begins. For example, the following two linked lists:

// A:          a1 → a2
//                    ↘
//                      c1 → c2 → c3
//                    ↗
// B:     b1 → b2 → b3
// NOTE:

// If the two linked lists have no intersection at all, return null.
// The linked lists must retain their original structure after the function returns.
// You may assume there are no cycles anywhere in the entire linked structure.
// Your code should preferably run in O(n) time and use only O(1) memory.
// The custom input to be given is different than the one explained in the examples. Please be careful.


// Problem Constraints

// 0 <= |A|, |B| <= 106



// Input Format

// The first argument of input contains a pointer to the head of the linked list A.

// The second argument of input contains a pointer to the head of the linked list B.



// Output Format

// Return a pointer to the node after which the linked list is intersecting.



// Example Input

// Input 1:

//  A = [1, 2, 3, 4, 5]
//  B = [6, 3, 4, 5]
// Input 2:

//  A = [1, 2, 3]
//  B = [4, 5]


// Example Output

// Output 1:

//  [3, 4, 5]
// Output 2:

//  []


// Example Explanation

// Explanation 1:

//  In the first example, the nodes have the same values after 3rd node in A and 2nd node in B. Thus, the linked lists are intersecting after that point. 
// Explanation 2:

//  In the second example, the nodes don't have the same values, thus we can return None/Null. 


#include "solution.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int lenofLL(ListNode* head){
    int count=0;
    while(head!=NULL){
        head=head->next;
        count++;
    }
    return count;
}

ListNode* intersection(int d, ListNode* A, ListNode* B){
    ListNode* ptr1=A;
    ListNode* ptr2=B;

    for (int i=0; i<d; i++){
        if (ptr1==NULL) return NULL;
        ptr1=ptr1->next;
    }
    while(ptr1!=NULL && ptr2!=NULL){
        if (ptr1==ptr2) return ptr1;
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return NULL;
}
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int Alen=lenofLL(A);
    int Blen=lenofLL(B);

    if (Alen>Blen) {
        int difference=Alen-Blen;
        return intersection(difference, A, B);
    }
    else {
        int difference=Blen-Alen;
        return intersection(difference, B, A);
    }
}
