// 1980. Find Unique Binary String

// Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.

 

// Example 1:

// Input: nums = ["01","10"]
// Output: "11"
// Explanation: "11" does not appear in nums. "00" would also be correct.
// Example 2:

// Input: nums = ["00","01"]
// Output: "11"
// Explanation: "11" does not appear in nums. "10" would also be correct.
// Example 3:

// Input: nums = ["111","011","001"]
// Output: "101"
// Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.
 

// Constraints:

// n == nums.length
// 1 <= n <= 16
// nums[i].length == n
// nums[i] is either '0' or '1'.
// All the strings of nums are unique.

class Solution
{
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        string ans = "";
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i][i] == '0')
            {
                ans += '1';
            }
            else
            {
                ans += '0';
            }
        }
        return ans;
    }
};

/*
This solution uses Cantor's Diagonalization method to find a binary string that differs from all given strings in nums:
1. It constructs a new string by looking at the diagonal elements (where row index equals column index)
2. For each diagonal element, it chooses the opposite bit (0 becomes 1, 1 becomes 0)
3. This guarantees the result will differ from every string in nums in at least one position
4. Time complexity is O(n) where n is the length of nums
5. Space complexity is O(n) for storing the answer string
*/