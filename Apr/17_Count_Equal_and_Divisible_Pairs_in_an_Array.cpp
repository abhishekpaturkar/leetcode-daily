// 2176. Count Equal and Divisible Pairs in an Array

// Given a 0-indexed integer array nums of length n and an integer k, return the number of pairs (i, j) where 0 <= i < j < n, such that nums[i] == nums[j] and (i * j) is divisible by k.
 

// Example 1:

// Input: nums = [3,1,2,2,2,1,3], k = 2
// Output: 4
// Explanation:
// There are 4 pairs that meet all the requirements:
// - nums[0] == nums[6], and 0 * 6 == 0, which is divisible by 2.
// - nums[2] == nums[3], and 2 * 3 == 6, which is divisible by 2.
// - nums[2] == nums[4], and 2 * 4 == 8, which is divisible by 2.
// - nums[3] == nums[4], and 3 * 4 == 12, which is divisible by 2.
// Example 2:

// Input: nums = [1,2,3,4], k = 1
// Output: 0
// Explanation: Since no value in nums is repeated, there are no pairs (i,j) that meet all the requirements.
 

// Constraints:

// 1 <= nums.length <= 100
// 1 <= nums[i], k <= 100

class Solution
{
public:
    static int countPairs(vector<int> &nums, int k)
    {
        const int n = nums.size();
        vector<char> freq[101];
        for (int i = 0; i < n; i++)
        {
            int x = nums[i];
            freq[x].push_back(i);
        }
        int cnt = 0;
        for (auto &fs : freq)
        {
            if (fs.size() < 2)
                continue;
            int fz = fs.size();
            for (int i = 0; i < fz - 1; i++)
                for (int j = i + 1; j < fz; j++)
                    cnt += (fs[i] * fs[j] % k == 0);
        }
        return cnt;
    }
};

/*
Code Explanation:
This solution finds pairs of equal elements whose indices product is divisible by k.
1. Create an array of vectors 'freq' to store indices of each number
2. Iterate through input array and store indices in corresponding freq vector
3. For each number that appears at least twice:
   - Get all pairs of indices using nested loops
   - Check if product of indices is divisible by k
   - Increment counter for valid pairs
4. Return total count of valid pairs

Time Complexity: O(n^2) in worst case where all elements are same
Space Complexity: O(n) to store indices in freq array
*/