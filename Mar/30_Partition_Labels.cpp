// 763. Partition Labels

// You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part. For example, the string "ababcc" can be partitioned into ["abab", "cc"], but partitions such as ["aba", "bcc"] or ["ab", "ab", "cc"] are invalid.

// Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

// Return a list of integers representing the size of these parts.

// Example 1:

// Input: s = "ababcbacadefegdehijhklij"
// Output: [9,7,8]
// Explanation:
// The partition is "ababcbaca", "defegde", "hijhklij".
// This is a partition so that each letter appears in at most one part.
// A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
// Example 2:

// Input: s = "eccbbbbdec"
// Output: [10]

// Constraints:

// 1 <= s.length <= 500
// s consists of lowercase English letters.

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        unordered_map<char, int> last_occurrence;
        for (int i = 0; i < s.size(); i++)
        {
            last_occurrence[s[i]] = i;
        }

        vector<int> result;
        int start = 0, end = 0;

        for (int i = 0; i < s.size(); i++)
        {
            end = max(end, last_occurrence[s[i]]);
            if (i == end)
            {
                result.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return result;
    }
};

/*
1. Create a map to store the last occurrence of each character
2. Iterate through the string
3. For each position, update the end boundary of the current partition based on the last occurrence of the current character
4. If we've reached the end boundary of our current partition, it means we've included all necessary characters for this partition, so we add its length to our result

Complexity
Time complexity: O(n), where n is the length of the string
Space complexity: O(k), where k is the number of unique characters in the string
*/