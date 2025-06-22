// 2138. Divide a String Into Groups of Size k

// A string s can be partitioned into groups of size k using the following procedure:

// The first group consists of the first k characters of the string, the second group consists of the next k characters of the string, and so on. Each element can be a part of exactly one group.
// For the last group, if the string does not have k characters remaining, a character fill is used to complete the group.
// Note that the partition is done so that after removing the fill character from the last group (if it exists) and concatenating all the groups in order, the resultant string should be s.

// Given the string s, the size of each group k and the character fill, return a string array denoting the composition of every group s has been divided into, using the above procedure.

 

// Example 1:

// Input: s = "abcdefghi", k = 3, fill = "x"
// Output: ["abc","def","ghi"]
// Explanation:
// The first 3 characters "abc" form the first group.
// The next 3 characters "def" form the second group.
// The last 3 characters "ghi" form the third group.
// Since all groups can be completely filled by characters from the string, we do not need to use fill.
// Thus, the groups formed are "abc", "def", and "ghi".
// Example 2:

// Input: s = "abcdefghij", k = 3, fill = "x"
// Output: ["abc","def","ghi","jxx"]
// Explanation:
// Similar to the previous example, we are forming the first three groups "abc", "def", and "ghi".
// For the last group, we can only use the character 'j' from the string. To complete this group, we add 'x' twice.
// Thus, the 4 groups formed are "abc", "def", "ghi", and "jxx".
 

// Constraints:

// 1 <= s.length <= 100
// s consists of lowercase English letters only.
// 1 <= k <= 100
// fill is a lowercase English letter.

class Solution
{
public:
    vector<string> divideString(string s, int k, char fill)
    {
        int n = s.size();
        int groups = (n + k - 1) / k;
        vector<string> result(groups);

        for (int i = 0; i < groups; i++)
        {
            string group;
            for (int j = 0; j < k; j++)
            {
                int index = i * k + j;
                if (index < n)
                {
                    group += s[index];
                }
                else
                {
                    group += fill; // Padding
                }
            }
            result[i] = group;
        }

        return result;
    }
};

/*
Code explanation:
This code divides a string into groups of size k and fills the last group with a specified character if needed.

1. Calculate total number of groups needed: (n + k - 1) / k
   - This formula rounds up the division to handle partial groups

2. Create result vector to store all groups

3. Outer loop iterates through each group
   Inner loop builds each group of size k:
   - If character exists in original string, add it
   - If we run out of characters, pad with fill character

4. Store completed group in result vector

Time Complexity: O(n) where n is string length
Space Complexity: O(n) for storing result
*/