// 2523. Closest Prime Numbers in Range

// Given two positive integers left and right, find the two integers num1 and num2 such that:

// left <= num1 < num2 <= right .
// Both num1 and num2 are prime numbers.
// num2 - num1 is the minimum amongst all other pairs satisfying the above conditions.
// Return the positive integer array ans = [num1, num2]. If there are multiple pairs satisfying these conditions, return the one with the smallest num1 value. If no such numbers exist, return [-1, -1].


// Example 1:

// Input: left = 10, right = 19
// Output: [11,13]
// Explanation: The prime numbers between 10 and 19 are 11, 13, 17, and 19.
// The closest gap between any pair is 2, which can be achieved by [11,13] or [17,19].
// Since 11 is smaller than 17, we return the first pair.
// Example 2:

// Input: left = 4, right = 6
// Output: [-1,-1]
// Explanation: There exists only one prime number in the given range, so the conditions cannot be satisfied.
 

// Constraints:

// 1 <= left <= right <= 106

class Solution
{
public:
    vector<int> closestPrimes(int left, int right)
    {
        auto is_prime = [](int n)
        {
            if (n <= 1)
                return false;
            if (n <= 3)
                return true;
            if (n % 2 == 0 || n % 3 == 0)
                return false;
            for (int i = 5; i * i <= n; i += 6)
            {
                if (n % i == 0 || n % (i + 2) == 0)
                    return false;
            }
            return true;
        };

        vector<int> primes;
        for (int num = max(2, left); num <= right; ++num)
        {
            if (is_prime(num))
            {
                primes.push_back(num);
            }
        }

        if (primes.size() < 2)
        {
            return {-1, -1};
        }

        int min_gap = INT_MAX;
        vector<int> result = {-1, -1};

        for (int i = 1; i < primes.size(); ++i)
        {
            int gap = primes[i] - primes[i - 1];
            if (gap < min_gap)
            {
                min_gap = gap;
                result = {primes[i - 1], primes[i]};
            }
        }

        return result;
    }
};

/*
This code finds the two closest prime numbers within a given range [left, right]. Here's how it works:

1. The is_prime lambda function efficiently checks if a number is prime using the 6k±1 optimization.

2. The code then creates a vector 'primes' to store all prime numbers in the given range.

3. If less than 2 prime numbers are found, returns [-1, -1].

4. Finally, it iterates through the prime numbers to find the pair with minimum gap between them.
   - Keeps track of minimum gap found so far
   - Updates result vector when a smaller gap is found

5. Returns the pair of prime numbers with smallest gap, favoring the pair with smaller first number if multiple pairs have the same gap.
*/