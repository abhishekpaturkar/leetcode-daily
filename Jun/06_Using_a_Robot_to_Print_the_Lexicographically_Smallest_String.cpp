// 2434. Using a Robot to Print the Lexicographically Smallest String

// You are given a string s and a robot that currently holds an empty string t. Apply one of the following operations until s and t are both empty:

// Remove the first character of a string s and give it to the robot. The robot will append this character to the string t.
// Remove the last character of a string t and give it to the robot. The robot will write this character on paper.
// Return the lexicographically smallest string that can be written on the paper.

 

// Example 1:

// Input: s = "zza"
// Output: "azz"
// Explanation: Let p denote the written string.
// Initially p="", s="zza", t="".
// Perform first operation three times p="", s="", t="zza".
// Perform second operation three times p="azz", s="", t="".
// Example 2:

// Input: s = "bac"
// Output: "abc"
// Explanation: Let p denote the written string.
// Perform first operation twice p="", s="c", t="ba". 
// Perform second operation twice p="ab", s="c", t="". 
// Perform first operation p="ab", s="", t="c". 
// Perform second operation p="abc", s="", t="".
// Example 3:

// Input: s = "bdda"
// Output: "addb"
// Explanation: Let p denote the written string.
// Initially p="", s="bdda", t="".
// Perform first operation four times p="", s="", t="bdda".
// Perform second operation four times p="addb", s="", t="".
 

// Constraints:

// 1 <= s.length <= 105
// s consists of only English lowercase letters.

class Solution
{
public:
    // Helper function to find the lexicographically smallest remaining character
    char l(vector<int> &freq)
    {
        for (int i = 0; i < 26; i++)
        {
            if (freq[i])
                return 'a' + i;
        }
        return 'a';
    }

    string robotWithString(string s)
    {
        stack<char> st;
        string t = "";
        vector<int> freq(26);

        // Count frequency of each character in s
        for (char ch : s)
        {
            freq[ch - 'a']++;
        }

        // Iterate over characters in s
        for (char ch : s)
        {
            st.push(ch);
            freq[ch - 'a']--;

            // Pop from stack to result if stack top ≤ smallest remaining char
            while (!st.empty() && st.top() <= l(freq))
            {
                t += st.top();
                st.pop();
            }
        }

        // Pop remaining characters
        while (!st.empty())
        {
            t += st.top();
            st.pop();
        }

        return t;
    }
};

/*
Code Explanation:
This solution finds the lexicographically smallest string that can be formed using a robot. Here's how it works:

1. The helper function 'l' finds the smallest character that still exists in the frequency array.

2. Main function 'robotWithString':
   - Uses a stack to store characters temporarily
   - Maintains frequency count of remaining characters
   - Processes each character:
     * Pushes current character to stack
     * Updates frequency count
     * If stack top is smaller/equal to smallest remaining character, adds it to result
   - Finally adds remaining stack characters to result

Time Complexity: O(n), where n is length of input string
- Each character is pushed and popped at most once
- Helper function 'l' takes O(1) as it always checks 26 characters

Space Complexity: O(n)
- Stack can store up to n characters
- Frequency array is constant size (26)
*/