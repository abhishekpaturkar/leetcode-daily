// 3403. Find the Lexicographically Largest String From the Box I

// You are given a string word, and an integer numFriends.

// Alice is organizing a game for her numFriends friends. There are multiple rounds in the game, where in each round:

// word is split into numFriends non-empty strings, such that no previous round has had the exact same split.
// All the split words are put into a box.
// Find the lexicographically largest string from the box after all the rounds are finished.

 
// Example 1:

// Input: word = "dbca", numFriends = 2

// Output: "dbc"

// Explanation: 

// All possible splits are:

// "d" and "bca".
// "db" and "ca".
// "dbc" and "a".
// Example 2:

// Input: word = "gggg", numFriends = 4

// Output: "g"

// Explanation: 

// The only possible split is: "g", "g", "g", and "g".

 

// Constraints:

// 1 <= word.length <= 5 * 103
// word consists only of lowercase English letters.
// 1 <= numFriends <= word.length

class Solution
{
public:
    string answerString(string word, int numFriends)
    {
        if (numFriends == 1)
            return word;
        string res = "";
        for (int i = 0; i < word.size(); i++)
            res = max(res, word.substr(i, word.length() - numFriends + 1));
        return res;
    }
};

/*
This code finds the lexicographically largest string from all possible splits of a given word among numFriends.

If numFriends is 1, it means no splitting is needed, so return the entire word.
Otherwise, iterate through each position in the word and consider substrings starting from that position.
The length of each substring is calculated as (word.length - numFriends + 1) to ensure valid splits.
Compare each substring with the current result and keep the lexicographically larger one.
Finally return the largest string found.

Time Complexity: O(n^2) where n is the length of word
- The loop runs n times
- substr operation takes O(n) time

Space Complexity: O(n) where n is the length of word
- We store substrings of the word
*/
