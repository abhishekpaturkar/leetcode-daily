// 3066. Minimum Operations to Exceed Threshold Value II

// You are given a 0-indexed integer array nums, and an integer k.

// In one operation, you will:

// Take the two smallest integers x and y in nums.
// Remove x and y from nums.
// Add min(x, y) * 2 + max(x, y) anywhere in the array.
// Note that you can only apply the described operation if nums contains at least two elements.

// Return the minimum number of operations needed so that all elements of the array are greater than or equal to k.

// Example 1:

// Input: nums = [2,11,10,1,3], k = 10
// Output: 2
// Explanation: In the first operation, we remove elements 1 and 2, then add 1 * 2 + 2 to nums. nums becomes equal to [4, 11, 10, 3].
// In the second operation, we remove elements 3 and 4, then add 3 * 2 + 4 to nums. nums becomes equal to [10, 11, 10].
// At this stage, all the elements of nums are greater than or equal to 10 so we can stop.
// It can be shown that 2 is the minimum number of operations needed so that all elements of the array are greater than or equal to 10.
// Example 2:

// Input: nums = [1,1,2,4,9], k = 20
// Output: 4
// Explanation: After one operation, nums becomes equal to [2, 4, 9, 3].
// After two operations, nums becomes equal to [7, 4, 9].
// After three operations, nums becomes equal to [15, 9].
// After four operations, nums becomes equal to [33].
// At this stage, all the elements of nums are greater than 20 so we can stop.
// It can be shown that 4 is the minimum number of operations needed so that all elements of the array are greater than or equal to 20.

// Constraints:

// 2 <= nums.length <= 2 * 105
// 1 <= nums[i] <= 109
// 1 <= k <= 109
// The input is generated such that an answer always exists. That is, there exists some sequence of operations after which all elements of the array are greater than or equal to k.

class Solution
{
public:
    int minOperations(vector<int> &a, int k)
    {
        priority_queue<int, vector<int>, greater<int>> q(a.begin(), a.end());
        for (int i = 0, x, y;; ++i)
        {
            x = q.top();
            q.pop();
            if (x >= k)
                return i;
            y = q.top();
            q.pop();
            const long t = 2L * x + y; // test overflow
            q.push(t < k ? (int)t : k);
        }
        return -1;
    }
};

/*
This code solves the problem of finding minimum operations to make all array elements >= k:
1. Creates a min-heap priority queue with input array elements
2. In each iteration:
   - Takes out smallest element x
   - If x >= k, returns number of operations done
   - Takes out next smallest element y 
   - Calculates new value as 2*x + y
   - Pushes new value back to queue (capped at k if exceeds k)
3. Continues until all elements >= k
4. Uses long to handle potential integer overflow
5. Returns -1 if no solution found (though problem guarantees solution exists)
*/