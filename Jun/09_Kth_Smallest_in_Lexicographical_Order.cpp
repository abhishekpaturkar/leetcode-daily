// 440. K-th Smallest in Lexicographical Order

// Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].

 

// Example 1:

// Input: n = 13, k = 2
// Output: 10
// Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.
// Example 2:

// Input: n = 1, k = 1
// Output: 1
 

// Constraints:

// 1 <= k <= n <= 109

class Solution
{
public:
    int getReqNum(long a, long b, long &n)
    {
        int gap = 0;
        while (a <= n)
        {
            gap += std::min(n + 1, b) - a;
            a *= 10;
            b *= 10;
        }
        return gap;
    }

    int findKthNumber(long n, long k)
    {
        long num = 1;
        for (int i = 1; i < k;)
        {
            int req = getReqNum(num, num + 1, n);
            if (i + req <= k)
            {
                i += req;
                num++;
            }
            else
            {
                i++;
                num *= 10;
            }
        }
        return num;
    }
};

/*
This solution finds the kth lexicographically smallest number in range [1, n] using a digit-by-digit approach:

1. getReqNum function:
   - Calculates count of numbers in lexicographical order between two prefixes
   - Uses decimal multiplication to check all possible numbers with given prefix
   - Returns total count of valid numbers between range

2. findKthNumber function:
   - Starts with smallest prefix 1
   - For each step, checks if numbers with current prefix can reach k
   - If yes, moves to next prefix horizontally (num++)
   - If no, moves to next number vertically (num*10)
   - Continues until kth number is found

Time Complexity: O(log n * log n)
- Each iteration processes one digit
- For each digit, we calculate numbers in range

Space Complexity: O(1)
- Only uses few variables regardless of input size
*/