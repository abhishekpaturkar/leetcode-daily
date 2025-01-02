// 2559. Count Vowel Strings in Ranges
// Medium
// Topics
// Companies
// Hint
// You are given a 0-indexed array of strings words and a 2D array of integers queries.

// Each query queries[i] = [li, ri] asks us to find the number of strings present in the range li to ri (both inclusive) of words that start and end with a vowel.

// Return an array ans of size queries.length, where ans[i] is the answer to the ith query.

// Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.

// Example 1:

// Input: words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
// Output: [2,3,0]
// Explanation: The strings starting and ending with a vowel are "aba", "ece", "aa" and "e".
// The answer to the query [0,2] is 2 (strings "aba" and "ece").
// to query [1,4] is 3 (strings "ece", "aa", "e").
// to query [1,1] is 0.
// We return [2,3,0].
// Example 2:

// Input: words = ["a","e","i"], queries = [[0,2],[0,1],[2,2]]
// Output: [3,2,1]
// Explanation: Every string satisfies the conditions, so we return [3,2,1].

// Constraints:

// 1 <= words.length <= 105
// 1 <= words[i].length <= 40
// words[i] consists only of lowercase English letters.
// sum(words[i].length) <= 3 * 105
// 1 <= queries.length <= 105
// 0 <= li <= ri < words.length

class Solution
{
public:
    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
    {
        int n = words.size();
        vector<int> Prefix(n + 1, 0);
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < n; i++)
        {
            Prefix[i + 1] = Prefix[i];
            if (vowels.count(words[i].front()) && vowels.count(words[i].back()))
            {
                Prefix[i + 1]++;
            }
        }
        vector<int> ANS;
        for (auto &query : queries)
        {
            int L = query[0], R = query[1];
            ANS.push_back(Prefix[R + 1] - Prefix[L]);
        }

        return ANS;
    }
};

/*
This code solves the problem of counting vowel strings in given ranges:
1. Creates a prefix sum array to store count of valid strings (starting and ending with vowels)
2. Uses unordered_set to store vowels for O(1) lookup
3. Iterates through words to build prefix sum:
   - Each element stores sum of valid strings up to that index
   - Checks if word starts and ends with vowel using front() and back()
4. Processes queries using prefix sum array:
   - For each query [L,R], calculates count using Prefix[R+1] - Prefix[L]
5. Returns array of answers for all queries
Time Complexity: O(n + q) where n = words length, q = queries length
Space Complexity: O(n) for prefix array
*/