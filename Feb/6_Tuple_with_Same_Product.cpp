// 1726. Tuple with Same Product
// Solved
// Medium
// Topics
// Companies
// Hint
// Given an array nums of distinct positive integers, return the number of tuples (a, b, c, d) such that a * b = c * d where a, b, c, and d are elements of nums, and a != b != c != d.


// Example 1:

// Input: nums = [2,3,4,6]
// Output: 8
// Explanation: There are 8 valid tuples:
// (2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
// (3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)
// Example 2:

// Input: nums = [1,2,4,5,10]
// Output: 16
// Explanation: There are 16 valid tuples:
// (1,10,2,5) , (1,10,5,2) , (10,1,2,5) , (10,1,5,2)
// (2,5,1,10) , (2,5,10,1) , (5,2,1,10) , (5,2,10,1)
// (2,10,4,5) , (2,10,5,4) , (10,2,4,5) , (10,2,5,4)
// (4,5,2,10) , (4,5,10,2) , (5,4,2,10) , (5,4,10,2)
 

// Constraints:

// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 104
// All elements in nums are distinct.

class Solution
{
public:
    int tupleSameProduct(vector<int> &nums)
    {
        const int n = nums.size();
        unordered_map<int, int> freq;
        freq.reserve(n * (n - 1) / 2);

        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                freq[nums[i] * nums[j]]++;

        int ans = 0;

        for (auto &[x, f] : freq)
        {
            if (f > 1)
                ans += f * (f - 1) * 4;
        }
        return ans;
    }
};

/*
This code solves the problem of finding valid tuples (a,b,c,d) where a*b = c*d. Here's how it works:

1. We create a frequency map to store products of all possible pairs of numbers
2. Using nested loops, we calculate product of each unique pair (nums[i] * nums[j]) and store its frequency
3. For each product frequency (f) greater than 1:
   - f represents number of pairs that give same product
   - f*(f-1) gives number of ways to choose 2 different pairs
   - Multiply by 4 because each pair can be arranged in 4 ways
4. Sum up all possibilities to get final answer

Time Complexity: O(n^2)
Space Complexity: O(n^2)
*/