// 2017. Grid Game

// You are given a 0-indexed 2D array grid of size 2 x n, where grid[r][c] represents the number of points at position (r, c) on the matrix. Two robots are playing a game on this matrix.

// Both robots initially start at (0, 0) and want to reach (1, n-1). Each robot may only move to the right ((r, c) to (r, c + 1)) or down ((r, c) to (r + 1, c)).

// At the start of the game, the first robot moves from (0, 0) to (1, n-1), collecting all the points from the cells on its path. For all cells (r, c) traversed on the path, grid[r][c] is set to 0. Then, the second robot moves from (0, 0) to (1, n-1), collecting the points on its path. Note that their paths may intersect with one another.

// The first robot wants to minimize the number of points collected by the second robot. In contrast, the second robot wants to maximize the number of points it collects. If both robots play optimally, return the number of points collected by the second robot.

// Example 1:

// Input: grid = [[2,5,4],[1,5,1]]
// Output: 4
// Explanation: The optimal path taken by the first robot is shown in red, and the optimal path taken by the second robot is shown in blue.
// The cells visited by the first robot are set to 0.
// The second robot will collect 0 + 0 + 4 + 0 = 4 points.
// Example 2:

// Input: grid = [[3,3,1],[8,5,2]]
// Output: 4
// Explanation: The optimal path taken by the first robot is shown in red, and the optimal path taken by the second robot is shown in blue.
// The cells visited by the first robot are set to 0.
// The second robot will collect 0 + 3 + 1 + 0 = 4 points.
// Example 3:

// Input: grid = [[1,3,1,15],[1,3,3,1]]
// Output: 7
// Explanation: The optimal path taken by the first robot is shown in red, and the optimal path taken by the second robot is shown in blue.
// The cells visited by the first robot are set to 0.
// The second robot will collect 0 + 1 + 3 + 3 + 0 = 7 points.

// Constraints:

// grid.length == 2
// n == grid[r].length
// 1 <= n <= 5 * 104
// 1 <= grid[r][c] <= 105

class Solution
{
public:
    long long gridGame(vector<vector<int>> &grid)
    {
        long long min_result = LLONG_MAX;                                     // Start with a large number for the minimum score.
        long long row1_sum = accumulate(grid[0].begin(), grid[0].end(), 0LL); // Top row sum
        long long row2_sum = 0;                                               // Bottom row sum starts at 0.

        for (int i = 0; i < grid[0].size(); ++i)
        {
            row1_sum -= grid[0][i];                                // Move the top player forward, subtract current value.
            min_result = min(min_result, max(row1_sum, row2_sum)); // Update the minimum of the max scores.
            row2_sum += grid[1][i];                                // Move the bottom player forward, add current value.
        }

        return min_result; // Return the minimum maximum score.
    }
};

/*
This code solves the Grid Game problem using a greedy approach:
1. Initialize min_result with maximum possible value to track minimum score
2. Calculate initial sum of top row (row1_sum)
3. Initialize bottom row sum (row2_sum) as 0
4. For each column in the grid:
   - Subtract current top cell value from row1_sum (first robot's path)
   - Compare remaining top sum (row1_sum) with accumulated bottom sum (row2_sum)
   - Take maximum of these two as potential second robot's score
   - Update min_result if current maximum is smaller
   - Add current bottom cell value to row2_sum
5. Return min_result as optimal score for second robot
The algorithm minimizes the maximum possible score second robot can achieve
*/