// 3306. Count of Substrings Containing Every Vowel and K Consonants II

// You are given a string word and a non-negative integer k.

// Return the total number of substrings of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at least once and exactly k consonants.


// Example 1:

// Input: word = "aeioqq", k = 1

// Output: 0

// Explanation:

// There is no substring with every vowel.

// Example 2:

// Input: word = "aeiou", k = 0

// Output: 1

// Explanation:

// The only substring with every vowel and zero consonants is word[0..4], which is "aeiou".

// Example 3:

// Input: word = "ieaouqqieaouqq", k = 1

// Output: 3

// Explanation:

// The substrings with every vowel and one consonant are:

// word[0..5], which is "ieaouq".
// word[6..11], which is "qieaou".
// word[7..12], which is "ieaouq".
 

// Constraints:

// 5 <= word.length <= 2 * 105
// word consists only of lowercase English letters.
// 0 <= k <= word.length - 5

class Solution
{
public:
    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    long long atLeastK(string &word, int k)
    {
        int n = word.size();
        long long ans = 0;
        int consonants = 0;
        int left = 0;
        unordered_map<char, int> vowel_map;

        for (int right = 0; right < n; right++)
        {
            if (isVowel(word[right]))
            {
                vowel_map[word[right]]++;
            }
            else
            {
                consonants++;
            }

            while (vowel_map.size() == 5 && consonants >= k)
            {
                ans += n - right;
                if (isVowel(word[left]))
                {
                    vowel_map[word[left]]--;
                    if (vowel_map[word[left]] == 0)
                    {
                        vowel_map.erase(word[left]);
                    }
                }
                else
                {
                    consonants--;
                }
                left++;
            }
        }
        return ans;
    }

    long long countOfSubstrings(string word, int k)
    {
        return atLeastK(word, k) - atLeastK(word, k + 1);
    }
};

/*
This code solves the problem of counting substrings that contain all vowels and exactly k consonants:

1. isVowel() function checks if a character is a vowel (a,e,i,o,u)

2. atLeastK() function:
   - Uses sliding window technique with two pointers (left, right)
   - Maintains vowel_map to track frequency of vowels
   - Counts consonants separately
   - When window has all 5 vowels and at least k consonants:
     * Adds count of possible substrings (n-right)
     * Shrinks window from left
   - Returns count of substrings with all vowels and >= k consonants

3. countOfSubstrings() function:
   - Uses inclusion-exclusion principle
   - Subtracts count of substrings with k+1 consonants from count of substrings with k consonants
   - Gives final count of substrings with exactly k consonants

Time Complexity: O(n) where n is length of string
Space Complexity: O(1) as vowel_map size is constant
*/