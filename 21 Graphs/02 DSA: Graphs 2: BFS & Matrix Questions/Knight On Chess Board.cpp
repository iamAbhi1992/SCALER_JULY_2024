// Problem Description

// Given any source point, (C, D) and destination point, (E, F) on a chess board of size A x B, we need to find whether Knight can move to the destination or not.


// The above figure details the movements for a knight ( 8 possibilities ).

// If yes, then what would be the minimum number of steps for the knight to move to the said point. If knight can not move from the source point to the destination point, then return -1.

// NOTE: A knight cannot go out of the board.



// Problem Constraints

// 1 <= A, B <= 500



// Input Format

// The first argument of input contains an integer A.
// The second argument of input contains an integer B.
// The third argument of input contains an integer C.
// The fourth argument of input contains an integer D.
// The fifth argument of input contains an integer E.
// The sixth argument of input contains an integer F.



// Output Format

// If it is possible to reach the destination point, return the minimum number of moves.
// Else return -1.



// Example Input

// Input 1:

//  A = 8
//  B = 8
//  C = 1
//  D = 1
//  E = 8
//  F = 8
// Input 2:

//  A = 2
//  B = 4
//  C = 2
//  D = 1
//  E = 4
//  F = 4


// Example Output

// Output 1:

//  6
// Output 2:

//  -1


// Example Explanation

// Explanation 1:

//  The size of the chessboard is 8x8, the knight is initially at (1, 1) and the knight wants to reach position (8, 8).
//  The minimum number of moves required for this is 6.
// Explanation 2:

//  It is not possible to move knight to position (4, 4) from (2, 1)

// https://www.scaler.com/academy/mentee-dashboard/class/297909/homework/problems/292?navref=cl_tt_lst_sl

// https://www.geeksforgeeks.org/minimum-steps-reach-target-knight/

#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct cell {
    int x, y, dist;
};

int knight(int A, int B, int C, int D, int E, int F) {
    vector<int> dx = {-2, -1, -2, -1, 2, 1, 1, 2};
    vector<int> dy = {-1, -2, 1, 2, -1, -2, 2, 1};

    if (C == E && D == F) return 0;

    vector<vector<int>> visited(A + 1, vector<int>(B + 1, INT_MAX));
    visited[C][D] = 0;

    queue<cell> q;
    q.push({C, D, 0});

    while (!q.empty()) {
        cell currcell = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int movex = dx[i] + currcell.x;
            int movey = dy[i] + currcell.y;

            if (movex > 0 && movex <= A && movey > 0 && movey <= B) {
                if (movex == E && movey == F) return currcell.dist + 1;

                if (visited[movex][movey] > currcell.dist + 1) {
                    visited[movex][movey] = currcell.dist + 1;
                    q.push({movex, movey, currcell.dist + 1});
                }
            }
        }
    }
    return -1;
}