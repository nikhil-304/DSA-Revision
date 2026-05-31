class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
    
        // Step 1: Transpose the matrix (swap mat[i][j] with mat[j][i])
        // Convert Columns into Rows

        /*
        TRANSPOSE THE MATRIX
        We swap only the elements ABOVE the main diagonal. (upper-triangle elements)      
        Example (3x3):
              0   1   2
           +---+---+---+
         0 | D | ? | ? |
           +---+---+---+
         1 | x | D | ? |
           +---+---+---+
         2 | x | x | D |
           +---+---+---+
        
        D = Diagonal elements (don't move)
        ? = Elements to swap
        x = Already handled by previous swaps
        
        Why not touch the diagonal?
        Because matrix[i][i] swapped with itself changes nothing.
        
        Why start j from i+1?
        To visit only the upper-right triangle.
        If we swapped both triangles, we'd undo our own work.
        Example: swap((0,1), (1,0))
        Later if we visited lower triangle: swap((1,0), (0,1))
        This would reverse the previous swap.
        */
        for (int i = 0; i < n-1; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row to get the final 90-degree rotated matrix
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

//Problem Link: https://leetcode.com/problems/rotate-image/

/*
90° CLOCKWISE
Columns -> Rows -> Reverse

Transpose + Reverse Every Row => Rotate Clockwise

"Transpose fixes position,
Reverse fixes direction."
*/

/*
Time Complexity: O(n^2)
Space Complexity: O(1)
*/

/*
Original          Rotated

1 2 3              7 4 1
4 5 6      =>      8 5 2
7 8 9              9 6 3

******* Observe Rows and Columns ********

Original first column:
1
4
7

Rotated first row:
7 4 1
That's the same column, but reversed.

Original second column:
2
5
8

becomes
8 5 2

Again: Column becomes -> Row


******** Big Observation ********
A clockwise rotation means:
1. Columns become rows
and
2. their order gets reversed


******** How do we convert Columns into Rows? ********

That's exactly what transpose does.
Original:
1 2 3
4 5 6
7 8 9

After transpose:
1 4 7
2 5 8
3 6 9

Notice:
Column 1 became Row 1
Column 2 became Row 2
Column 3 became Row 3

Transpose achieves:
Columns -> Rows
but not reversed yet.

******** What's Missing? ********

Desired result:
7 4 1
8 5 2
9 6 3

Current result after transpose:
1 4 7
2 5 8
3 6 9

Each row is backwards.
Fix It
Reverse every row.

1 4 7  ->  7 4 1
2 5 8  ->  8 5 2
3 6 9  ->  9 6 3

90° Clockwise Rotation
          ?
Columns should become Rows
          ?
Transpose
          ?
Rows need reversing
          ?
Reverse each row
*/

/*
For a 3×3 matrix, the indices look like this:

        j
        0      1      2
      +------+------+------+
i = 0 |(0,0) |(0,1) |(0,2) |
      +------+------+------+
i = 1 |(1,0) |(1,1) |(1,2) |
      +------+------+------+
i = 2 |(2,0) |(2,1) |(2,2) |
      +------+------+------+
Which cells do we actually need to visit?

For transpose, we only need the upper triangle (above the diagonal):
        j
        0      1      2
      +------+------+------+
i = 0 |  D   |  ?   |  ?   |
      +------+------+------+
i = 1 |  x   |  D   |  ?   |
      +------+------+------+
i = 2 |  x   |  x   |  D   |
      +------+------+------+

Where:
D = Diagonal (don't touch)
? = Need to swap
x = Skip

So the only indices we visit are:
(0,1)
(0,2)
(1,2)
Why exactly these?

Look at the indices:

(0,1) -> 0 < 1
(0,2) -> 0 < 2
(1,2) -> 1 < 2

Notice:

First Index < Second Index

or

i < j

This is the mathematical condition for being above the main diagonal.

What gets swapped?

Each selected cell is swapped with its mirror across the diagonal:

(0,1) <-> (1,0)
(0,2) <-> (2,0)
(1,2) <-> (2,1)

How does this become j = i + 1?

We need:
i < j

For each row:

Row 0
Need: (0,1), (0,2)
So: j = 1
which is: j = i + 1
because i = 0.

Row 1
Need: (1,2)
So: j = 2
which is: j = i + 1
because i = 1.

Row 2
Need: None
because there is no column greater than 2.
*/

//Revision Done on: 31/05/2026
