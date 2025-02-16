// 1718. Construct the Lexicographically Largest Valid Sequence

// Given an integer n, find a sequence that satisfies all of the following:

// The integer 1 occurs once in the sequence.
// Each integer between 2 and n occurs twice in the sequence.
// For every integer i between 2 and n, the distance between the two occurrences of i is exactly i.
// The distance between two numbers on the sequence, a[i] and a[j], is the absolute difference of their indices, |j - i|.

// Return the lexicographically largest sequence. It is guaranteed that under the given constraints, there is always a solution.

// A sequence a is lexicographically larger than a sequence b (of the same length) if in the first position where a and b differ, sequence a has a number greater than the corresponding number in b. For example, [0,1,9,0] is lexicographically larger than [0,1,5,6] because the first position they differ is at the third number, and 9 is greater than 5.

// Example 1:

// Input: n = 3
// Output: [3,1,2,3,2]
// Explanation: [2,3,2,1,3] is also a valid sequence, but [3,1,2,3,2] is the lexicographically largest valid sequence.
// Example 2:

// Input: n = 5
// Output: [5,3,1,4,3,5,2,4,2]

// Constraints:

// 1 <= n <= 20

class Solution
{
public:
    vector<int> constructDistancedSequence(int n)
    {
        vector<int> result(2 * n - 1, 0);
        vector<bool> used(n + 1, false);
        backtrack(result, used, n, 0);
        return result;
    }

private:
    bool backtrack(vector<int> &result, vector<bool> &used, int n, int index)
    {
        while (index < result.size() && result[index] != 0)
        {
            index++;
        }
        if (index == result.size())
        {
            return true;
        }

        for (int i = n; i >= 1; i--)
        {
            if (used[i])
                continue;

            if (i == 1)
            {
                result[index] = 1;
                used[1] = true;
                if (backtrack(result, used, n, index + 1))
                    return true;
                result[index] = 0;
                used[1] = false;
            }
            else if (index + i < result.size() && result[index + i] == 0)
            {
                result[index] = i;
                result[index + i] = i;
                used[i] = true;
                if (backtrack(result, used, n, index + 1))
                    return true;
                result[index] = 0;
                result[index + i] = 0;
                used[i] = false;
            }
        }
        return false;
    }
};

/*
This code solves the problem of constructing the lexicographically largest valid sequence where:
1. Number 1 appears once
2. Numbers 2 to n appear twice
3. For each number i (2 to n), the distance between its two occurrences is exactly i

The solution uses backtracking:
- Creates a result array of size 2n-1 (initialized with zeros)
- Uses a boolean array to track used numbers
- For each position, tries placing numbers from n down to 1 (to get lexicographically largest)
- For number 1: places it at current index
- For numbers 2 to n: places at current index and index+i if both positions are empty
- Backtracks if current placement doesn't lead to solution
- Returns true when all positions are filled
*/