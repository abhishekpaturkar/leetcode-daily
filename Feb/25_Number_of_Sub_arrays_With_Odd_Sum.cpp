// 1524. Number of Sub-arrays With Odd Sum

// Given an array of integers arr, return the number of subarrays with an odd sum.

// Since the answer can be very large, return it modulo 109 + 7.

 
// Example 1:

// Input: arr = [1,3,5]
// Output: 4
// Explanation: All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
// All sub-arrays sum are [1,4,9,3,8,5].
// Odd sums are [1,9,3,5] so the answer is 4.
// Example 2:

// Input: arr = [2,4,6]
// Output: 0
// Explanation: All subarrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
// All sub-arrays sum are [2,6,12,4,10,6].
// All sub-arrays have even sum and the answer is 0.
// Example 3:

// Input: arr = [1,2,3,4,5,6,7]
// Output: 16
 

// Constraints:

// 1 <= arr.length <= 105
// 1 <= arr[i] <= 100

class Solution
{
public:
    int numOfSubarrays(vector<int> &arr)
    {
        long long oddCount = 0, prefixSum = 0;
        for (int a : arr)
        {
            prefixSum += a;
            oddCount += prefixSum % 2;
        }
        oddCount += (arr.size() - oddCount) * oddCount;
        return oddCount % 1'000'000'007;
    }
};

/*
This solution finds subarrays with odd sums using prefix sums:
1. Uses prefixSum to track running sum of elements
2. oddCount keeps track of number of odd prefix sums encountered
3. For each element:
   - Adds it to prefixSum
   - If prefixSum is odd (prefixSum % 2 == 1), increments oddCount
4. Final formula (arr.size() - oddCount) * oddCount calculates total odd subarrays
5. Returns result modulo 10^9 + 7 to handle large numbers
*/