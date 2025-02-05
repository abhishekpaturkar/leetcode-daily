// 1790. Check if One String Swap Can Make Strings Equal
// Solved
// Easy
// Topics
// Companies
// Hint
// You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.

// Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.

 

// Example 1:

// Input: s1 = "bank", s2 = "kanb"
// Output: true
// Explanation: For example, swap the first character with the last character of s2 to make "bank".
// Example 2:

// Input: s1 = "attack", s2 = "defend"
// Output: false
// Explanation: It is impossible to make them equal with one string swap.
// Example 3:

// Input: s1 = "kelb", s2 = "kelb"
// Output: true
// Explanation: The two strings are already equal, so no string swap operation is required.
 

// Constraints:

// 1 <= s1.length, s2.length <= 100
// s1.length == s2.length
// s1 and s2 consist of only lowercase English letters.

class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        if (s1 == s2)
            return true;

        vector<int> diff;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
            {
                diff.push_back(i);
            }

            if (diff.size() > 2)
                return false;
        }

        return diff.size() == 2 && s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]];
    }
};

/*
This code checks if two strings can be made equal by performing at most one swap operation:
1. First checks if strings are already equal - returns true if they are
2. Creates a vector 'diff' to store indices where characters differ
3. Iterates through both strings comparing characters
4. When characters differ, stores that index in diff vector
5. If more than 2 differences found, returns false (can't make equal with one swap)
6. Finally checks if:
   - Exactly 2 differences were found
   - Characters at those positions can be swapped to make strings equal
   - Returns true only if all conditions are met
*/