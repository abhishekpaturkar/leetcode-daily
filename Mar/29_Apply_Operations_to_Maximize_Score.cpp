t // 2818. Apply Operations to Maximize Score

    // You are given an array nums of n positive integers and an integer k.

    // Initially, you start with a score of 1. You have to maximize your score by applying the following operation at most k times:

    // Choose any non-empty subarray nums[l, ..., r] that you haven't chosen previously.
    // Choose an element x of nums[l, ..., r] with the highest prime score. If multiple such elements exist, choose the one with the smallest index.
    // Multiply your score by x.
    // Here, nums[l, ..., r] denotes the subarray of nums starting at index l and ending at the index r, both ends being inclusive.

    // The prime score of an integer x is equal to the number of distinct prime factors of x. For example, the prime score of 300 is 3 since 300 = 2 * 2 * 3 * 5 * 5.

    // Return the maximum possible score after applying at most k operations.

    // Since the answer may be large, return it modulo 109 + 7.

    // Example 1:

    // Input: nums = [8,3,9,3,8], k = 2
    // Output: 81
    // Explanation: To get a score of 81, we can apply the following operations:
    // - Choose subarray nums[2, ..., 2]. nums[2] is the only element in this subarray. Hence, we multiply the score by nums[2]. The score becomes 1 * 9 = 9.
    // - Choose subarray nums[2, ..., 3]. Both nums[2] and nums[3] have a prime score of 1, but nums[2] has the smaller index. Hence, we multiply the score by nums[2]. The score becomes 9 * 9 = 81.
    // It can be proven that 81 is the highest score one can obtain.
    // Example 2:

    // Input: nums = [19,12,14,6,10,18], k = 3
    // Output: 4788
    // Explanation: To get a score of 4788, we can apply the following operations:
    // - Choose subarray nums[0, ..., 0]. nums[0] is the only element in this subarray. Hence, we multiply the score by nums[0]. The score becomes 1 * 19 = 19.
    // - Choose subarray nums[5, ..., 5]. nums[5] is the only element in this subarray. Hence, we multiply the score by nums[5]. The score becomes 19 * 18 = 342.
    // - Choose subarray nums[2, ..., 3]. Both nums[2] and nums[3] have a prime score of 2, but nums[2] has the smaller index. Hence, we multipy the score by nums[2]. The score becomes 342 * 14 = 4788.
    // It can be proven that 4788 is the highest score one can obtain.

    // Constraints:

    // 1 <= nums.length == n <= 105
    // 1 <= nums[i] <= 105
    // 1 <= k <= min(n * (n + 1) / 2, 109)

    class Solution
{
private:
    int countDistinctPrimeFactors(int n)
    {
        int count = 0;
        if (n % 2 == 0)
        {
            count++;
            while (n % 2 == 0)
            {
                n /= 2;
            }
        }

        for (long long i = 3; i * i <= n; i += 2)
        {
            if (n % i == 0)
            {
                count++;
                while (n % i == 0)
                {
                    n /= i;
                }
            }
        }
        if (n > 1)
            count++;
        return count;
    }

    int modPow(int base, int exp, int mod)
    {
        long long result = 1;
        long long b = base % mod;
        while (exp > 0)
        {
            if (exp & 1)
            {
                result = (result * b) % mod;
            }
            b = (b * b) % mod;
            exp >>= 1;
        }
        return (int)result;
    }

public:
    int maximumScore(vector<int> &nums, int k)
    {
        int n = (int)nums.size();
        if (n == 0)
            return 1;

        priority_queue<pair<int, int>> maxValues;
        vector<int> rightLarge(n, n), LeftLarge(n, -1), primeScores(n, 0);
        stack<int> st, reverse;

        for (int i = 0; i < n; i++)
        {
            primeScores[i] = countDistinctPrimeFactors(nums[i]);
            maxValues.emplace(nums[i], i);
        }

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && primeScores[i] > primeScores[st.top()])
            {
                rightLarge[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        for (int i = n - 1; i >= 0; i--)
        {
            while (!reverse.empty() &&
                   primeScores[i] >= primeScores[reverse.top()])
            {
                LeftLarge[reverse.top()] = i;
                reverse.pop();
            }
            reverse.push(i);
        }

        int score = 1;
        const int MODULE = 1000000007;

        while (!maxValues.empty() && k > 0)
        {
            auto [val, idx] = maxValues.top();
            maxValues.pop();

            long long t =
                1LL * (rightLarge[idx] - idx) * (idx - LeftLarge[idx]);
            long long steps = min(t, (long long)k);

            int multiply = modPow(val, (int)steps, MODULE);
            score = (int)((1LL * score * multiply) % MODULE);

            k -= steps;
        }
        return score % MODULE;
    }
};

/*
1. Compute Prime Factor Counts:
    - Count the number of distinct prime factors for each element in nums.
2. Find Next Greater Elements (Monotonic Stack):
    - Find the next greater element index to the right (rightLarge).
    - Find the next greater element index to the left (leftLarge).
3. Use a Max-Heap:
    - Sort elements by their values (largest first) and process them greedily.
4. Efficient Exponentiation:
    - Use modular exponentiation to handle large values efficiently.

    Complexity
Time Complexity:
Prime factorization: (O(sqrt{M})) per number → (O(n*sqrt{M})).
Space Complexity:
Storing indices, prime scores, and priority queue → (O(n)).
*/