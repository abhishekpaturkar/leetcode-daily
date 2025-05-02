// 838. Push Dominoes

// There are n dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.

// After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.

// When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

// For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.

// You are given a string dominoes representing the initial state where:

// dominoes[i] = 'L', if the ith domino has been pushed to the left,
// dominoes[i] = 'R', if the ith domino has been pushed to the right, and
// dominoes[i] = '.', if the ith domino has not been pushed.
// Return a string representing the final state.

 

// Example 1:

// Input: dominoes = "RR.L"
// Output: "RR.L"
// Explanation: The first domino expends no additional force on the second domino.
// Example 2:


// Input: dominoes = ".L.R...LR..L.."
// Output: "LL.RR.LLRRLL.."
 

// Constraints:

// n == dominoes.length
// 1 <= n <= 105
// dominoes[i] is either 'L', 'R', or '.'.

class Solution
{
public:
    string pushDominoes(string s)
    {
        s = 'L' + s + 'R';
        string res;

        int prev = 0;
        for (int curr = 1; curr < s.size(); ++curr)
        {
            if (s[curr] == '.')
            {
                continue;
            }

            int span = curr - prev - 1;
            if (prev > 0)
                res += s[prev];

            if (s[prev] == s[curr])
            {
                res += string(span, s[prev]);
            }
            else if (s[prev] == 'L' && s[curr] == 'R')
            {
                res += string(span, '.');
            }
            else
            {
                res += string(span / 2, 'R') + string(span % 2, '.') + string(span / 2, 'L');
            }
            prev = curr;
        }
        return res;
    }
};

/*
Code Explanation:
This solution solves the Push Dominoes problem using a two-pointer approach:

1. First, we add 'L' at start and 'R' at end of input string as boundary conditions
2. We maintain two pointers: prev and curr
3. We iterate through string looking for non-'.' characters
4. For each segment between prev and curr:
   - If both ends are same (L,L or R,R): fill whole segment with that character
   - If L->R: keep segment as dots
   - If R->L: fill half with R, middle dot if odd length, half with L
5. Build result string incrementally based on these rules

Time Complexity: O(n) where n is length of input string
Space Complexity: O(n) for storing the result string
*/