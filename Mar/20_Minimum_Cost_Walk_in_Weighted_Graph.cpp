// 3108. Minimum Cost Walk in Weighted Graph

// There is an undirected weighted graph with n vertices labeled from 0 to n - 1.

// You are given the integer n and an array edges, where edges[i] = [ui, vi, wi] indicates that there is an edge between vertices ui and vi with a weight of wi.

// A walk on a graph is a sequence of vertices and edges. The walk starts and ends with a vertex, and each edge connects the vertex that comes before it and the vertex that comes after it. It's important to note that a walk may visit the same edge or vertex more than once.

// The cost of a walk starting at node u and ending at node v is defined as the bitwise AND of the weights of the edges traversed during the walk. In other words, if the sequence of edge weights encountered during the walk is w0, w1, w2, ..., wk, then the cost is calculated as w0 & w1 & w2 & ... & wk, where & denotes the bitwise AND operator.

// You are also given a 2D array query, where query[i] = [si, ti]. For each query, you need to find the minimum cost of the walk starting at vertex si and ending at vertex ti. If there exists no such walk, the answer is -1.

// Return the array answer, where answer[i] denotes the minimum cost of a walk for query i.

// Example 1:

// Input: n = 5, edges = [[0,1,7],[1,3,7],[1,2,1]], query = [[0,3],[3,4]]

// Output: [1,-1]

// Explanation:

// To achieve the cost of 1 in the first query, we need to move on the following edges: 0->1 (weight 7), 1->2 (weight 1), 2->1 (weight 1), 1->3 (weight 7).

// In the second query, there is no walk between nodes 3 and 4, so the answer is -1.

// Example 2:

// Input: n = 3, edges = [[0,2,7],[0,1,15],[1,2,6],[1,2,1]], query = [[1,2]]

// Output: [0]

// Explanation:

// To achieve the cost of 0 in the first query, we need to move on the following edges: 1->2 (weight 1), 2->1 (weight 6), 1->2 (weight 1).

// Constraints:

// 2 <= n <= 105
// 0 <= edges.length <= 105
// edges[i].length == 3
// 0 <= ui, vi <= n - 1
// ui != vi
// 0 <= wi <= 105
// 1 <= query.length <= 105
// query[i].length == 2
// 0 <= si, ti <= n - 1
// si != ti

class Solution
{
public:
    class DSU
    {
    public:
        int n;
        vector<int> parent, rank, bitAnd;
        DSU(int _n)
        {
            n = _n;
            int maxAnd = pow(2, 30) - 1; // 11111..1111
            parent.resize(n);
            bitAnd.resize(n, maxAnd);
            rank.resize(n, 1); // all components rank 1 initialy
            for (int i = 0; i < n; i++)
            {
                parent[i] = i; // each is its own parent intiially
            }
        }

        int find(int x)
        {
            if (parent[x] != x)
            {
                parent[x] = find(parent[x]); // path compression
            }
            return parent[x];
        }

        // while combining edges, add the bitwise AND of edge to component that becomes parent
        void combine(int x, int y, int w)
        {
            int rootX = find(x);
            int rootY = find(y);

            if (rootX == rootY)
            {
                bitAnd[rootX] &= w; // add bitwise AND of edge to component
                return;
            }
            if (rank[rootX] > rank[rootY])
            {
                parent[rootY] = rootX;
                bitAnd[rootX] &= bitAnd[rootY];
                bitAnd[rootX] &= w;
            }
            else if (rank[rootX] < rank[rootY])
            {
                parent[rootX] = rootY;
                bitAnd[rootY] &= bitAnd[rootX];
                bitAnd[rootY] &= w;
            }
            else
            { // if equal rank, increase rank of the one with more elements
                parent[rootY] = rootX;
                rank[rootX]++;
                bitAnd[rootX] &= bitAnd[rootY];
                bitAnd[rootX] &= w;
            }
        }

        int getANDofComponent(int root)
        {
            return bitAnd[root];
        }
    };

    vector<int> minimumCost(int n, vector<vector<int>> &edges, vector<vector<int>> &query)
    {
        vector<int> ans;
        DSU dsu = DSU(n);

        for (auto &edge : edges)
        {
            int ui = edge[0], vi = edge[1], wi = edge[2];
            dsu.combine(ui, vi, wi);
        }

        for (auto &q : query)
        {
            int ui = q[0], vi = q[1];
            int rootU = dsu.find(ui), rootV = dsu.find(vi);
            if (rootU == rootV)
            {
                ans.push_back(dsu.getANDofComponent(rootU));
            }
            else
            { // diff components, no path exists
                ans.push_back(-1);
            }
        }

        return ans;
    }
};

/*
Code Explanation:
This solution uses Disjoint Set Union (DSU) data structure to solve the minimum cost walk problem in a weighted graph.

1. DSU Class:
   - Maintains three vectors: parent (for tracking parent nodes), rank (for union by rank), and bitAnd (for storing bitwise AND values)
   - find(): Implements path compression to find the root of a component
   - combine(): Merges two components and maintains the bitwise AND of edge weights
   - getANDofComponent(): Returns the bitwise AND value of a component

2. minimumCost Function:
   - Creates a DSU object with n vertices
   - Processes each edge by combining vertices and updating bitwise AND values
   - For each query, checks if vertices are in same component:
     * If yes, returns the component's bitwise AND value
     * If no, returns -1 (no path exists)

Time Complexity:
- DSU initialization: O(n)
- find() operation: O(α(n)) amortized, where α is the inverse Ackermann function
- combine() operation: O(α(n))
- Overall: O(n + (E + Q) * α(n)), where E is number of edges and Q is number of queries

Space Complexity:
- O(n) for DSU vectors (parent, rank, bitAnd)
- O(Q) for answer vector
- Overall: O(n + Q)
*/
