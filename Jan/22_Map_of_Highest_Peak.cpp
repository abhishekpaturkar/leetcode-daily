// 1765. Map of Highest Peak

// You are given an integer matrix isWater of size m x n that represents a map of land and water cells.

// If isWater[i][j] == 0, cell (i, j) is a land cell.
// If isWater[i][j] == 1, cell (i, j) is a water cell.
// You must assign each cell a height in a way that follows these rules:

// The height of each cell must be non-negative.
// If the cell is a water cell, its height must be 0.
// Any two adjacent cells must have an absolute height difference of at most 1. A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).
// Find an assignment of heights such that the maximum height in the matrix is maximized.

// Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. If there are multiple solutions, return any of them.

// Example 1:

// Input: isWater = [[0,1],[0,0]]
// Output: [[1,0],[2,1]]
// Explanation: The image shows the assigned heights of each cell.
// The blue cell is the water cell, and the green cells are the land cells.
// Example 2:

// Input: isWater = [[0,0,1],[1,0,0],[0,0,0]]
// Output: [[1,1,0],[0,1,1],[1,2,2]]
// Explanation: A height of 2 is the maximum possible height of any assignment.
// Any height assignment that has a maximum height of 2 while still meeting the rules will also be accepted.

// Constraints:

// m == isWater.length
// n == isWater[i].length
// 1 <= m, n <= 1000
// isWater[i][j] is 0 or 1.
// There is at least one water cell.

class Solution
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        int R = isWater.size();
        int C = isWater[0].size();
        vector<vector<int>> height(R, vector<int>(C, R + C)); // Initialize with a safe sentinel value

        // First pass: set water cells to 0 and propagate height from top-left to bottom-right
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (isWater[i][j] == 1)
                {
                    height[i][j] = 0; // Water cell has height 0
                }
                else
                {
                    if (i > 0)
                        height[i][j] = min(height[i][j], height[i - 1][j] + 1); // Check from top
                    if (j > 0)
                        height[i][j] = min(height[i][j], height[i][j - 1] + 1); // Check from left
                }
            }
        }

        // Second pass: propagate height from bottom-right to top-left
        for (int i = R - 1; i >= 0; i--)
        {
            for (int j = C - 1; j >= 0; j--)
            {
                if (i < R - 1)
                    height[i][j] = min(height[i][j], height[i + 1][j] + 1); // Check from bottom
                if (j < C - 1)
                    height[i][j] = min(height[i][j], height[i][j + 1] + 1); // Check from right
            }
        }

        return height;
    }
};

/*
This code solves the problem of assigning heights to cells in a grid where water cells must have height 0 and adjacent cells can differ by at most 1 in height. Here's how it works:

1. First, it creates a height matrix initialized with a large value (R + C).

2. The solution uses two passes through the grid:
   - First pass (top-left to bottom-right):
     * Sets water cells to height 0
     * For land cells, checks cells above and to the left to maintain height difference of 1
   
   - Second pass (bottom-right to top-left):
     * Checks cells below and to the right to maintain height difference of 1
     * Updates heights if a smaller valid height is found

3. The two-pass approach ensures that heights propagate from water cells in all directions and maintains the minimum possible height difference between adjacent cells.

4. The final result is a valid height assignment that maximizes the overall height while following all the given constraints.
*/