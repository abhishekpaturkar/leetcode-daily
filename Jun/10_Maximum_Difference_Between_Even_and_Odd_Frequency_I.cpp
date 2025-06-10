// 3442. Maximum Difference Between Even and Odd Frequency I

// You are given a string s consisting of lowercase English letters.

// Your task is to find the maximum difference diff = freq(a1) - freq(a2) between the frequency of characters a1 and a2 in the string such that:

// a1 has an odd frequency in the string.
// a2 has an even frequency in the string.
// Return this maximum difference.

 

// Example 1:

// Input: s = "aaaaabbc"

// Output: 3

// Explanation:

// The character 'a' has an odd frequency of 5, and 'b' has an even frequency of 2.
// The maximum difference is 5 - 2 = 3.
// Example 2:

// Input: s = "abcabcab"

// Output: 1

// Explanation:

// The character 'a' has an odd frequency of 3, and 'c' has an even frequency of 2.
// The maximum difference is 3 - 2 = 1.
 

// Constraints:

// 3 <= s.length <= 100
// s consists only of lowercase English letters.
// s contains at least one character with an odd frequency and one with an even frequency.

class Solution
{
public:
    int maxDifference(string s)
    {
        vector<int> mpp(26);
        int maxi = 0, mini = s.size();
        for (char c : s)
            mpp[c - 'a']++;
        for (int i = 0; i < 26; i++)
        {
            if (mpp[i] % 2 != 0)
                maxi = max(maxi, mpp[i]);
            if (mpp[i] % 2 == 0 && mpp[i] > 0)
                mini = min(mini, mpp[i]);
        }
        return maxi - mini;
    }
};

/*
Code Explanation:
This solution finds the maximum difference between odd and even frequency characters in a string.
1. Create a frequency array 'mpp' of size 26 to store count of each character
2. Initialize maxi=0 and mini=string length
3. Count frequency of each character in string using mpp array
4. Iterate through mpp array:
   - If frequency is odd, update maxi if current frequency is larger
   - If frequency is even and >0, update mini if current frequency is smaller
5. Return difference between maxi and mini

Time Complexity: O(n) where n is length of string
Space Complexity: O(1) as we use fixed size array of 26 characters
*/