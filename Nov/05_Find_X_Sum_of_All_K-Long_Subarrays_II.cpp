// 3321. Find X-Sum of All K-Long Subarrays II

// You are given an array nums of n integers and two integers k and x.

// The x-sum of an array is calculated by the following procedure:

// Count the occurrences of all elements in the array.
// Keep only the occurrences of the top x most frequent elements. If two elements have the same number of occurrences, the element with the bigger value is considered more frequent.
// Calculate the sum of the resulting array.
// Note that if an array has less than x distinct elements, its x-sum is the sum of the array.

// Return an integer array answer of length n - k + 1 where answer[i] is the x-sum of the subarray nums[i..i + k - 1].

 

// Example 1:

// Input: nums = [1,1,2,2,3,4,2,3], k = 6, x = 2

// Output: [6,10,12]

// Explanation:

// For subarray [1, 1, 2, 2, 3, 4], only elements 1 and 2 will be kept in the resulting array. Hence, answer[0] = 1 + 1 + 2 + 2.
// For subarray [1, 2, 2, 3, 4, 2], only elements 2 and 4 will be kept in the resulting array. Hence, answer[1] = 2 + 2 + 2 + 4. Note that 4 is kept in the array since it is bigger than 3 and 1 which occur the same number of times.
// For subarray [2, 2, 3, 4, 2, 3], only elements 2 and 3 are kept in the resulting array. Hence, answer[2] = 2 + 2 + 2 + 3 + 3.
// Example 2:

// Input: nums = [3,8,7,8,7,5], k = 2, x = 2

// Output: [11,15,15,15,12]

// Explanation:

// Since k == x, answer[i] is equal to the sum of the subarray nums[i..i + k - 1].

 

// Constraints:

// nums.length == n
// 1 <= n <= 105
// 1 <= nums[i] <= 109
// 1 <= x <= k <= nums.length

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> findXSum(vector<int> &nums, int k, int x)
    {
        int n = nums.size();
        vector<long long> ans(n - k + 1);
        unordered_map<int, int> freq;

        // Step 1: Initialize structures
        auto cmp = [&](int a, int b)
        {
            if (freq[a] != freq[b])
            {
                return freq[a] < freq[b];
            }
            return a < b;
        };

        set<int, decltype(cmp)> topX(cmp), rest(cmp);
        long long sumTop = 0;

        // Step 2: Ordering / comparator defined above

        auto rebalance = [&]()
        {
            // Step 4: rebalance logic
            while ((int)topX.size() < min(x, (int)freq.size()) && !rest.empty())
            {
                int best = *prev(rest.end());
                rest.erase(prev(rest.end()));
                topX.insert(best);
                sumTop += 1LL * freq[best] * best;
            }

            while ((int)topX.size() > x)
            {
                int worst = *topX.begin();
                topX.erase(topX.begin());
                rest.insert(worst);
                sumTop -= 1LL * freq[worst] * worst;
            }

            while (!topX.empty() && !rest.empty())
            {
                int worstTop = *topX.begin();
                int bestRest = *prev(rest.end());
                int fw = freq[worstTop], fr = freq[bestRest];

                if (fr > fw || (fr == fw && bestRest > worstTop))
                {
                    topX.erase(topX.begin());
                    rest.erase(prev(rest.end()));
                    topX.insert(bestRest);
                    rest.insert(worstTop);
                    sumTop += 1LL * fr * bestRest - 1LL * fw * worstTop;
                }
                else
                {
                    break;
                }
            }
        };

        // Step 3,5,6 and Step 7: Main sliding-window loop
        for (int i = 0; i < n; ++i)
        {
            int v = nums[i];
            int old = freq[v];

            if (old > 0)
            {
                if (topX.erase(v))
                {
                    sumTop -= 1LL * old * v;
                }
                else
                {
                    rest.erase(v);
                }
            }

            freq[v] = old + 1;
            rest.insert(v);
            rebalance();

            if (i >= k)
            {
                int u = nums[i - k];
                int oldU = freq[u];

                if (topX.erase(u))
                {
                    sumTop -= 1LL * oldU * u;
                }
                else
                {
                    rest.erase(u);
                }

                if (oldU == 1)
                {
                    freq.erase(u);
                }
                else
                {
                    freq[u] = oldU - 1;
                    rest.insert(u);
                }
                rebalance();
            }

            if (i >= k - 1)
            {
                ans[i - k + 1] = sumTop;
            }
        }

        // Step 9: Return result
        return ans;
    }
};