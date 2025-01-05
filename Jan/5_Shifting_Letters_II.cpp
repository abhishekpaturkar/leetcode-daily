// 2381. Shifting Letters II

// You are given a string s of lowercase English letters and a 2D integer array shifts where shifts[i] = [starti, endi, directioni]. For every i, shift the characters in s from the index starti to the index endi (inclusive) forward if directioni = 1, or shift the characters backward if directioni = 0.

// Shifting a character forward means replacing it with the next letter in the alphabet (wrapping around so that 'z' becomes 'a'). Similarly, shifting a character backward means replacing it with the previous letter in the alphabet (wrapping around so that 'a' becomes 'z').

// Return the final string after all such shifts to s are applied.

 

// Example 1:

// Input: s = "abc", shifts = [[0,1,0],[1,2,1],[0,2,1]]
// Output: "ace"
// Explanation: Firstly, shift the characters from index 0 to index 1 backward. Now s = "zac".
// Secondly, shift the characters from index 1 to index 2 forward. Now s = "zbd".
// Finally, shift the characters from index 0 to index 2 forward. Now s = "ace".
// Example 2:

// Input: s = "dztz", shifts = [[0,0,0],[1,1,1]]
// Output: "catz"
// Explanation: Firstly, shift the characters from index 0 to index 0 backward. Now s = "cztz".
// Finally, shift the characters from index 1 to index 1 forward. Now s = "catz".
 

// Constraints:

// 1 <= s.length, shifts.length <= 5 * 104
// shifts[i].length == 3
// 0 <= starti <= endi < s.length
// 0 <= directioni <= 1
// s consists of lowercase English letters.

class Solution
{
public:
    string shiftingLetters(string s, vector<vector<int>> &shifts)
    {

        vector<int> v(s.length() + 1, 0);

        for (auto &s : shifts)
        {
            int start = s[0];
            int end = s[1];
            int dir = s[2];

            if (dir == 1)
            {
                v[start] += 1;
                v[end + 1] -= 1;
            }
            else
            {
                v[start] += -1;
                v[end + 1] -= -1;
            }
        }

        int curr = 0;
        for (int i = 0; i < s.length(); i++)
        {
            curr += v[i];
            v[i] = curr;
        }

        for (int i = 0; i < s.length(); i++)
        {
            int cal = (v[i] % 26 + 26) % 26;
            s[i] = 'a' + (s[i] - 'a' + cal) % 26;
        }

        return s;
    }
};

/*
Approach:
1. Line Sweep/Difference Array Technique is used to handle multiple range updates efficiently
2. Create a difference array v of size n+1 initialized with 0
3. For each shift operation:
   - If direction is 1 (forward): Add +1 at start index and -1 at end+1 index
   - If direction is 0 (backward): Add -1 at start index and +1 at end+1 index
4. Calculate prefix sum of difference array to get actual shifts at each position
5. For each character in string:
   - Calculate effective shift after considering cyclic nature (26 letters)
   - Apply the shift to current character using modulo arithmetic
6. Return modified string

Time Complexity: O(n + m) where n is string length and m is number of shifts
Space Complexity: O(n) for difference array

The key insight is using difference array to handle range updates in O(1) time per update
instead of O(range_length) time. The final prefix sum gives cumulative shifts at each position.
*/

