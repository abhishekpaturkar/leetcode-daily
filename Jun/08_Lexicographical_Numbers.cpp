// 386. Lexicographical Numbers

// Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.

// You must write an algorithm that runs in O(n) time and uses O(1) extra space. 

 

// Example 1:

// Input: n = 13
// Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
// Example 2:

// Input: n = 2
// Output: [1,2]
 

// Constraints:

// 1 <= n <= 5 * 104

class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> ans(n);
        int x = 1;
        for (int i = 0; i < n; i++)
        {
            ans[i] = x;
            if (x * 10 > n)
            {
                if (x == n)
                    x /= 10;
                x++;
                while (x % 10 == 0)
                    x /= 10;
            }
            else
                x *= 10;
        }
        return ans;
    }
};

/*
This code generates lexicographically ordered numbers from 1 to n. Here's how it works:

1. Initialize a vector 'ans' of size n to store the result
2. Start with x = 1 (first lexicographical number)
3. For each position in array:
   - Add current x to answer
   - If x*10 exceeds n:
     * If x equals n, move back one digit
     * Increment x and remove trailing zeros
   - Else multiply x by 10 to get next lexicographical number

For example, for n=13:
x progression: 1->10->11->12->13->2->3->4->5->6->7->8->9

Time Complexity: O(n) - visits each number exactly once
Space Complexity: O(1) - excluding output array, uses constant extra space
*/