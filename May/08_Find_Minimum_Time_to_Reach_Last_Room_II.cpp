// 3342. Find Minimum Time to Reach Last Room II

// There is a dungeon with n x m rooms arranged as a grid.

// You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds when you can start moving to that room. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving between adjacent rooms takes one second for one move and two seconds for the next, alternating between the two.

// Return the minimum time to reach the room (n - 1, m - 1).

// Two rooms are adjacent if they share a common wall, either horizontally or vertically.

 

// Example 1:

// Input: moveTime = [[0,4],[4,4]]

// Output: 7

// Explanation:

// The minimum time required is 7 seconds.

// At time t == 4, move from room (0, 0) to room (1, 0) in one second.
// At time t == 5, move from room (1, 0) to room (1, 1) in two seconds.
// Example 2:

// Input: moveTime = [[0,0,0,0],[0,0,0,0]]

// Output: 6

// Explanation:

// The minimum time required is 6 seconds.

// At time t == 0, move from room (0, 0) to room (1, 0) in one second.
// At time t == 1, move from room (1, 0) to room (1, 1) in two seconds.
// At time t == 3, move from room (1, 1) to room (1, 2) in one second.
// At time t == 4, move from room (1, 2) to room (1, 3) in two seconds.
// Example 3:

// Input: moveTime = [[0,1],[1,2]]

// Output: 4

// Constraints:

// 2 <= n == moveTime.length <= 750
// 2 <= m == moveTime[i].length <= 750
// 0 <= moveTime[i][j] <= 109

using namespace std;

struct Pair
{
    int steps, i, j, move;
    Pair(int steps, int i, int j, int move) : steps(steps), i(i), j(j), move(move) {}
    bool operator>(const Pair &other) const
    {
        return steps > other.steps;
    }
};

class Solution
{
public:
    static int minTimeToReach(vector<vector<int>> &moveTime)
    {
        int r = moveTime.size(), c = moveTime[0].size();
        vector<vector<int>> minimumTime(r, vector<int>(c, INT_MAX));
        priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

        pq.emplace(-1, 0, 0, 1);
        minimumTime[0][0] = 0;

        while (!pq.empty())
        {
            Pair top = pq.top();
            pq.pop();
            int i = top.i, j = top.j, move = top.move, nextStep = top.steps;

            if (i + 1 < r)
                update(i + 1, j, pq, nextStep, moveTime, minimumTime, move);
            if (i - 1 >= 0)
                update(i - 1, j, pq, nextStep, moveTime, minimumTime, move);
            if (j + 1 < c)
                update(i, j + 1, pq, nextStep, moveTime, minimumTime, move);
            if (j - 1 >= 0)
                update(i, j - 1, pq, nextStep, moveTime, minimumTime, move);

            if (minimumTime[r - 1][c - 1] != INT_MAX)
                return minimumTime[r - 1][c - 1];
        }
        return -1;
    }

private:
    static void update(int i, int j, priority_queue<Pair, vector<Pair>, greater<Pair>> &pq, int nextStep, vector<vector<int>> &moveTime, vector<vector<int>> &minimumTime, int move)
    {
        nextStep = move + max(nextStep, moveTime[i][j]);
        if (minimumTime[i][j] > nextStep)
        {
            pq.emplace(nextStep, i, j, move == 1 ? 2 : 1);
            minimumTime[i][j] = nextStep;
        }
    }
};

/*
This code solves the problem of finding the minimum time to reach the bottom-right room in a grid-based dungeon. Here's how it works:

1. The Pair struct holds information about each state: steps taken, current position (i,j), and current move cost.

2. The minTimeToReach function uses Dijkstra's algorithm with a priority queue to find the shortest path:
   - Initializes a grid to track minimum times to reach each cell
   - Starts from (0,0) with initial move cost of 1
   - Explores adjacent rooms using alternating move costs (1 and 2)
   - Updates minimum times when a better path is found

3. The update helper function:
   - Calculates the next step time considering move cost and room's minimum time requirement
   - Updates the minimum time if a better path is found
   - Adds the new state to the priority queue

Time Complexity: O(mn * log(mn)) where m,n are grid dimensions
- Priority queue operations take O(log(mn))
- Each cell can be visited multiple times

Space Complexity: O(mn)
- Priority queue and minimum time grid both use O(mn) space
*/