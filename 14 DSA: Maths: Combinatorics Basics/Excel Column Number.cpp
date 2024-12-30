// https://www.scaler.com/academy/mentee-dashboard/class/297881/homework/problems/74?navref=cl_tt_lst_nm

// Problem Description

// Given a column title as appears in an Excel sheet, return its corresponding column number.



// Problem Constraints

// 1 <= length of the column title <= 5



// Input Format

// The only argument is a string that represents the column title in the excel sheet.



// Output Format

// Return a single integer that represents the corresponding column number.



// Example Input

// Input 1:

//  AB
// Input 2:

//  BB


// Example Output

// Output 1:

//  28
// Output 2:

//  54


// Example Explanation

// Explanation 1:

//  A -> 1
//  B -> 2
//  C -> 3
//  ...
//  Z -> 26
//  AA -> 27
//  AB -> 28
// Explanation 2:

//  A -> 1
//  B -> 2
//  C -> 3
//  ...
//  Z -> 26
//  AA -> 27
//  AB -> 28
//  ...
//  AZ -> 52
//  BA -> 53
//  BB -> 54

int Solution::titleToNumber(string A) {
    int ans=0;
    int pow=1;
    while(A.length()!=0){
        char last_ele = A.back();  // Get the last character
        
        int last_char_value = last_ele - 'A' + 1;

        ans+=last_char_value*pow;

        pow*=26;
        A.pop_back();
    }

    return ans;

}
