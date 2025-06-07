// 3170. Lexicographically Minimum String After Removing Stars

// You are given a string s. It may contain any number of '*' characters. Your task is to remove all '*' characters.

// While there is a '*', do the following operation:

// Delete the leftmost '*' and the smallest non-'*' character to its left. If there are several smallest characters, you can delete any of them.
// Return the lexicographically smallest resulting string after removing all '*' characters.

 

// Example 1:

// Input: s = "aaba*"

// Output: "aab"

// Explanation:

// We should delete one of the 'a' characters with '*'. If we choose s[3], s becomes the lexicographically smallest.

// Example 2:

// Input: s = "abc"

// Output: "abc"

// Explanation:

// There is no '*' in the string.

 

// Constraints:

// 1 <= s.length <= 105
// s consists only of lowercase English letters and '*'.
// The input is generated such that it is possible to delete all '*' characters.

class Solution
{
public:
    string clearStars(string s)
    {
        vector<vector<int>> pos(26);
        priority_queue<char, vector<char>, greater<char>> pq;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '*')
            {
                char c = pq.top();
                s[pos[c - 'a'].back()] = '*';
                pos[c - 'a'].pop_back();
                if (pos[c - 'a'].empty())
                    pq.pop();
            }
            else
            {
                if (pos[s[i] - 'a'].empty())
                    pq.push(s[i]);
                pos[s[i] - 'a'].push_back(i);
            }
        }
        string res;
        for (char c : s)
            if (c >= 'a')
                res += c;
        return res;
    }
};

/*
Code Explanation:
1. We create a vector of vectors 'pos' to store positions of each character (a-z).
2. Use min heap priority queue to always get smallest character.
3. Iterate through string:
   - If '*' found: Get smallest char from pq, mark its leftmost position as '*', update positions
   - If letter found: Store its position and add to pq if first occurrence
4. Finally create result string with remaining non-'*' characters

Time Complexity: O(n log k) where n is string length, k is unique characters
Space Complexity: O(n) for storing positions and priority queue
*/