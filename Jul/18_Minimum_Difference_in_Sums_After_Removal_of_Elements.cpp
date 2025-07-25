// 2163. Minimum Difference in Sums After Removal of Elements

// You are given a 0-indexed integer array nums consisting of 3 * n elements.

// You are allowed to remove any subsequence of elements of size exactly n from nums. The remaining 2 * n elements will be divided into two equal parts:

// The first n elements belonging to the first part and their sum is sumfirst.
// The next n elements belonging to the second part and their sum is sumsecond.
// The difference in sums of the two parts is denoted as sumfirst - sumsecond.

// For example, if sumfirst = 3 and sumsecond = 2, their difference is 1.
// Similarly, if sumfirst = 2 and sumsecond = 3, their difference is -1.
// Return the minimum difference possible between the sums of the two parts after the removal of n elements.

 

// Example 1:

// Input: nums = [3,1,2]
// Output: -1
// Explanation: Here, nums has 3 elements, so n = 1. 
// Thus we have to remove 1 element from nums and divide the array into two equal parts.
// - If we remove nums[0] = 3, the array will be [1,2]. The difference in sums of the two parts will be 1 - 2 = -1.
// - If we remove nums[1] = 1, the array will be [3,2]. The difference in sums of the two parts will be 3 - 2 = 1.
// - If we remove nums[2] = 2, the array will be [3,1]. The difference in sums of the two parts will be 3 - 1 = 2.
// The minimum difference between sums of the two parts is min(-1,1,2) = -1. 
// Example 2:

// Input: nums = [7,9,5,8,1,3]
// Output: 1
// Explanation: Here n = 2. So we must remove 2 elements and divide the remaining array into two parts containing two elements each.
// If we remove nums[2] = 5 and nums[3] = 8, the resultant array will be [7,9,1,3]. The difference in sums will be (7+9) - (1+3) = 12.
// To obtain the minimum difference, we should remove nums[1] = 9 and nums[4] = 1. The resultant array becomes [7,5,8,3]. The difference in sums of the two parts is (7+5) - (8+3) = 1.
// It can be shown that it is not possible to obtain a difference smaller than 1.
 

// Constraints:

// nums.length == 3 * n
// 1 <= n <= 105
// 1 <= nums[i] <= 105

class Solution
{
public:
    long long minimumDifference(vector<int> &nums)
    {
        int n = nums.size();
        int k = n / 3;

        vector<long long> leftMins(n), rightMaxs(n);
        priority_queue<int> maxLeftHeap;                             // max-heap for smallest k
        priority_queue<int, vector<int>, greater<int>> minRightHeap; // min-heap for largest k

        long long leftSum = 0, rightSum = 0, minDiff = LLONG_MAX;

        // Build leftMins
        for (int i = 0; i < k; ++i)
        {
            maxLeftHeap.push(nums[i]);
            leftSum += nums[i];
        }
        leftMins[k - 1] = leftSum;

        for (int i = k; i < n - k; ++i)
        {
            if (!maxLeftHeap.empty() && nums[i] < maxLeftHeap.top())
            {
                leftSum += nums[i] - maxLeftHeap.top();
                maxLeftHeap.pop();
                maxLeftHeap.push(nums[i]);
            }
            leftMins[i] = leftSum;
        }

        // Build rightMaxs
        for (int i = n - 1; i >= n - k; --i)
        {
            minRightHeap.push(nums[i]);
            rightSum += nums[i];
        }
        rightMaxs[n - k] = rightSum;

        for (int i = n - k - 1; i >= k - 1; --i)
        {
            if (!minRightHeap.empty() && nums[i] > minRightHeap.top())
            {
                rightSum += nums[i] - minRightHeap.top();
                minRightHeap.pop();
                minRightHeap.push(nums[i]);
            }
            rightMaxs[i] = rightSum;
        }

        // Compute min difference
        for (int i = k - 1; i < n - k; ++i)
        {
            minDiff = min(minDiff, leftMins[i] - rightMaxs[i + 1]);
        }

        return minDiff;
    }
};

/*
This solution uses priority queues (heaps) to efficiently maintain the k smallest elements from the left side and k largest elements from the right side of the array.

The algorithm works in three main steps:
1. Build leftMins array: For each position i, it maintains the sum of k smallest elements from nums[0] to nums[i] using a max heap
2. Build rightMaxs array: For each position i, it maintains the sum of k largest elements from nums[i] to nums[n-1] using a min heap
3. Find minimum difference: Iterate through possible split points and find minimum difference between leftMins[i] and rightMaxs[i+1]

Time Complexity: O(n log k) where n is length of input array
- Building leftMins and rightMaxs takes O(n log k) due to heap operations
- Final minimum difference computation takes O(n)

Space Complexity: O(n)
- leftMins and rightMaxs arrays take O(n) space
- Priority queues take O(k) space
*/