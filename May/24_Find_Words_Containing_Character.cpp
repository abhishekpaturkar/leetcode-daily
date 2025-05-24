// 2942. Find Words Containing Character
// Easy
// Topics
// Companies
// Hint
// You are given a 0-indexed array of strings words and a character x.

// Return an array of indices representing the words that contain the character x.

// Note that the returned array may be in any order.

 

// Example 1:

// Input: words = ["leet","code"], x = "e"
// Output: [0,1]
// Explanation: "e" occurs in both words: "leet", and "code". Hence, we return indices 0 and 1.
// Example 2:

// Input: words = ["abc","bcd","aaaa","cbc"], x = "a"
// Output: [0,2]
// Explanation: "a" occurs in "abc", and "aaaa". Hence, we return indices 0 and 2.
// Example 3:

// Input: words = ["abc","bcd","aaaa","cbc"], x = "z"
// Output: []
// Explanation: "z" does not occur in any of the words. Hence, we return an empty array.
 

// Constraints:

// 1 <= words.length <= 50
// 1 <= words[i].length <= 50
// x is a lowercase English letter.
// words[i] consists only of lowercase English letters.

class Solution
{
public:
    vector<int> findWordsContaining(vector<string> &words, char x)
    {
        vector<int> ans;

        for (int i = 0; i < words.size(); i++)
        {
            string word = words[i];
            for (int j = 0; j < word.length(); j++)
            {
                if (word[j] == x)
                {
                    ans.push_back(i);
                    break;
                }
            }
        }

        return ans;
    }
};

/*
Code Explanation:
This code finds indices of words containing a specific character 'x' in a given array of strings.
1. Takes a vector of strings 'words' and character 'x' as input
2. Creates empty vector 'ans' to store indices
3. Iterates through each word in 'words' array
4. For each word, checks each character
5. If character matches 'x', adds word's index to 'ans' and breaks inner loop
6. Returns vector containing all matching indices

Time Complexity: O(N * M) where N is number of words and M is average length of words
Space Complexity: O(K) where K is number of words containing character 'x'
*/