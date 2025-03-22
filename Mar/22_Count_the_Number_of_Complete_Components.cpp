// 2685. Count the Number of Complete Components

// You are given an undirected graph with n nodes labeled from 0 to n-1. The graph is represented by:
// An integer n, denoting the number of nodes.
// A list of edges edges, where each edges[i] = [u, v] represents an undirected edge between nodes u and v.
// A complete component is a connected component where every pair of nodes within that component has a direct edge between them. In other words, if a component has k nodes, it should contain exactly k * (k - 1) / 2 edges.

// Objective:
// Determine the number of complete components present in the given graph.

// Constraints & Conditions:
// Each node is uniquely labeled from 0 to n-1.
// The graph may consist of multiple connected components.
// A connected component is a complete component if every pair of nodes within that component is directly connected.
// A node with no edges is considered a complete component of size 1.

// Input:
// n: An integer representing the number of nodes in the graph.
// edges: A list of pairs [u, v] where each pair represents an undirected edge between nodes u and v.

// Output:
// Return an integer representing the number of complete components in the given graph.

class Solution {
    void dfs(int curr, int& nodes, int& edges, vector<vector<int>>& adj, vector<bool>& visited) {
        nodes++;
        visited[curr] = true;
        
        for (int& nbr : adj[curr]) {
            edges++;
            if (!visited[nbr]) {
                dfs(nbr, nodes, edges, adj, visited);
            }
        }
    }

 public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        int complete_components = 0;
        vector<bool> visited(n, false);
        
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int edges = 0;
                int nodes = 0;
                
                dfs(i, nodes, edges, adj, visited);
                
                if (edges == (nodes * (nodes - 1))) {
                    complete_components++;
                }
            }
        }
        return complete_components;
    }
};