// 3272. Find the Count of Good Integers

// You are given two positive integers n and k.

// An integer x is called k-palindromic if:

// x is a palindrome.
// x is divisible by k.
// An integer is called good if its digits can be rearranged to form a k-palindromic integer. For example, for k = 2, 2020 can be rearranged to form the k-palindromic integer 2002, whereas 1010 cannot be rearranged to form a k-palindromic integer.

// Return the count of good integers containing n digits.

// Note that any integer must not have leading zeros, neither before nor after rearrangement. For example, 1010 cannot be rearranged to form 101.

 

// Example 1:

// Input: n = 3, k = 5

// Output: 27

// Explanation:

// Some of the good integers are:

// 551 because it can be rearranged to form 515.
// 525 because it is already k-palindromic.
// Example 2:

// Input: n = 1, k = 4

// Output: 2

// Explanation:

// The two good integers are 4 and 8.

// Example 3:

// Input: n = 5, k = 6

// Output: 2468

 

// Constraints:

// 1 <= n <= 10
// 1 <= k <= 9

class Solution
{
public:
    long long countGoodIntegers(int n, int k)
    {
        static long long comb[11][11];
        for (int i = 0; i <= 10; i++)
        {
            comb[i][0] = comb[i][i] = 1;
        }
        for (int i = 2; i <= 10; i++)
        {
            for (int j = 1; j < i; j++)
            {
                comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
            }
        }
        int base = 1;
        for (int i = 0; i < (n + 1) / 2; i++)
            base *= 10;

        vector<long long> encodedFreqs;
        for (int half = base / 10; half < base; half++)
        {
            long long num = half;
            for (int j = 0, mirror = ((n & 1) ? half / 10 : half); j < n / 2; j++)
                num = num * 10 + (mirror % 10), mirror /= 10;
            if (num % k == 0)
            {
                int freq[10] = {};
                for (int t = 0; t < n; t++)
                    freq[num % 10]++, num /= 10;
                num = 0;
                for (int d = 0; d < 10; d++)
                    num = num * 11 + freq[d];
                encodedFreqs.push_back(num);
            }
        }

        sort(encodedFreqs.begin(), encodedFreqs.end());
        encodedFreqs.erase(unique(encodedFreqs.begin(), encodedFreqs.end()), encodedFreqs.end());

        long long total = 0;
        for (long long code : encodedFreqs)
        {
            int freq[10] = {};
            for (int d = 9; d >= 0; d--)
                freq[d] = code % 11, code /= 11;
            long long ways = 1;
            for (int i = 0, rem = n; i < 10; i++)
                ways *= comb[i ? rem : rem - 1][freq[i]], rem -= freq[i];
            total += ways;
        }
        return total;
    }
};

/*
Code Explanation:
This solution finds the count of good integers with n digits that can be rearranged to form k-palindromic numbers.

1. First, it precomputes combinations using Pascal's triangle (comb array)
2. Generates half of palindrome numbers and extends them to full palindromes
3. For each valid palindrome (divisible by k), it:
   - Counts frequency of each digit
   - Encodes these frequencies into a single number
   - Stores unique frequency patterns
4. Finally, for each unique frequency pattern:
   - Decodes back the frequencies
   - Calculates number of possible arrangements using combinations
   - Adds to total count

Time Complexity: O(10^((n+1)/2) * n)
- Main work is in generating half palindromes which is O(10^((n+1)/2))
- For each palindrome, we do O(n) work

Space Complexity: O(10^((n+1)/2))
- For storing encoded frequencies
- Additional O(1) space for combinations array (11x11)
*/