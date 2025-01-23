// 1267. Count Servers that Communicate
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.

// Return the number of servers that communicate with any other server.

// Example 1:

// Input: grid = [[1,0],[0,1]]
// Output: 0
// Explanation: No servers can communicate with others.
// Example 2:

// Input: grid = [[1,0],[1,1]]
// Output: 3
// Explanation: All three servers can communicate with at least one other server.
// Example 3:

// Input: grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
// Output: 4
// Explanation: The two servers in the first row can communicate with each other. The two servers in the third column can communicate with each other. The server at right bottom corner can't communicate with any other server.

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m <= 250
// 1 <= n <= 250
// grid[i][j] == 0 or 1

class Solution
{
public:
    int countServers(vector<vector<int>> &grid)
    {
        vector<int> Rows(grid.size());
        vector<int> Col(grid[0].size());

        // Calculate row and column sums
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                Rows[i] += grid[i][j];
                Col[j] += grid[i][j];
            }
        }

        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1 && (Rows[i] > 1 || Col[j] > 1))
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};

/*
This code solves the problem of counting servers that can communicate with at least one other server in a grid. Here's how it works:

1. Two vectors Rows and Col are created to store the count of servers in each row and column respectively.

2. First loop:
   - Iterates through the grid and counts servers in each row and column
   - Rows[i] stores total servers in row i
   - Col[j] stores total servers in column j

3. Second loop:
   - Checks each cell in the grid
   - If a cell has a server (grid[i][j] == 1) and either:
     a) Its row has more than one server (Rows[i] > 1) or
     b) Its column has more than one server (Col[j] > 1)
   - Then this server can communicate with at least one other server
   - Increments the answer counter

4. Returns the total count of servers that can communicate
*/