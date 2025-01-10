// 916. Word Subsets

// You are given two string arrays words1 and words2.

// A string b is a subset of string a if every letter in b occurs in a including multiplicity.

// For example, "wrr" is a subset of "warrior" but is not a subset of "world".
// A string a from words1 is universal if for every string b in words2, b is a subset of a.

// Return an array of all the universal strings in words1. You may return the answer in any order.

 

// Example 1:

// Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
// Output: ["facebook","google","leetcode"]
// Example 2:

// Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["l","e"]
// Output: ["apple","google","leetcode"]
 

// Constraints:

// 1 <= words1.length, words2.length <= 104
// 1 <= words1[i].length, words2[i].length <= 10
// words1[i] and words2[i] consist only of lowercase English letters.
// All the strings of words1 are unique.

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> freq(26, 0);

        for(auto& w : words2) {
            vector<int> temp(26, 0);
            for(char c : w) {
                temp[c - 'a']++;
            }

            for(int i = 0; i < 26; i++) {
                freq[i] = max(freq[i], temp[i]);
            }
        }

        vector<string> res;
        for(auto& w : words1) {
            vector<int> temp(26, 0);
            for(char c : w) {
                temp[c - 'a']++;
            }
            int i;
            for(i = 0; i < 26; i++) {
                if(temp[i] < freq[i]) {
                    break;
                }
            }
            if(i == 26) {
                res.push_back(w);
            }
        } 
        return res;
    }
};

/*
This code solves the Word Subsets problem. Here's how it works:

1. First, it creates a frequency array 'freq' to store the maximum frequency of each character required from words2.

2. For each word in words2:
   - Creates a temporary frequency array for current word
   - Counts frequency of each character in current word
   - Updates the main frequency array with maximum values

3. Then for each word in words1:
   - Creates a frequency array for current word
   - Checks if this word has enough of each character to satisfy the requirements
   - If all requirements are met (loop reaches 26), adds word to result

4. Finally returns the array of universal strings

The solution uses character frequency counting and comparison to efficiently determine which strings from words1 are universal.
Time complexity is O(N*K) where N is total characters in all words and K is alphabet size (26).
*/
