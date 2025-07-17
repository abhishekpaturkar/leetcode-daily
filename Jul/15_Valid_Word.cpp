// 3136. Valid Word

// A word is considered valid if:

// It contains a minimum of 3 characters.
// It contains only digits (0-9), and English letters (uppercase and lowercase).
// It includes at least one vowel.
// It includes at least one consonant.
// You are given a string word.

// Return true if word is valid, otherwise, return false.

// Notes:

// 'a', 'e', 'i', 'o', 'u', and their uppercases are vowels.
// A consonant is an English letter that is not a vowel.
 

// Example 1:

// Input: word = "234Adas"

// Output: true

// Explanation:

// This word satisfies the conditions.

// Example 2:

// Input: word = "b3"

// Output: false

// Explanation:

// The length of this word is fewer than 3, and does not have a vowel.

// Example 3:

// Input: word = "a3$e"

// Output: false

// Explanation:

// This word contains a '$' character and does not have a consonant.

 

// Constraints:

// 1 <= word.length <= 20
// word consists of English uppercase and lowercase letters, digits, '@', '#', and '$'.

class Solution
{
public:
    bool isValid(string s)
    {
        int n = s.length();
        if (n < 3)
            return false;

        int vowels = 0, consonants = 0;
        string vowelList = "aeiouAEIOU";

        for (char c : s)
        {
            if (isalpha(c))
            {
                if (vowelList.find(c) != string::npos)
                {
                    vowels++;
                }
                else
                {
                    consonants++;
                }
            }
            else if (!isdigit(c))
            {
                return false;
            }
        }

        return vowels >= 1 && consonants >= 1;
    }
};

/*
This code checks if a given string is valid according to the following rules:
1. Length must be at least 3 characters
2. Can only contain letters and digits
3. Must have at least one vowel
4. Must have at least one consonant

The algorithm:
1. First checks string length
2. Maintains counters for vowels and consonants
3. Iterates through each character:
   - If it's a letter, checks if it's a vowel or consonant
   - If it's not a letter or digit, returns false
4. Finally checks if both vowels and consonants are present

Time Complexity: O(n) where n is the length of string
Space Complexity: O(1) as we only use fixed extra space
*/