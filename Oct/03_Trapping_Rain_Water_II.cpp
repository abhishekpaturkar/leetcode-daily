// 407. Trapping Rain Water II

// Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.

 

// Example 1:


// Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
// Output: 4
// Explanation: After the rain, water is trapped between the blocks.
// We have two small ponds 1 and 3 units trapped.
// The total volume of water trapped is 4.
// Example 2:


// Input: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
// Output: 10
 

// Constraints:

// m == heightMap.length
// n == heightMap[i].length
// 1 <= m, n <= 200
// 0 <= heightMap[i][j] <= 2 * 104

#include <vector>
#include <queue>
#include <tuple>
using namespace std;

class Solution
{
public:
    int trapRainWater(vector<vector<int>> &heightMap)
    {
        if (heightMap.empty() || heightMap[0].empty())
            return 0;
        int m = heightMap.size(), n = heightMap[0].size();
        if (m < 3 || n < 3)
            return 0;

        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i)
        {
            pq.emplace(heightMap[i][0], i, 0);
            visited[i][0] = true;
            pq.emplace(heightMap[i][n - 1], i, n - 1);
            visited[i][n - 1] = true;
        }
        for (int j = 0; j < n; ++j)
        {
            if (!visited[0][j])
            {
                pq.emplace(heightMap[0][j], 0, j);
                visited[0][j] = true;
            }
            if (!visited[m - 1][j])
            {
                pq.emplace(heightMap[m - 1][j], m - 1, j);
                visited[m - 1][j] = true;
            }
        }

        int res = 0;
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!pq.empty())
        {
            auto [h, r, c] = pq.top();
            pq.pop();
            for (auto &d : dirs)
            {
                int nr = r + d[0], nc = c + d[1];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n || visited[nr][nc])
                    continue;
                visited[nr][nc] = true;
                int nh = heightMap[nr][nc];
                if (nh < h)
                    res += h - nh;
                pq.emplace(max(nh, h), nr, nc);
            }
        }
        return res;
    }
};