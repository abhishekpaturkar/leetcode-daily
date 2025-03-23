// 1976. Number of Ways to Arrive at Destination

// You are given a weighted undirected graph with n nodes labeled from 0 to n-1. The graph is represented by:
// An integer n, denoting the number of nodes.
// A list of roads, where each roads[i] = [u, v, time] represents a bidirectional road between nodes u and v with a travel time of time.
// You need to determine the number of different ways to reach node n-1 starting from node 0, using the shortest possible travel time. Since the answer can be large, return it modulo 10^9 + 7.

// Constraints & Conditions:
// The graph is undirected (bidirectional edges).
// The graph may have multiple paths between 0 and n-1.
// We are only interested in paths that use the minimum possible travel time.
// There may be cycles, but all edges have positive weights.
// If there is only one shortest path, return 1.

// Input:
// n: An integer representing the number of nodes in the graph.
// roads: A list of triplets [u, v, time], where each triplet represents an undirected road with a travel time.

// Output:
// Return an integer representing the number of different ways to reach n-1 from 0 using the shortest possible travel time, modulo 10^9 + 7.

class Solution {
    #define ll long long
    #define pll pair<ll, ll>
    #define MOD 1000000007

 public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pll>> adj(n);
        
        for (auto& road : roads) {
            adj[road[0]].push_back(make_pair(road[1], road[2]));
            adj[road[1]].push_back(make_pair(road[0], road[2]));
        }

        priority_queue<pll, vector<pll>, greater<pll>> minheap;
        minheap.push(make_pair(0, 0));

        vector<bool> processed(n, false);
        vector<ll> count_ways(n, 0);
        vector<ll> min_cost(n, LONG_MAX);
        
        count_ways[0] = 1;
        min_cost[0] = 0;
        
        while (!minheap.empty()) {
            pll curr = minheap.top();
            minheap.pop();
            
            ll cost = curr.first;
            ll curr_node = curr.second;
            
            if (processed[curr_node]) {
                continue;
            }
            
            processed[curr_node] = true;
            
            for (auto& [nbr, weight] : adj[curr_node]) {
                if (!processed[nbr]) {
                    if (cost + weight == min_cost[nbr]) {
                        count_ways[nbr] = (count_ways[nbr] + count_ways[curr_node]) % MOD;
                    } else if (cost + weight < min_cost[nbr]) {
                        min_cost[nbr] = cost + weight;
                        count_ways[nbr] = count_ways[curr_node];
                        minheap.push(make_pair(cost + weight, nbr));
                    }
                }
            }
        }
        
        return count_ways[n - 1];
    }
};
