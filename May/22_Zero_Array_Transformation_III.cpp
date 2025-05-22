// 3362. Zero Array Transformation III

// You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri].

// Each queries[i] represents the following action on nums:

// Decrement the value at each index in the range [li, ri] in nums by at most 1.
// The amount by which the value is decremented can be chosen independently for each index.
// A Zero Array is an array with all its elements equal to 0.

// Return the maximum number of elements that can be removed from queries, such that nums can still be converted to a zero array using the remaining queries. If it is not possible to convert nums to a zero array, return -1.

 

// Example 1:

// Input: nums = [2,0,2], queries = [[0,2],[0,2],[1,1]]

// Output: 1

// Explanation:

// After removing queries[2], nums can still be converted to a zero array.

// Using queries[0], decrement nums[0] and nums[2] by 1 and nums[1] by 0.
// Using queries[1], decrement nums[0] and nums[2] by 1 and nums[1] by 0.
// Example 2:

// Input: nums = [1,1,1,1], queries = [[1,3],[0,2],[1,3],[1,2]]

// Output: 2

// Explanation:

// We can remove queries[2] and queries[3].

// Example 3:

// Input: nums = [1,2,3,4], queries = [[0,3]]

// Output: -1

// Explanation:

// nums cannot be converted to a zero array even after using all the queries.

 

// Constraints:

// 1 <= nums.length <= 105
// 0 <= nums[i] <= 105
// 1 <= queries.length <= 105
// queries[i].length == 2
// 0 <= li <= ri < nums.length

class Solution
{
public:
    static int maxRemoval(vector<int> &nums, vector<vector<int>> &queries)
    {
        const int n = nums.size(), qz = queries.size();
        vector<vector<int>> qEnd(n);
        for (int i = 0; i < qz; i++)
        {
            qEnd[queries[i][0]].push_back(queries[i][1]);
        }
        priority_queue<int> pq;
        vector<int> cntQ(n + 1, 0);
        int dec = 0;
        for (int i = 0, j = 0; i < n; i++)
        {
            const int x = nums[i];
            dec += cntQ[i];
            for (int j : qEnd[i])
                pq.push(j);
            int k;
            for (; x > dec && pq.size() > 0 && (k = pq.top()) >= i; dec++)
            {
                cntQ[k + 1]--;
                pq.pop();
            }
            if (x > dec)
                return -1;
        }
        return pq.size();
    }
};

/*
This code solves the problem of finding the maximum number of queries that can be removed while still being able to convert an array to a zero array.

The algorithm works as follows:
1. Create a vector qEnd to store the end indices of queries starting at each index
2. Process array from left to right, keeping track of decrements (dec)
3. For each position i:
   - Add accumulated decrements
   - Add all queries starting at i to priority queue
   - While current value > decrements and queries available:
     - Use query with largest end point
     - Update decrements and counters
4. If can't make current element 0, return -1
5. Return remaining unused queries

Time Complexity: O(N * log Q) where N is array length and Q is number of queries
Space Complexity: O(N + Q) for the qEnd vector and priority queue
*/