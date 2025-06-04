// 3403. Find the Lexicographically Largest String From the Box I

// You are given a string word and an integer numFriends. In each game round, the word is split into numFriends non-empty parts such that no exact same split has been used before, and all substrings from all valid splits are placed in a box.

// Your task is to return the lexicographically largest string that appears in any of the substrings from all rounds.

// This solution avoids generating all splits, which would be computationally expensive. Instead, it uses an optimized algorithm based on Duval's algorithm (or Booth's algorithm) to find the best starting index of the lexicographically largest substring in the original string.

// If numFriends == 1, then the entire string is the only split, so return word.

// Otherwise, use a greedy comparison approach (bestStartingPoint) to find the start of the lexicographically largest suffix of word.

// Since you need to split the string into numFriends parts, the maximum length of any part can be at most n - (numFriends - 1).

// From the largest suffix found, take the maximum possible prefix (up to the allowed length) to get the answer.

class Solution {
public:
    int bestStartingPoint(string &word, int n) {
        int i = 0; 
        int j = 1; 

        while(j < n) {
            int k = 0;

            while( j+k < n && word[i+k] == word[j+k]) {
                k++;
            }

            if(j+k < n && word[j+k] > word[i+k]) {
                i = j; 
                j = j+1;
            } else {
                j = j + k + 1; 
            }
        }

        return i;
    }

    string answerString(string word, int numFriends) {
        int n = word.length();

        if(numFriends == 1)
            return word;

        int i = bestStartingPoint(word, n);

        int longestPossibleLength = n - (numFriends-1);
        int canTakePossible       = min(longestPossibleLength, n-i);

        return word.substr(i, canTakePossible);

    }
};

// Two Pointer approach to find the lexicographically largest suffix.

// Similar in spirit to Booth’s algorithm for lexicographically minimal or maximal rotations.

// Example :

// Input: word = "dbca", numFriends = 2
// Output: "dbc"

// Explanation:
// - All possible splits of "dbca" into 2 parts give: ("d","bca"), ("db","ca"), ("dbc","a")
// - All substrings from those splits are: "d", "bca", "db", "ca", "dbc", "a"
// - The largest among them is "dbc"

// Time Complexity: O(n), where n is the length of the string. Each character is processed at most twice in bestStartingPoint.

// Space Complexity: O(1) extra space, aside from the substring returned.
