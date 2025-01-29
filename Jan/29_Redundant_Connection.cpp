// 684. Redundant Connection
// Solved
// Medium
// Topics
// Companies
// In this problem, a tree is an undirected graph that is connected and has no cycles.

// You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

// Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

 

// Example 1:


// Input: edges = [[1,2],[1,3],[2,3]]
// Output: [2,3]
// Example 2:


// Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
// Output: [1,4]
 

// Constraints:

// n == edges.length
// 3 <= n <= 1000
// edges[i].length == 2
// 1 <= ai < bi <= edges.length
// ai != bi
// There are no repeated edges.
// The given graph is connected

class Solution
{
    vector<int> parent;
    vector<int> rank;

    int find(int i)
    {
        if (parent[i] != i)
            parent[i] = find(parent[i]); // Path compression
        return parent[i];
    }

    void join(int u, int v)
    {
        int rootU = find(u), rootV = find(v);
        if (rootU != rootV)
        {
            // Union by rank to balance trees
            if (rank[rootU] > rank[rootV])
                parent[rootV] = rootU;
            else if (rank[rootU] < rank[rootV])
                parent[rootU] = rootV;
            else
            {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        // Initialize each node as its own parent
        for (int i = 1; i <= n; i++)
            parent[i] = i;

        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1];
            if (find(u) == find(v))
                return edge; // Cycle detected!
            join(u, v);      // Merge sets
        }

        return {}; // Unreachable for valid inputs
    }
};

/*
This code implements a solution to find a redundant connection in a graph using the Union-Find (Disjoint Set) data structure. Here's how it works:

1. The Solution class uses two vectors:
   - parent: stores the parent of each node
   - rank: stores the height of each subtree for union by rank optimization

2. The find() function implements path compression:
   - Finds the root parent of a node
   - Compresses the path by making all nodes in the path point directly to the root

3. The join() function implements union by rank:
   - Merges two sets based on their ranks
   - Attaches the shorter tree to the root of the taller tree
   - If ranks are equal, arbitrarily chooses one as root and increments its rank

4. The findRedundantConnection() function:
   - Initializes the disjoint set with n+1 nodes (1-based indexing)
   - Processes each edge in the input
   - If an edge connects nodes that are already in the same set, it's redundant
   - Otherwise, joins the sets containing the two nodes

The algorithm efficiently detects cycles in the graph while maintaining a balanced tree structure through union by rank and path compression optimizations.
*/