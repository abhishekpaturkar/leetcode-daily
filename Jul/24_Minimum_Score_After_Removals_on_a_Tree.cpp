// 2322. Minimum Score After Removals on a Tree

// There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.

// You are given a 0-indexed integer array nums of length n where nums[i] represents the value of the ith node. You are also given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

// Remove two distinct edges of the tree to form three connected components. For a pair of removed edges, the following steps are defined:

// Get the XOR of all the values of the nodes for each of the three components respectively.
// The difference between the largest XOR value and the smallest XOR value is the score of the pair.
// For example, say the three components have the node values: [4,5,7], [1,9], and [3,3,3]. The three XOR values are 4 ^ 5 ^ 7 = 6, 1 ^ 9 = 8, and 3 ^ 3 ^ 3 = 3. The largest XOR value is 8 and the smallest XOR value is 3. The score is then 8 - 3 = 5.
// Return the minimum score of any possible pair of edge removals on the given tree.

 

// Example 1:


// Input: nums = [1,5,5,4,11], edges = [[0,1],[1,2],[1,3],[3,4]]
// Output: 9
// Explanation: The diagram above shows a way to make a pair of removals.
// - The 1st component has nodes [1,3,4] with values [5,4,11]. Its XOR value is 5 ^ 4 ^ 11 = 10.
// - The 2nd component has node [0] with value [1]. Its XOR value is 1 = 1.
// - The 3rd component has node [2] with value [5]. Its XOR value is 5 = 5.
// The score is the difference between the largest and smallest XOR value which is 10 - 1 = 9.
// It can be shown that no other pair of removals will obtain a smaller score than 9.
// Example 2:


// Input: nums = [5,5,2,4,4,2], edges = [[0,1],[1,2],[5,2],[4,3],[1,3]]
// Output: 0
// Explanation: The diagram above shows a way to make a pair of removals.
// - The 1st component has nodes [3,4] with values [4,4]. Its XOR value is 4 ^ 4 = 0.
// - The 2nd component has nodes [1,0] with values [5,5]. Its XOR value is 5 ^ 5 = 0.
// - The 3rd component has nodes [2,5] with values [2,2]. Its XOR value is 2 ^ 2 = 0.
// The score is the difference between the largest and smallest XOR value which is 0 - 0 = 0.
// We cannot obtain a smaller score than 0.
 

// Constraints:

// n == nums.length
// 3 <= n <= 1000
// 1 <= nums[i] <= 108
// edges.length == n - 1
// edges[i].length == 2
// 0 <= ai, bi < n
// ai != bi
// edges represents a valid tree.

class Solution
{
public:
    int ans = 1e9, xo = 0, time = 0;
    void dfs(int node, int par, vector<vector<int>> &adj, vector<int> &nums, vector<int> &sub, vector<int> &in, vector<int> &out)
    {
        in[node] = time++;
        sub[node] = nums[node];
        for (auto child : adj[node])
        {
            if (child == par)
                continue;
            dfs(child, node, adj, nums, sub, in, out);
            sub[node] ^= sub[child];
        }
        out[node] = time++;
    }

    int minimumScore(vector<int> &nums, vector<vector<int>> &edges)
    {
        int n = nums.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++)
        {
            xo ^= nums[i];
        }
        for (int i = 0; i < n - 1; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> sub(n, 0), in(n), out(n);
        dfs(0, 0, adj, nums, sub, in, out);
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (i == j)
                    continue;
                else if (in[i] < in[j] && out[i] > out[j])
                {
                    int x = sub[j];
                    int y = sub[i] ^ sub[j];
                    int z = xo ^ sub[i];
                    int mn = min(x, min(y, z)), mx = max(x, max(y, z));
                    ans = min(ans, mx - mn);
                }
                else if (in[i] > in[j] && out[i] < out[j])
                {
                    int x = sub[i];
                    int y = sub[i] ^ sub[j];
                    int z = xo ^ sub[j];
                    int mn = min(x, min(y, z)), mx = max(x, max(y, z));
                    ans = min(ans, mx - mn);
                }
                else
                {
                    int x = sub[i];
                    int y = sub[j];
                    int z = xo ^ sub[i] ^ sub[j];
                    int mn = min(x, min(y, z)), mx = max(x, max(y, z));
                    ans = min(ans, mx - mn);
                }
            }
        }
        return ans;
    }
};