// 38. Count and Say

// The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

// countAndSay(1) = "1"
// countAndSay(n) is the run-length encoding of countAndSay(n - 1).
// Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11". Thus the compressed string becomes "23321511".

// Given a positive integer n, return the nth element of the count-and-say sequence.

// Example 1:

// Input: n = 4

// Output: "1211"

// Explanation:

// countAndSay(1) = "1"
// countAndSay(2) = RLE of "1" = "11"
// countAndSay(3) = RLE of "11" = "21"
// countAndSay(4) = RLE of "21" = "1211"
// Example 2:

// Input: n = 1

// Output: "1"

// Explanation:

// This is the base case.

// Constraints:

// 1 <= n <= 30

class Solution
{
public:
    string ans = "";
    bool found = false;
    void fn(string &temp, int n)
    {
        if (found)
            return;
        if (n == 1)
        {
            ans = temp;
            found = true;
            return;
        }

        char pre = temp[0];
        string s = temp;
        string str = "";
        int cnt = 1;
        for (int i = 1; i < temp.length(); i++)
        {
            if (temp[i] == pre)
            {
                cnt++;
            }
            else
            {
                str += to_string(cnt);
                str += pre;
                cnt = 1;
            }
            pre = temp[i];
        }
        str += to_string(cnt);
        str += pre;
        fn(str, n - 1);
    }
    string countAndSay(int n)
    {
        string temp = "1";
        fn(temp, n);
        return ans;
    }
};

/*
Code Explanation:
This code implements the Count and Say sequence problem using recursion. Here's how it works:

1. The Solution class has member variables:
   - ans: stores the final result string
   - found: boolean flag to stop recursion

2. The fn() function is the recursive helper that:
   - Takes current string and remaining count n
   - Base case: when n=1, stores result in ans
   - For each string, counts consecutive same characters
   - Builds new string with count followed by character
   - Recursively calls itself with new string and n-1

3. The countAndSay() function:
   - Takes input n
   - Starts with initial string "1"
   - Calls recursive helper fn()
   - Returns final answer

Time Complexity: O(N * M)
- N is the input number
- M is the length of string at each step
- Each recursive call processes entire string

Space Complexity: O(N)
- Due to recursive call stack depth of N
- Additional space for temporary strings at each step
*/