// 2127. Maximum Employees to Be Invited to a Meeting

// A company is organizing a meeting and has a list of n employees, waiting to be invited. They have arranged for a large circular table, capable of seating any number of employees.

// The employees are numbered from 0 to n - 1. Each employee has a favorite person and they will attend the meeting only if they can sit next to their favorite person at the table. The favorite person of an employee is not themself.

// Given a 0-indexed integer array favorite, where favorite[i] denotes the favorite person of the ith employee, return the maximum number of employees that can be invited to the meeting.

// Example 1:

// Input: favorite = [2,2,1,2]
// Output: 3
// Explanation:
// The above figure shows how the company can invite employees 0, 1, and 2, and seat them at the round table.
// All employees cannot be invited because employee 2 cannot sit beside employees 0, 1, and 3, simultaneously.
// Note that the company can also invite employees 1, 2, and 3, and give them their desired seats.
// The maximum number of employees that can be invited to the meeting is 3.
// Example 2:

// Input: favorite = [1,2,0]
// Output: 3
// Explanation:
// Each employee is the favorite person of at least one other employee, and the only way the company can invite them is if they invite every employee.
// The seating arrangement will be the same as that in the figure given in example 1:
// - Employee 0 will sit between employees 2 and 1.
// - Employee 1 will sit between employees 0 and 2.
// - Employee 2 will sit between employees 1 and 0.
// The maximum number of employees that can be invited to the meeting is 3.
// Example 3:

// Input: favorite = [3,0,1,4,1]
// Output: 4
// Explanation:
// The above figure shows how the company will invite employees 0, 1, 3, and 4, and seat them at the round table.
// Employee 2 cannot be invited because the two spots next to their favorite employee 1 are taken.
// So the company leaves them out of the meeting.
// The maximum number of employees that can be invited to the meeting is 4.

// Constraints:

// n == favorite.length
// 2 <= n <= 105
// 0 <= favorite[i] <= n - 1
// favorite[i] != i

class Solution
{
public:
    int maximumInvitations(vector<int> &fav)
    {
        int n = fav.size(), maxCycle = 0, pairChains = 0;
        queue<int> q;                      // Handles employees not in cycles
        vector<bool> vis(n);               // Tracks processed employees
        vector<int> inDeg(n), chainLen(n); // inDeg: favorite counts; chainLen: longest chain to each

        // Step 1: Calculate how many people favor each employee
        for (int x : fav)
            inDeg[x]++;

        // Step 2: Start with employees no one favorites (chain starters)
        for (int i = 0; i < n; ++i)
            if (!inDeg[i])
                q.push(i);

        // Step 3: Process chain starters to find longest chains
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            vis[u] = true;                                       // Mark as processed
            int nbr = fav[u];                                    // u's favorite
            chainLen[nbr] = max(chainLen[nbr], chainLen[u] + 1); // Update chain length
            if (--inDeg[nbr] == 0)
                q.push(nbr); // Process when all dependents are handled
        }

        // Step 4: Check remaining employees for cycles
        for (int i = 0; i < n; ++i)
        {
            if (vis[i])
                continue; // Already processed in chains

            int cycleLen = 0, u = i;
            // Measure cycle length
            while (!vis[u])
            {
                vis[u] = true;
                u = fav[u];
                cycleLen++;
            }

            // Handle mutual pairs (cycle of 2) with their chains
            if (cycleLen == 2)
                pairChains += 2 + chainLen[i] + chainLen[fav[i]];
            // Track longest non-pair cycle
            else
                maxCycle = max(maxCycle, cycleLen);
        }

        // Choose best option: largest cycle or mutual pairs with chains
        return max(maxCycle, pairChains);
    }
};

/*
This code solves the problem of finding the maximum number of employees that can be invited to a meeting with seating constraints. Here's how it works:

1. The code uses a topological sort-like approach to handle both cycles and chains in the favorite relationships.

2. Data structures used:
   - inDeg: Counts how many people have each person as their favorite
   - chainLen: Tracks the longest chain ending at each person
   - vis: Marks which employees have been processed
   - q: Queue for processing employees with no incoming favorites

3. The algorithm has four main steps:
   a) Count incoming favorites for each person
   b) Identify and queue employees that no one favorites
   c) Process chains starting from these employees
   d) Handle remaining employees in cycles

4. For cycles, it handles two cases differently:
   - Two-person mutual pairs: Adds their chain lengths to the pair
   - Larger cycles: Tracks the longest cycle found

5. The final result is the maximum of:
   - The longest cycle length
   - The sum of all pair combinations with their chains

This solution efficiently handles both circular arrangements and chain arrangements to find the maximum possible meeting size.
*/