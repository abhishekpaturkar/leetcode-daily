// 1931. Painting a Grid With Three Different Colors
// Hard
// Topics
// Companies
// Hint
// You are given two integers m and n. Consider an m x n grid where each cell is initially white. You can paint each cell red, green, or blue. All cells must be painted.

// Return the number of ways to color the grid with no two adjacent cells having the same color. Since the answer can be very large, return it modulo 109 + 7.

 

// Example 1:


// Input: m = 1, n = 1
// Output: 3
// Explanation: The three possible colorings are shown in the image above.
// Example 2:


// Input: m = 1, n = 2
// Output: 6
// Explanation: The six possible colorings are shown in the image above.
// Example 3:

// Input: m = 5, n = 5
// Output: 580986
 

// Constraints:

// 1 <= m <= 5
// 1 <= n <= 1000

class Solution
{
    static const int MOD = 1000000007;

public:
    int colorTheGrid(int m, int n)
    {
        // Step 1: Generate all valid columns
        vector<vector<int>> states;
        vector<int> current(m);
        generateStates(m, current, 0, states);

        // Step 2: Build transitions between states (compatible pairs)
        vector<vector<int>> transitions(states.size());
        for (int i = 0; i < (int)states.size(); i++)
        {
            for (int j = 0; j < (int)states.size(); j++)
            {
                if (isCompatible(states[i], states[j]))
                {
                    transitions[i].push_back(j);
                }
            }
        }

        // Step 3: Initialize DP for the first column
        vector<long long> dp(states.size(), 1);

        // Step 4: DP over columns
        for (int col = 1; col < n; col++)
        {
            vector<long long> newDp(states.size(), 0);
            for (int prev = 0; prev < (int)states.size(); prev++)
            {
                if (dp[prev] == 0)
                {
                    continue;
                }

                for (int nxt : transitions[prev])
                {
                    newDp[nxt] = (newDp[nxt] + dp[prev]) % MOD;
                }
            }

            dp = move(newDp);
        }

        // Step 5: Sum all final configurations
        long long result = 0;
        for (long long val : dp)
        {
            result = (result + val) % MOD;
        }

        return (int)result;
    }

private:
    // Recursively generate all valid columns (no vertical same colors)
    void generateStates(int m, vector<int> &current, int row, vector<vector<int>> &states)
    {
        if (row == m)
        {
            states.push_back(current);
            return;
        }

        for (int color = 1; color <= 3; color++)
        {
            if (row > 0 && current[row - 1] == color)
            {
                continue;
            }

            current[row] = color;
            generateStates(m, current, row + 1, states);
        }
    }

    // Check if two columns are compatible horizontally (no same colors in any row)
    bool isCompatible(const vector<int> &a, const vector<int> &b)
    {
        for (int i = 0; i < (int)a.size(); i++)
        {
            if (a[i] == b[i])
            {
                return false;
            }
        }

        return true;
    }
};

/*
Code Explanation:
This solution solves the problem of coloring an m×n grid with three colors where no adjacent cells can have the same color.

The approach uses dynamic programming with state generation:

1. First, it generates all possible valid column states where no two adjacent cells in a column have the same color.

2. Then, it builds a transition matrix that shows which column states can be placed next to each other (no horizontal conflicts).

3. Uses DP to build the solution:
   - dp[i] represents the number of valid colorings ending with state i
   - For each column, it calculates new states based on valid transitions
   - Uses modulo arithmetic to handle large numbers

4. Finally, sums up all possible ending states to get the total number of valid colorings.

Time Complexity:
- State Generation: O(3^m) for generating all possible states
- Transition Matrix: O(S^2 * m) where S is number of states
- DP Calculation: O(n * S^2) where n is number of columns
Overall: O(3^m + n * 3^2m)

Space Complexity:
- States Storage: O(3^m * m)
- Transition Matrix: O(3^m * 3^m)
- DP Array: O(3^m)
Overall: O(3^2m)
*/