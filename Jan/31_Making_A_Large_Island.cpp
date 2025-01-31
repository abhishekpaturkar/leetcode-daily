// 827. Making A Large Island
// Solved
// Hard
// Topics
// Companies
// You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

// Return the size of the largest island in grid after applying this operation.

// An island is a 4-directionally connected group of 1s.

// Example 1:

// Input: grid = [[1,0],[0,1]]
// Output: 3
// Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
// Example 2:

// Input: grid = [[1,1],[1,0]]
// Output: 4
// Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
// Example 3:

// Input: grid = [[1,1],[1,1]]
// Output: 4
// Explanation: Can't change any 0 to 1, only one island with area = 4.

// Constraints:

// n == grid.length
// n == grid[i].length
// 1 <= n <= 500
// grid[i][j] is either 0 or 1.

class Solution
{
private:
    int exploreIsland(vector<vector<int>> &grid, int islandId, int currentRow,
                      int currentColumn)
    {
        if (currentRow < 0 || currentRow >= grid.size() || currentColumn < 0 ||
            currentColumn >= grid[0].size() ||
            grid[currentRow][currentColumn] != 1)
            return 0;

        grid[currentRow][currentColumn] = islandId;
        return 1 +
               exploreIsland(grid, islandId, currentRow + 1, currentColumn) +
               exploreIsland(grid, islandId, currentRow - 1, currentColumn) +
               exploreIsland(grid, islandId, currentRow, currentColumn + 1) +
               exploreIsland(grid, islandId, currentRow, currentColumn - 1);
    }

public:
    int largestIsland(vector<vector<int>> &grid)
    {
        unordered_map<int, int> islandSizes;
        int islandId = 2;

        // Step 1: Mark all islands and calculate their sizes
        for (int currentRow = 0; currentRow < grid.size(); ++currentRow)
        {
            for (int currentColumn = 0; currentColumn < grid[0].size();
                 ++currentColumn)
            {
                if (grid[currentRow][currentColumn] == 1)
                {
                    islandSizes[islandId] = exploreIsland(
                        grid, islandId, currentRow, currentColumn);
                    ++islandId;
                }
            }
        }

        // If there are no islands, return 1
        if (islandSizes.empty())
        {
            return 1;
        }
        // If the entire grid is one island, return its size or size + 1
        if (islandSizes.size() == 1)
        {
            --islandId;
            return (islandSizes[islandId] == grid.size() * grid[0].size())
                       ? islandSizes[islandId]
                       : islandSizes[islandId] + 1;
        }

        int maxIslandSize = 1;

        // Step 2: Try converting every 0 to 1 and calculate the resulting
        // island size
        for (int currentRow = 0; currentRow < grid.size(); ++currentRow)
        {
            for (int currentColumn = 0; currentColumn < grid[0].size();
                 ++currentColumn)
            {
                if (grid[currentRow][currentColumn] == 0)
                {
                    int currentIslandSize = 1;
                    unordered_set<int> neighboringIslands;

                    // Check down
                    if (currentRow + 1 < grid.size() &&
                        grid[currentRow + 1][currentColumn] > 1)
                    {
                        neighboringIslands.insert(
                            grid[currentRow + 1][currentColumn]);
                    }

                    // Check up
                    if (currentRow - 1 >= 0 &&
                        grid[currentRow - 1][currentColumn] > 1)
                    {
                        neighboringIslands.insert(
                            grid[currentRow - 1][currentColumn]);
                    }

                    // Check right
                    if (currentColumn + 1 < grid[0].size() &&
                        grid[currentRow][currentColumn + 1] > 1)
                    {
                        neighboringIslands.insert(
                            grid[currentRow][currentColumn + 1]);
                    }

                    // Check left
                    if (currentColumn - 1 >= 0 &&
                        grid[currentRow][currentColumn - 1] > 1)
                    {
                        neighboringIslands.insert(
                            grid[currentRow][currentColumn - 1]);
                    }

                    // Sum the sizes of all unique neighboring islands
                    for (int id : neighboringIslands)
                    {
                        currentIslandSize += islandSizes[id];
                    }

                    maxIslandSize = max(maxIslandSize, currentIslandSize);
                }
            }
        }

        return maxIslandSize;
    }
};

/*
This code solves the problem of finding the largest possible island in a binary matrix after changing at most one 0 to 1. Here's how it works:

1. The exploreIsland function uses DFS to explore and mark connected 1s as part of the same island. It:
   - Takes parameters: grid, islandId (unique identifier for each island), and current position
   - Returns the size of the explored island
   - Marks visited cells with the islandId instead of 1

2. The largestIsland function:
   a) First pass (Step 1):
      - Identifies all existing islands
      - Assigns unique IDs (starting from 2) to each island
      - Stores island sizes in islandSizes map
   
   b) Special cases:
      - If no islands exist, returns 1
      - If one island covers entire grid, returns its size
      - If one island with empty cells exists, returns size + 1

   c) Second pass (Step 2):
      - Examines each 0 cell
      - Checks all 4 directions for neighboring islands
      - Calculates potential island size by combining neighboring islands
      - Keeps track of maximum possible island size

3. Key data structures:
   - islandSizes: Maps island IDs to their sizes
   - neighboringIslands: Tracks unique neighboring islands for each 0 cell

4. Time Complexity: O(N²) where N is the grid dimension
   Space Complexity: O(N²) for storing island information
*/