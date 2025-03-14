// 3160. Find the Number of Distinct Colors Among the Balls
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given an integer limit and a 2D array queries of size n x 2.

// There are limit + 1 balls with distinct labels in the range [0, limit]. Initially, all balls are uncolored. For every query in queries that is of the form [x, y], you mark ball x with the color y. After each query, you need to find the number of distinct colors among the balls.

// Return an array result of length n, where result[i] denotes the number of distinct colors after ith query.

// Note that when answering a query, lack of a color will not be considered as a color.

 

// Example 1:

// Input: limit = 4, queries = [[1,4],[2,5],[1,3],[3,4]]

// Output: [1,2,2,3]

// Explanation:



// After query 0, ball 1 has color 4.
// After query 1, ball 1 has color 4, and ball 2 has color 5.
// After query 2, ball 1 has color 3, and ball 2 has color 5.
// After query 3, ball 1 has color 3, ball 2 has color 5, and ball 3 has color 4.
// Example 2:

// Input: limit = 4, queries = [[0,1],[1,2],[2,2],[3,4],[4,5]]

// Output: [1,2,2,3,4]

// Explanation:



// After query 0, ball 0 has color 1.
// After query 1, ball 0 has color 1, and ball 1 has color 2.
// After query 2, ball 0 has color 1, and balls 1 and 2 have color 2.
// After query 3, ball 0 has color 1, balls 1 and 2 have color 2, and ball 3 has color 4.
// After query 4, ball 0 has color 1, balls 1 and 2 have color 2, ball 3 has color 4, and ball 4 has color 5.
 

// Constraints:

// 1 <= limit <= 109
// 1 <= n == queries.length <= 105
// queries[i].length == 2
// 0 <= queries[i][0] <= limit
// 1 <= queries[i][1] <= 109

class Solution
{
public:
    vector<int> queryResults(int limit, vector<vector<int>> &queries)
    {
        unordered_map<int, int> ball, color;
        vector<int> ans;
        ans.reserve(queries.size());
        int distinct = 0;
        for (auto &q : queries)
        {
            int pos = q[0], c = q[1];
            if (ball.count(pos))
                if (--color[ball[pos]] == 0)
                    distinct--;
            ball[pos] = c;
            if (++color[c] == 1)
                distinct++;
            ans.push_back(distinct);
        }
        return ans;
    }
};

/*
This code solves the problem of tracking distinct colors among balls:
1. Uses two hash maps: 'ball' maps ball positions to colors, 'color' tracks frequency of each color
2. For each query:
   - Checks if ball at position already has color
   - If yes, decrements old color count and updates distinct count if needed
   - Assigns new color to ball
   - Increments new color count and updates distinct count if it's first occurrence
   - Stores current distinct color count in result
3. Returns array of distinct color counts after each query
Time complexity: O(n) where n is number of queries
Space complexity: O(n) for storing results and ball/color mappings
*/