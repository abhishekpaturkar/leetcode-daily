// 2493. Divide Nodes Into the Maximum Number of Groups

// You are given a positive integer n representing the number of nodes in an undirected graph. The nodes are labeled from 1 to n.

// You are also given a 2D integer array edges, where edges[i] = [ai, bi] indicates that there is a bidirectional edge between nodes ai and bi. Notice that the given graph may be disconnected.

// Divide the nodes of the graph into m groups (1-indexed) such that:

// Each node in the graph belongs to exactly one group.
// For every pair of nodes in the graph that are connected by an edge [ai, bi], if ai belongs to the group with index x, and bi belongs to the group with index y, then |y - x| = 1.
// Return the maximum number of groups (i.e., maximum m) into which you can divide the nodes. Return -1 if it is impossible to group the nodes with the given conditions.
 

// Example 1:


// Input: n = 6, edges = [[1,2],[1,4],[1,5],[2,6],[2,3],[4,6]]
// Output: 4
// Explanation: As shown in the image we:
// - Add node 5 to the first group.
// - Add node 1 to the second group.
// - Add nodes 2 and 4 to the third group.
// - Add nodes 3 and 6 to the fourth group.
// We can see that every edge is satisfied.
// It can be shown that that if we create a fifth group and move any node from the third or fourth group to it, at least on of the edges will not be satisfied.
// Example 2:

// Input: n = 3, edges = [[1,2],[2,3],[3,1]]
// Output: -1
// Explanation: If we add node 1 to the first group, node 2 to the second group, and node 3 to the third group to satisfy the first two edges, we can see that the third edge will not be satisfied.
// It can be shown that no grouping is possible.
 

// Constraints:

// 1 <= n <= 500
// 1 <= edges.length <= 104
// edges[i].length == 2
// 1 <= ai, bi <= n
// ai != bi
// There is at most one edge between any pair of vertices.

class Solution
{
    vector<int> color;       // Tracks bipartition colors (0/1)
    vector<vector<int>> adj; // Adjacency list
    int n;                   // Number of nodes

    // DFS to check bipartiteness and collect component nodes
    bool isBipartite(int node, int c, vector<int> &component)
    {
        color[node] = c;
        component.push_back(node);
        for (int nbr : adj[node])
        {
            if (color[nbr] == c)
                return false; // Odd cycle detected
            if (color[nbr] == -1 && !isBipartite(nbr, 1 - c, component))
                return false;
        }
        return true;
    }

    // BFS to compute max depth (groups) for a component
    int maxGroupsInComponent(const vector<int> &component)
    {
        int maxDepth = 0;
        for (int start : component)
        {
            vector<int> depth(n, -1);
            queue<int> q;
            q.push(start);
            depth[start] = 0;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                for (int nbr : adj[node])
                {
                    if (depth[nbr] == -1)
                    {
                        depth[nbr] = depth[node] + 1;
                        maxDepth = max(maxDepth, depth[nbr]);
                        q.push(nbr);
                    }
                }
            }
        }
        return maxDepth + 1; // Depth to groups conversion
    }

public:
    int magnificentSets(int n, vector<vector<int>> &edges)
    {
        this->n = n;
        color.assign(n, -1);
        adj.resize(n);
        for (auto &e : edges)
        {
            int u = e[0] - 1, v = e[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<int>> components;
        for (int i = 0; i < n; ++i)
        {
            if (color[i] == -1)
            {
                components.emplace_back();
                if (!isBipartite(i, 0, components.back()))
                    return -1; // Non-bipartite component
            }
        }

        int total = 0;
        for (auto &comp : components)
            total += maxGroupsInComponent(comp);

        return total;
    }
};

/*
This code solves the problem of dividing nodes into the maximum number of groups with specific conditions:

1. The Solution class uses:
   - A color vector for bipartite checking
   - An adjacency list (adj) for graph representation
   - Variable n for total nodes

2. Key components:
   - isBipartite(): Uses DFS to check if graph components are bipartite and collects nodes
   - maxGroupsInComponent(): Uses BFS to find maximum possible groups in a component
   - magnificentSets(): Main function that processes the graph

3. Algorithm flow:
   a. Builds adjacency list from edges
   b. Finds connected components and checks bipartiteness
   c. For each valid component, calculates maximum possible groups
   d. Returns sum of all component groups or -1 if invalid

4. The solution works by:
   - Ensuring no odd cycles (bipartite check)
   - Computing maximum depth for each component using BFS
   - Converting depths to group numbers
   - Summing up all component groups for final result
*/