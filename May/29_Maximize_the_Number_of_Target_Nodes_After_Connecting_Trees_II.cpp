// 3373. Maximize the Number of Target Nodes After Connecting Trees II

// There exist two undirected trees with n and m nodes, labeled from [0, n - 1] and [0, m - 1], respectively.

// You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree.

// Node u is target to node v if the number of edges on the path from u to v is even. Note that a node is always target to itself.

// Return an array of n integers answer, where answer[i] is the maximum possible number of nodes that are target to node i of the first tree if you had to connect one node from the first tree to another node in the second tree.

// Note that queries are independent from each other. That is, for every query you will remove the added edge before proceeding to the next query.

 

// Example 1:

// Input: edges1 = [[0,1],[0,2],[2,3],[2,4]], edges2 = [[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]]

// Output: [8,7,7,8,8]

// Explanation:

// For i = 0, connect node 0 from the first tree to node 0 from the second tree.
// For i = 1, connect node 1 from the first tree to node 4 from the second tree.
// For i = 2, connect node 2 from the first tree to node 7 from the second tree.
// For i = 3, connect node 3 from the first tree to node 0 from the second tree.
// For i = 4, connect node 4 from the first tree to node 4 from the second tree.

// Example 2:

// Input: edges1 = [[0,1],[0,2],[0,3],[0,4]], edges2 = [[0,1],[1,2],[2,3]]

// Output: [3,6,6,6,6]

// Explanation:

// For every i, connect node i of the first tree with any node of the second tree.


 

// Constraints:

// 2 <= n, m <= 105
// edges1.length == n - 1
// edges2.length == m - 1
// edges1[i].length == edges2[i].length == 2
// edges1[i] = [ai, bi]
// 0 <= ai, bi < n
// edges2[i] = [ui, vi]
// 0 <= ui, vi < m
// The input is generated such that edges1 and edges2 represent valid trees.

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

    void dfsColor(const vector<vector<int>> &adj, int u, int parent,
                  vector<int> &color, int &evenCnt, int &oddCnt)
    {
        if (color[u] == 0)
            evenCnt++;
        else
            oddCnt++;
        for (int v : adj[u])
            if (v != parent)
            {
                color[v] = color[u] ^ 1;
                dfsColor(adj, v, u, color, evenCnt, oddCnt);
            }
    }

    vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2)
    {
        auto adjA = buildList(edges1), adjB = buildList(edges2);
        int n = adjA.size(), m = adjB.size();
        vector<int> colorA(n, -1), colorB(m, -1);
        int evenA = 0, oddA = 0, evenB = 0, oddB = 0;
        colorA[0] = 0;
        dfsColor(adjA, 0, -1, colorA, evenA, oddA);
        colorB[0] = 0;
        dfsColor(adjB, 0, -1, colorB, evenB, oddB);
        int maxiB = max(evenB, oddB);
        vector<int> res(n);
        for (int i = 0; i < n; i++)
            res[i] = (colorA[i] == 0 ? evenA : oddA) + maxiB;
        return res;
    }
};

/*
This code solves the problem of finding maximum target nodes after connecting two trees.

The solution uses a 2-coloring approach where:
1. buildList function creates adjacency lists from edge lists
2. dfsColor performs DFS to color nodes and count even/odd colored nodes
3. maxTargetNodes combines results from both trees

Key steps:
- Convert edge lists to adjacency lists
- Color both trees (0/1 coloring)
- Count nodes with even/odd colors in both trees
- For each node in tree1, calculate max possible target nodes

Time Complexity: O(N + M) where N and M are number of nodes in trees
Space Complexity: O(N + M) for adjacency lists and color arrays
*/