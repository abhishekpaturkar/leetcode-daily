// 802. Find Eventual Safe States

// There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

// A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

// Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

// Example 1:

// Illustration of graph
// Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
// Output: [2,4,5,6]
// Explanation: The given graph is shown above.
// Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
// Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.
// Example 2:

// Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
// Output: [4]
// Explanation:
// Only node 4 is a terminal node, and every path starting at node 4 leads to node 4.

// Constraints:

// n == graph.length
// 1 <= n <= 104
// 0 <= graph[i].length <= n
// 0 <= graph[i][j] <= n - 1
// graph[i] is sorted in a strictly increasing order.
// The graph may contain self-loops.
// The number of edges in the graph will be in the range [1, 4 * 104].

class Solution
{
public:
    bool DFSrecur(int s, vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &dfsVisited, vector<bool> &cycle_detect)
    {
        visited[s] = true;
        dfsVisited[s] = true;

        vector<int> data = graph[s];

        for (auto x : data)
        {
            if (!visited[x])
            {
                if (DFSrecur(x, graph, visited, dfsVisited, cycle_detect))
                {
                    return cycle_detect[s] = true;
                }
            }
            else if (visited[x] && dfsVisited[x])
            {
                return cycle_detect[s] = true;
            }
        }
        dfsVisited[s] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        vector<int> ans;

        int n = graph.size();
        vector<bool> visited(n, false), dfsVisited(n, false);
        vector<bool> cycle_detect(n, false);

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                DFSrecur(i, graph, visited, dfsVisited, cycle_detect);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (!cycle_detect[i])
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

/*
This code solves the problem of finding eventual safe nodes in a directed graph. Here's how it works:

1. The solution uses a DFS-based approach with cycle detection.

2. A node is considered safe if it doesn't lead to any cycle and all paths from it lead to terminal nodes.

3. The DFSrecur function:
   - Uses two visited arrays: one for normal DFS visits and another for tracking nodes in current DFS path
   - Uses cycle_detect array to mark nodes that are part of or lead to a cycle
   - Returns true if a cycle is detected, false otherwise

4. The eventualSafeNodes function:
   - Initializes necessary vectors for tracking visited nodes and cycle detection
   - Runs DFS from each unvisited node
   - Collects nodes that are not part of any cycle (safe nodes)
   - Returns the safe nodes in ascending order

5. Time Complexity: O(V + E) where V is number of vertices and E is number of edges
   Space Complexity: O(V) for the visited and cycle detection arrays
*/
