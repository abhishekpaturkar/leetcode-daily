// 2661. First Completely Painted Row or Column

// You are given a 0-indexed integer array arr, and an m x n integer matrix mat. arr and mat both contain all the integers in the range [1, m * n].

// Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].

// Return the smallest index i at which either a row or a column will be completely painted in mat.

// Example 1:

// image explanation for example 1
// Input: arr = [1,3,4,2], mat = [[1,4],[2,3]]
// Output: 2
// Explanation: The moves are shown in order, and both the first row and second column of the matrix become fully painted at arr[2].
// Example 2:

// image explanation for example 2
// Input: arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
// Output: 3
// Explanation: The second column becomes fully painted at arr[3].
 

// Constraints:

// m == mat.length
// n = mat[i].length
// arr.length == m * n
// 1 <= m, n <= 105
// 1 <= m * n <= 105
// 1 <= arr[i], mat[r][c] <= m * n
// All the integers of arr are unique.
// All the integers of mat are unique.

class Solution
{
public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {
        int rows = mat.size(), cols = mat[0].size();
        unordered_map<int, pair<int, int>> positionMap;
        vector<int> rowCount(rows, cols), colCount(cols, rows);

        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                positionMap[mat[r][c]] = {r, c};
            }
        }

        for (int idx = 0; idx < arr.size(); ++idx)
        {
            int val = arr[idx];
            auto [row, col] = positionMap[val];

            if (--rowCount[row] == 0 || --colCount[col] == 0)
            {
                return idx;
            }
        }

        return -1;
    }
};

/*
This code solves the problem of finding the first completely painted row or column in a matrix. Here's how it works:

1. First, it creates a position map that stores the row and column coordinates for each number in the matrix.

2. It initializes two counters:
   - rowCount: tracks remaining unpainted cells in each row (initialized to number of columns)
   - colCount: tracks remaining unpainted cells in each column (initialized to number of rows)

3. For each number in the input array 'arr':
   - Finds its position in the matrix using positionMap
   - Decrements the count for that number's row and column
   - If either count reaches zero, returns the current index

4. Returns -1 if no row or column is completely painted (though this case won't occur given the problem constraints)

Time Complexity: O(m*n) for building map, O(k) for processing array where k = m*n
Space Complexity: O(m*n) for the position map and counter arrays
*/