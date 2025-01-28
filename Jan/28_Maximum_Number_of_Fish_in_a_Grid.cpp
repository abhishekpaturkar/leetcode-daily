// 2658. Maximum Number of Fish in a Grid

// You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents:

// A land cell if grid[r][c] = 0, or
// A water cell containing grid[r][c] fish, if grid[r][c] > 0.
// A fisher can start at any water cell (r, c) and can do the following operations any number of times:

// Catch all the fish at cell (r, c), or
// Move to any adjacent water cell.
// Return the maximum number of fish the fisher can catch if he chooses his starting cell optimally, or 0 if no water cell exists.

// An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) or (r - 1, c) if it exists.

// Example 1:

// Input: grid = [[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]
// Output: 7
// Explanation: The fisher can start at cell (1,3) and collect 3 fish, then move to cell (2,3) and collect 4 fish.
// Example 2:

// Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,1]]
// Output: 1
// Explanation: The fisher can start at cells (0,0) or (3,3) and collect a single fish.

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 10
// 0 <= grid[i][j] <= 10

class Solution
{
public:
    int m, n, dir[5] = {-1, 0, 1, 0, -1};

    int dfs(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || !grid[i][j])
            return 0;
        int sum = grid[i][j];
        grid[i][j] = 0;
        for (int k = 0; k < 4; k++)
            sum += dfs(grid, i + dir[k], j + dir[k + 1]);
        return sum;
    }

    int findMaxFish(vector<vector<int>> &grid)
    {
        m = grid.size(), n = grid[0].size();
        int maxFish = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j])
                    maxFish = max(maxFish, dfs(grid, i, j));
        return maxFish;
    }
};

/*
This solution solves the Maximum Number of Fish in a Grid problem using DFS (Depth First Search).

The class contains:
1. Member variables:
   - m, n: dimensions of the grid
   - dir[5]: array to help navigate in 4 directions (up, right, down, left)

2. dfs() method:
   - Takes grid and current position (i,j) as parameters
   - Checks boundary conditions and if cell has fish
   - Collects fish from current cell and marks it as visited (sets to 0)
   - Recursively explores all 4 adjacent cells
   - Returns total fish collected from current cell and its connected water cells

3. findMaxFish() method:
   - Initializes grid dimensions
   - Iterates through each cell in grid
   - For each cell with fish, starts DFS to find connected water cells
   - Keeps track of maximum fish that can be collected
   - Returns the maximum possible fish collection

The solution uses DFS to explore connected water cells and sum up all fish that can be collected from each starting position, returning the maximum possible sum.
*/