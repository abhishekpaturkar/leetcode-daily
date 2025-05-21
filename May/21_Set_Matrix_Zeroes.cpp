// 73. Set Matrix Zeroes

// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// You must do it in place.


// Example 1:


// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]
// Example 2:


// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

// Constraints:

// m == matrix.length
// n == matrix[0].length
// 1 <= m, n <= 200
// -231 <= matrix[i][j] <= 231 - 1
 

// Follow up:

// A straightforward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        bool rowZero = false;

        // Determine which rows/cols need to be zero

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    if (i > 0)
                    {
                        matrix[i][0] = 0;
                    }
                    else
                    {
                        rowZero = true;
                    }
                }
            }
        }

        // Zero the rows and cols

        // 0ing rows and cols except first
        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // 0ing first col
        if (matrix[0][0] == 0)
        {
            for (int i = 0; i < rows; i++)
            {
                matrix[i][0] = 0;
            }
        }

        // 0ing first rows
        if (rowZero == true)
        {
            for (int j = 0; j < cols; j++)
            {
                matrix[0][j] = 0;
            }
        }
    }
};

/*
This solution uses constant extra space O(1) to solve the problem. The approach is to use the first row and first column of the matrix as markers.

Algorithm:
1. Use first row/col as markers to track which rows/cols need to be zeroed
2. Use separate boolean for first row since it's used as marker
3. First pass: mark first row/col if zero found
4. Second pass: zero non-first rows/cols based on markers
5. Finally zero first row/col if needed

Time Complexity: O(M * N) where M and N are dimensions of matrix
Space Complexity: O(1) as we use the matrix itself for marking
*/