// 3304. Find the K-th Character in String Game I

// Alice and Bob are playing a game. Initially, Alice has a string word = "a".

// You are given a positive integer k.

// Now Bob will ask Alice to perform the following operation forever:

// Generate a new string by changing each character in word to its next character in the English alphabet, and append it to the original word.
// For example, performing the operation on "c" generates "cd" and performing the operation on "zb" generates "zbac".

// Return the value of the kth character in word, after enough operations have been done for word to have at least k characters.

// Note that the character 'z' can be changed to 'a' in the operation.

 

// Example 1:

// Input: k = 5

// Output: "b"

// Explanation:

// Initially, word = "a". We need to do the operation three times:

// Generated string is "b", word becomes "ab".
// Generated string is "bc", word becomes "abbc".
// Generated string is "bccd", word becomes "abbcbccd".
// Example 2:

// Input: k = 10

// Output: "c"

 

// Constraints:

// 1 <= k <= 500

class Solution
{
public:
    char kthCharacter(int k)
    {
        std::string sb = "a";
        while (sb.length() < k)
        {
            int size = sb.length();
            for (int i = 0; i < size; ++i)
            {
                char nextChar = 'a' + ((sb[i] - 'a' + 1) % 26);
                sb += nextChar;
            }
        }
        return sb[k - 1];
    }
};

/*
This code implements a solution to find the k-th character in a string game:
1. Start with string "a"
2. For each character in current string:
   - Generate next alphabet character (wrapping z to a)
   - Append to existing string
3. Continue until string length >= k
4. Return k-th character (1-based index)

Time Complexity: O(k) - In each iteration string length doubles
Space Complexity: O(k) - String grows to length k
*/