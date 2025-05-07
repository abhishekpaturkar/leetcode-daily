// 3341. Find Minimum Time to Reach Last Room I

// There is a dungeon with n x m rooms arranged as a grid.

// You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds when you can start moving to that room. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving between adjacent rooms takes exactly one second.

// Return the minimum time to reach the room (n - 1, m - 1).

// Two rooms are adjacent if they share a common wall, either horizontally or vertically.

// Example 1:

// Input: moveTime = [[0,4],[4,4]]

// Output: 6

// Explanation:

// The minimum time required is 6 seconds.

// At time t == 4, move from room (0, 0) to room (1, 0) in one second.
// At time t == 5, move from room (1, 0) to room (1, 1) in one second.
// Example 2:

// Input: moveTime = [[0,0,0],[0,0,0]]

// Output: 3

// Explanation:

// The minimum time required is 3 seconds.

// At time t == 0, move from room (0, 0) to room (1, 0) in one second.
// At time t == 1, move from room (1, 0) to room (1, 1) in one second.
// At time t == 2, move from room (1, 1) to room (1, 2) in one second.
// Example 3:

// Input: moveTime = [[0,1],[1,2]]

// Output: 3

 

// Constraints:

// 2 <= n == moveTime.length <= 50
// 2 <= m == moveTime[i].length <= 50
// 0 <= moveTime[i][j] <= 109

class Solution
{
public:
    int minTimeToReach(vector<vector<int>> &moveTime)
    {
        int m = moveTime.size();
        int n = moveTime[0].size();

        // Step 1: Initialize distance matrix with max values
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0; // Starting point at time 0

        // Step 2: Use tuple instead of vector to allow structured bindings
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, 0, 0}); // Format: {currentTime, row, col}

        // Step 3: Directions for moving in 4 directions
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // Step 4: Process nodes while queue is not empty
        while (!pq.empty())
        {
            auto [time, x, y] = pq.top();
            pq.pop();

            // Step 5: Check if destination reached
            if (x == m - 1 && y == n - 1)
            {
                return time;
            }

            // Step 6: Traverse all neighbors
            for (auto &dir : dirs)
            {
                int nx = x + dir[0];
                int ny = y + dir[1];

                // Step 7: Check boundaries
                if (nx >= 0 && nx < m && ny >= 0 && ny < n)
                {
                    // Step 8: Compute wait time if needed
                    int waitTime = max(0, moveTime[nx][ny] - time);
                    int arriveTime = time + 1 + waitTime;

                    // Step 9: Update distance and queue if this path is better
                    if (arriveTime < dist[nx][ny])
                    {
                        dist[nx][ny] = arriveTime;
                        pq.push({arriveTime, nx, ny});
                    }
                }
            }
        }

        // Step 10: If unreachable
        return -1;
    }
};

/*
This code implements Dijkstra's algorithm to find the minimum time required to reach from the top-left room (0,0) to the bottom-right room (n-1, m-1) in a grid of rooms.

The algorithm works as follows:
1. Initialize a distance matrix with maximum values and set starting point distance as 0
2. Use a priority queue to process rooms in order of minimum time
3. For each room, explore all 4 adjacent rooms
4. For each adjacent room, calculate wait time if needed and total arrival time
5. If new arrival time is less than previously known time, update it and add to queue
6. Continue until destination is reached or queue is empty

Key points:
- Uses priority queue for efficient selection of next room to process
- Handles waiting time requirements for each room
- Explores all possible paths to find minimum time
- Returns -1 if destination is unreachable

Time Complexity: O(mn * log(mn)) where m,n are grid dimensions
- Each cell can be processed at most once
- Priority queue operations take log(mn) time

Space Complexity: O(mn)
- Distance matrix: O(mn)
- Priority queue: O(mn) in worst case
*/