// 2033. Minimum Operations to Make a Uni-Value Grid

// You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.

// A uni-value grid is a grid where all the elements of it are equal.

// Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.


// Example 1:


// Input: grid = [[2,4],[6,8]], x = 2
// Output: 4
// Explanation: We can make every element equal to 4 by doing the following: 
// - Add x to 2 once.
// - Subtract x from 6 once.
// - Subtract x from 8 twice.
// A total of 4 operations were used.
// Example 2:


// Input: grid = [[1,5],[2,3]], x = 1
// Output: 5
// Explanation: We can make every element equal to 3.
// Example 3:


// Input: grid = [[1,2],[3,4]], x = 2
// Output: -1
// Explanation: It is impossible to make every element equal.
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 105
// 1 <= m * n <= 105
// 1 <= x, grid[i][j] <= 104

class Solution
{
public:
    int minOperations(vector<vector<int>> &grid, int x)
    {
        vector<int> values;
        for (const auto &row : grid)
        {
            for (int val : row)
            {
                values.push_back(val);
            }
        }

        sort(values.begin(), values.end());

        for (int val : values)
        {
            if (abs(val - values[0]) % x != 0)
            {
                return -1;
            }
        }

        int median = values[values.size() / 2];
        int opp = 0;

        for (int val : values)
        {
            opp += abs(val - median) / x;
        }

        return opp;
    }
};

/*
Code Explanation:
1. First, we flatten the 2D grid into a 1D array called 'values'
2. Sort the values array to find the median element
3. Check if all elements can be converted to the same value using x:
   - If any element's difference with first element is not divisible by x, return -1
4. Find the median value which will be our target value
5. Calculate minimum operations needed by summing up the absolute differences 
   between each value and median, divided by x

Time Complexity: O(n*m*log(n*m)) where n,m are grid dimensions - due to sorting
Space Complexity: O(n*m) for storing flattened array
*/