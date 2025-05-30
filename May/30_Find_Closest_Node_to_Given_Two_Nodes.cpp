// 2359. Find Closest Node to Given Two Nodes

// You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.

// The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from i, then edges[i] == -1.

// You are also given two integers node1 and node2.

// Return the index of the node that can be reached from both node1 and node2, such that the maximum between the distance from node1 to that node, and from node2 to that node is minimized. If there are multiple answers, return the node with the smallest index, and if no possible answer exists, return -1.

// Note that edges may contain cycles.

 

// Example 1:


// Input: edges = [2,2,3,-1], node1 = 0, node2 = 1
// Output: 2
// Explanation: The distance from node 0 to node 2 is 1, and the distance from node 1 to node 2 is 1.
// The maximum of those two distances is 1. It can be proven that we cannot get a node with a smaller maximum distance than 1, so we return node 2.
// Example 2:


// Input: edges = [1,2,-1], node1 = 0, node2 = 2
// Output: 2
// Explanation: The distance from node 0 to node 2 is 2, and the distance from node 2 to itself is 0.
// The maximum of those two distances is 2. It can be proven that we cannot get a node with a smaller maximum distance than 2, so we return node 2.
 

// Constraints:

// n == edges.length
// 2 <= n <= 105
// -1 <= edges[i] < n
// edges[i] != i
// 0 <= node1, node2 < n

class Solution
{
public:
    void dfs(int current, int distance, const vector<int> &edges, vector<int> &distances)
    {
        while (current != -1 && distances[current] == -1)
        {
            distances[current] = distance++;
            current = edges[current];
        }
    }

    int closestMeetingNode(vector<int> &edges, int start1, int start2)
    {
        int res = -1, Min_Of_Max = INT_MAX, n = edges.size();
        vector<int> dist1(n, -1), dist2(n, -1);
        dfs(start1, 0, edges, dist1);
        dfs(start2, 0, edges, dist2);

        for (int i = 0; i < n; i++)
        {
            if (dist1[i] >= 0 && dist2[i] >= 0)
            {
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < Min_Of_Max)
                {
                    Min_Of_Max = maxDist;
                    res = i;
                }
            }
        }
        return res;
    }
};

/*
Code Explanation:
This solution finds the closest node that can be reached from both given nodes in a directed graph.

1. The dfs function performs a depth-first search:
   - Takes current node, distance, edges array, and distances array as parameters
   - Updates distances for each reachable node from the start node
   - Continues until it hits a cycle or dead end (-1)

2. The closestMeetingNode function:
   - Initializes result as -1 and minimum maximum distance as INT_MAX
   - Creates two distance arrays dist1 and dist2 for paths from both start nodes
   - Calls dfs for both start nodes to fill distance arrays
   - Iterates through all nodes to find one reachable from both starts
   - Updates result when finding a better (smaller) maximum distance
   - Returns the node with smallest index that minimizes the maximum distance

Time Complexity: O(n) where n is the number of nodes
- DFS takes O(n) for each start node
- Final iteration takes O(n)
Total: O(n)

Space Complexity: O(n)
- Two distance arrays of size n
*/