// 2131. Longest Palindrome by Concatenating Two Letter Words

// You are given an array of strings words. Each element of words consists of two lowercase English letters.

// Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.

// Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.

// A palindrome is a string that reads the same forward and backward.

 
// Example 1:

// Input: words = ["lc","cl","gg"]
// Output: 6
// Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
// Note that "clgglc" is another longest palindrome that can be created.
// Example 2:

// Input: words = ["ab","ty","yt","lc","cl","ab"]
// Output: 8
// Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
// Note that "lcyttycl" is another longest palindrome that can be created.
// Example 3:

// Input: words = ["cc","ll","xx"]
// Output: 2
// Explanation: One longest palindrome is "cc", of length 2.
// Note that "ll" is another longest palindrome that can be created, and so is "xx".
 

// Constraints:

// 1 <= words.length <= 105
// words[i].length == 2
// words[i] consists of lowercase English letters.

class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        unordered_map<string, int> mpp;
        for (string w : words)
            mpp[w]++;

        int count = 0, alreadyPalindrome = 0;
        for (auto &[w, freq] : mpp)
        {
            string s = w;
            reverse(s.begin(), s.end());
            if (w == s)
            {
                count += (freq / 2) * 4;
                if (freq % 2)
                    alreadyPalindrome = 1;
            }
            else if (w < s && mpp.count(s))
            {
                count += min(freq, mpp[s]) * 4;
            }
        }
        return count + alreadyPalindrome * 2;
    }
};

/*
Code Explanation:
This solution finds the longest palindrome that can be created by concatenating two-letter words. Here's how it works:

1. First, it creates a frequency map (mpp) to store the count of each word.

2. Then it iterates through each unique word in the map and:
   - Creates a reversed version of the current word
   - Handles two cases:
     a) If word is a palindrome itself (like "gg"):
        - Adds pairs of such words to result (freq/2 * 4)
        - If there's an extra palindrome word, marks it for center position
     b) If word has a matching reverse word (like "lc" and "cl"):
        - Adds the minimum frequency of both words * 4 to result

3. Finally returns total count plus 2 if there's an unused palindrome word for center

Time Complexity: O(N), where N is the number of words
Space Complexity: O(N) for storing the frequency map

*/