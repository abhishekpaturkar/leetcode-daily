// 3372. Maximize the Number of Target Nodes After Connecting Trees I

// There exist two undirected trees with n and m nodes, with distinct labels in ranges [0, n - 1] and [0, m - 1], respectively.

// You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree. You are also given an integer k.

// Node u is target to node v if the number of edges on the path from u to v is less than or equal to k. Note that a node is always target to itself.

// Return an array of n integers answer, where answer[i] is the maximum possible number of nodes target to node i of the first tree if you have to connect one node from the first tree to another node in the second tree.

// Note that queries are independent from each other. That is, for every query you will remove the added edge before proceeding to the next query.

 

// Example 1:

// Input: edges1 = [[0,1],[0,2],[2,3],[2,4]], edges2 = [[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]], k = 2

// Output: [9,7,9,8,8]

// Explanation:

// For i = 0, connect node 0 from the first tree to node 0 from the second tree.
// For i = 1, connect node 1 from the first tree to node 0 from the second tree.
// For i = 2, connect node 2 from the first tree to node 4 from the second tree.
// For i = 3, connect node 3 from the first tree to node 4 from the second tree.
// For i = 4, connect node 4 from the first tree to node 4 from the second tree.

// Example 2:

// Input: edges1 = [[0,1],[0,2],[0,3],[0,4]], edges2 = [[0,1],[1,2],[2,3]], k = 1

// Output: [6,3,3,3,3]

// Explanation:

// For every i, connect node i of the first tree with any node of the second tree.


 

// Constraints:

// 2 <= n, m <= 1000
// edges1.length == n - 1
// edges2.length == m - 1
// edges1[i].length == edges2[i].length == 2
// edges1[i] = [ai, bi]
// 0 <= ai, bi < n
// edges2[i] = [ui, vi]
// 0 <= ui, vi < m
// The input is generated such that edges1 and edges2 represent valid trees.
// 0 <= k <= 1000

class Solution
{
public:
    vector<vector<int>> buildList(const vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(edges.size() + 1);
        for (auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return adj;
    }

    int dfs(const vector<vector<int>> &adj, int u, int p, int k)
    {
        if (k < 0)
            return 0;
        int cnt = 1;
        for (int v : adj[u])
            if (v != p)
                cnt += dfs(adj, v, u, k - 1);
        return cnt;
    }

    vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2, int k)
    {
        auto adj1 = buildList(edges1), adj2 = buildList(edges2);
        int n = adj1.size(), m = adj2.size(), maxiB = 0;
        vector<int> res(n);

        for (int i = 0; i < m; i++)
            maxiB = max(maxiB, dfs(adj2, i, -1, k - 1));
        for (int i = 0; i < n; i++)
            res[i] = dfs(adj1, i, -1, k) + maxiB;
        return res;
    }
};

/*
This code solves the problem of finding the maximum number of target nodes after connecting two trees.

The solution consists of three main functions:

1. buildList: Converts edge list representation to adjacency list representation
   - Takes edges as input and creates an undirected graph using adjacency lists
   - Time: O(E) where E is number of edges
   - Space: O(V + E) where V is number of vertices

2. dfs: Performs depth-first search to count reachable nodes within k steps
   - Counts nodes that can be reached from current node within k steps
   - Uses parent pointer to avoid going back
   - Time: O(V + E) for each DFS call
   - Space: O(H) where H is height of tree (recursion stack)

3. maxTargetNodes: Main function that solves the problem
   - Builds adjacency lists for both trees
   - For each node in first tree, finds maximum reachable nodes by connecting to second tree
   - Uses DFS to count reachable nodes in both trees
   - Time: O(V1 * (V1 + E1) + V2 * (V2 + E2)) where V1,E1 and V2,E2 are vertices and edges of trees
   - Space: O(V1 + E1 + V2 + E2) for adjacency lists

Overall Time Complexity: O(V1 * (V1 + E1) + V2 * (V2 + E2))
Overall Space Complexity: O(V1 + E1 + V2 + E2)
*/