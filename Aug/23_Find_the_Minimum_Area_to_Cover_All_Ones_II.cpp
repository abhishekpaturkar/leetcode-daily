// 3197. Find the Minimum Area to Cover All Ones II

// You are given a 2D binary array grid. You need to find 3 non-overlapping rectangles having non-zero areas with horizontal and vertical sides such that all the 1's in grid lie inside these rectangles.

// Return the minimum possible sum of the area of these rectangles.

// Note that the rectangles are allowed to touch.

 

// Example 1:

// Input: grid = [[1,0,1],[1,1,1]]

// Output: 5

// Explanation:



// The 1's at (0, 0) and (1, 0) are covered by a rectangle of area 2.
// The 1's at (0, 2) and (1, 2) are covered by a rectangle of area 2.
// The 1 at (1, 1) is covered by a rectangle of area 1.
// Example 2:

// Input: grid = [[1,0,1,0],[0,1,0,1]]

// Output: 5

// Explanation:



// The 1's at (0, 0) and (0, 2) are covered by a rectangle of area 3.
// The 1 at (1, 1) is covered by a rectangle of area 1.
// The 1 at (1, 3) is covered by a rectangle of area 1.
 

// Constraints:

// 1 <= grid.length, grid[i].length <= 30
// grid[i][j] is either 0 or 1.
// The input is generated such that there are at least three 1's in grid.

class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        // prefix sum for fast submatrix sum
        vector<vector<int>> pre(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                pre[i+1][j+1] = pre[i+1][j] + pre[i][j+1] - pre[i][j] + grid[i][j];

        auto countOnes = [&](int r1, int r2, int c1, int c2) -> int {
            if (r1 > r2 || c1 > c2) return 0;
            return pre[r2+1][c2+1] - pre[r1][c2+1] - pre[r2+1][c1] + pre[r1][c1];
        };

        auto boundingArea = [&](int r1, int r2, int c1, int c2) -> int {
            int cnt = countOnes(r1, r2, c1, c2);
            if (cnt == 0) return 0;

            int top = r1, bottom = r2, left = c1, right = c2;

            while (top <= r2 && countOnes(top, top, c1, c2) == 0) ++top;
            while (bottom >= r1 && countOnes(bottom, bottom, c1, c2) == 0) --bottom;
            while (left <= c2 && countOnes(r1, r2, left, left) == 0) ++left;
            while (right >= c1 && countOnes(r1, r2, right, right) == 0) --right;

            return (bottom - top + 1) * (right - left + 1);
        };

        const int INF = 1e9;
        // dp[k][r1][r2][c1][c2] = min area to cover ones in submatrix with up to k rectangles
        auto make4D = [&](int init) {
            return vector(n, vector(n, vector(m, vector<int>(m, init))));
        };
        auto dp1 = make4D(0), dp2 = make4D(0), dp3 = make4D(0);

        // iterate submatrices by height & width
        for (int h = 1; h <= n; ++h) {
            for (int r1 = 0; r1 + h - 1 < n; ++r1) {
                int r2 = r1 + h - 1;
                for (int w = 1; w <= m; ++w) {
                    for (int c1 = 0; c1 + w - 1 < m; ++c1) {
                        int c2 = c1 + w - 1;

                        int cnt = countOnes(r1, r2, c1, c2);
                        if (cnt == 0) {
                            dp1[r1][r2][c1][c2] = dp2[r1][r2][c1][c2] = dp3[r1][r2][c1][c2] = 0;
                            continue;
                        }

                        // base: one rectangle
                        int one = boundingArea(r1, r2, c1, c2);
                        int best2 = one;
                        int best3 = one;

                        // vertical splits
                        for (int mid = c1; mid < c2; ++mid) {
                            int lcnt = countOnes(r1, r2, c1, mid);
                            int rcnt = cnt - lcnt;

                            best2 = min(best2, dp1[r1][r2][c1][mid] + dp1[r1][r2][mid+1][c2]);
                            if (rcnt == 0) best2 = min(best2, dp2[r1][r2][c1][mid]);
                            if (lcnt == 0) best2 = min(best2, dp2[r1][r2][mid+1][c2]);

                            best3 = min(best3, dp2[r1][r2][c1][mid] + dp1[r1][r2][mid+1][c2]);
                            best3 = min(best3, dp1[r1][r2][c1][mid] + dp2[r1][r2][mid+1][c2]);
                            if (rcnt == 0) best3 = min(best3, dp3[r1][r2][c1][mid]);
                            if (lcnt == 0) best3 = min(best3, dp3[r1][r2][mid+1][c2]);
                        }

                        // horizontal splits
                        for (int mid = r1; mid < r2; ++mid) {
                            int tcnt = countOnes(r1, mid, c1, c2);
                            int bcnt = cnt - tcnt;

                            best2 = min(best2, dp1[r1][mid][c1][c2] + dp1[mid+1][r2][c1][c2]);
                            if (bcnt == 0) best2 = min(best2, dp2[r1][mid][c1][c2]);
                            if (tcnt == 0) best2 = min(best2, dp2[mid+1][r2][c1][c2]);

                            best3 = min(best3, dp2[r1][mid][c1][c2] + dp1[mid+1][r2][c1][c2]);
                            best3 = min(best3, dp1[r1][mid][c1][c2] + dp2[mid+1][r2][c1][c2]);
                            if (bcnt == 0) best3 = min(best3, dp3[r1][mid][c1][c2]);
                            if (tcnt == 0) best3 = min(best3, dp3[mid+1][r2][c1][c2]);
                        }

                        dp1[r1][r2][c1][c2] = one;
                        dp2[r1][r2][c1][c2] = best2;
                        dp3[r1][r2][c1][c2] = best3;
                    }
                }
            }
        }

        return dp3[0][n-1][0][m-1];
    }
};