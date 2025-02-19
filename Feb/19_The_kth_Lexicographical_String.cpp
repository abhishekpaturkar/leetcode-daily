// 1415. The k-th Lexicographical String of All Happy Strings of Length n

// A happy string is a string that:

// consists only of letters of the set ['a', 'b', 'c'].
// s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
// For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.

// Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.

// Return the kth string of this list or return an empty string if there are less than k happy strings of length n.


// Example 1:

// Input: n = 1, k = 3
// Output: "c"
// Explanation: The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".
// Example 2:

// Input: n = 1, k = 4
// Output: ""
// Explanation: There are only 3 happy strings of length 1.
// Example 3:

// Input: n = 3, k = 9
// Output: "cab"
// Explanation: There are 12 different happy string of length 3 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]. You will find the 9th string = "cab"
 

// Constraints:

// 1 <= n <= 10
// 1 <= k <= 100


class Solution
{
    int n2;
    string dfs(string prefix, int n, int k) {
        if (n == 0)
            return prefix;
        for (char c = 'a'; c <= 'c'; c++) {
            if (!prefix.empty() && c == prefix.back())
                continue;
            int cnt = (1 << (n2 - prefix.length() - 1));
            if (cnt >= k)
                return dfs(prefix + c, n - 1, k);
            else
                k -= cnt;
        }
        return "";
    }
public:
    string getHappyString(int n, int k) {
        n2 = n;
        return dfs("", n, k);
    }
};

/*
This code finds the kth lexicographically sorted happy string of length n. Here's how it works:

1. The class maintains n2 as a member variable to store the original length n.

2. The dfs function uses a recursive approach with parameters:
   - prefix: current string being built
   - n: remaining length needed
   - k: position of string we're looking for

3. Base case: When n becomes 0, we've built a string of required length, so return it

4. For each character 'a' to 'c':
   - Skip if current char equals last char of prefix (happy string rule)
   - Calculate count of possible strings (cnt) from current position
   - If k is within current count, recurse with new prefix
   - Otherwise, subtract count from k and try next character

5. The getHappyString function initializes n2 and starts DFS with empty prefix

The solution uses bit manipulation (1 << x) to calculate possible strings count efficiently.
*/