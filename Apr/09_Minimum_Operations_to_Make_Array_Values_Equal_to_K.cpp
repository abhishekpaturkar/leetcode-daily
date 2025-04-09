// 3375. Minimum Operations to Make Array Values Equal to K

// You are given an integer array nums and an integer k.

// An integer h is called valid if all values in the array that are strictly greater than h are identical.

// For example, if nums = [10, 8, 10, 8], a valid integer is h = 9 because all nums[i] > 9 are equal to 10, but 5 is not a valid integer.

// You are allowed to perform the following operation on nums:

// Select an integer h that is valid for the current values in nums.
// For each index i where nums[i] > h, set nums[i] to h.
// Return the minimum number of operations required to make every element in nums equal to k. If it is impossible to make all elements equal to k, return -1.

 

// Example 1:

// Input: nums = [5,2,5,4,5], k = 2

// Output: 2

// Explanation:

// The operations can be performed in order using valid integers 4 and then 2.

// Example 2:

// Input: nums = [2,1,2], k = 2

// Output: -1

// Explanation:

// It is impossible to make all the values equal to 2.

// Example 3:

// Input: nums = [9,7,5,3], k = 1

// Output: 4

// Explanation:

// The operations can be performed using valid integers in the order 7, 5, 3, and 1.

 

// Constraints:

// 1 <= nums.length <= 100 
// 1 <= nums[i] <= 100
// 1 <= k <= 100

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            for (int num : nums) {
                if (num < k) return -1;
            }
    
            sort(nums.begin(), nums.end(), greater<int>());
    
            unordered_set<int> seen;
            for (int num : nums) {
                if (num > k) {
                    seen.insert(num);
                }
            }
    
            return seen.size();
        }
};

/*
Code Explanation:
This solution finds the number of unique elements in the array `nums` that are **strictly greater** than a given value `k`.

1. **Initial Check**:
   - We iterate through each number in `nums`.
   - If any number is **less than** `k`, return `-1` (invalid input based on problem constraint).

2. **Sorting**:
   - We sort the array in **descending order** to process larger elements first.
   - This is optional for correctness, but might be helpful for early exits in some variations.

3. **Tracking Unique Elements**:
   - We use an `unordered_set` to keep track of all elements that are **strictly greater than `k`**.
   - We iterate through the sorted array and insert elements > `k` into the set.

4. **Result**:
   - The size of the `seen` set gives the **number of unique elements greater than `k`**.

Time Complexity: O(n log n) due to sorting  
Space Complexity: O(n) for the unordered_set to store unique elements
*/
