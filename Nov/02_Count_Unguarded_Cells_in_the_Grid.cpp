// 2257. Count Unguarded Cells in the Grid

// You are given two integers m and n representing a 0-indexed m x n grid. You are also given two 2D integer arrays guards and walls where guards[i] = [rowi, coli] and walls[j] = [rowj, colj] represent the positions of the ith guard and jth wall respectively.

// A guard can see every cell in the four cardinal directions (north, east, south, or west) starting from their position unless obstructed by a wall or another guard. A cell is guarded if there is at least one guard that can see it.

// Return the number of unoccupied cells that are not guarded.

 

// Example 1:


// Input: m = 4, n = 6, guards = [[0,0],[1,1],[2,3]], walls = [[0,1],[2,2],[1,4]]
// Output: 7
// Explanation: The guarded and unguarded cells are shown in red and green respectively in the above diagram.
// There are a total of 7 unguarded cells, so we return 7.
// Example 2:


// Input: m = 3, n = 3, guards = [[1,1]], walls = [[0,1],[1,0],[2,1],[1,2]]
// Output: 4
// Explanation: The unguarded cells are shown in green in the above diagram.
// There are a total of 4 unguarded cells, so we return 4.
 

// Constraints:

// 1 <= m, n <= 105
// 2 <= m * n <= 105
// 1 <= guards.length, walls.length <= 5 * 104
// 2 <= guards.length + walls.length <= m * n
// guards[i].length == walls[j].length == 2
// 0 <= rowi, rowj < m
// 0 <= coli, colj < n
// All the positions in guards and walls are unique.

class Solution
{
public:
    vector<int> dir = {-1, 0, 1, 0, -1};

    void dfs(int x, int y, int d, vector<vector<int>> &grid)
    {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 2 || grid[x][y] == 3)
        {
            return;
        }

        grid[x][y] = 1;
        if (d == 0)
            dfs(x - 1, y, d, grid);
        else if (d == 1)
            dfs(x, y + 1, d, grid);
        else if (d == 2)
            dfs(x + 1, y, d, grid);
        else if (d == 3)
            dfs(x, y - 1, d, grid);
    }

    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
    {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for (auto &g : guards)
        {
            grid[g[0]][g[1]] = 2;
        }

        for (auto &w : walls)
        {
            grid[w[0]][w[1]] = 3;
        }

        for (auto &g : guards)
        {
            for (int i = 0; i < 4; i++)
            {
                int x = g[0] + dir[i];
                int y = g[1] + dir[i + 1];
                dfs(x, y, i, grid);
            }
        }

        int ans = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};