// 2226. Maximum Candies Allocated to K Children

// You are given a 0-indexed integer array candies. Each element in the array denotes a pile of candies of size candies[i]. You can divide each pile into any number of sub piles, but you cannot merge two piles together.

// You are also given an integer k. You should allocate piles of candies to k children such that each child gets the same number of candies. Each child can be allocated candies from only one pile of candies and some piles of candies may go unused.

// Return the maximum number of candies each child can get.

// Example 1:

// Input: candies = [5,8,6], k = 3
// Output: 5
// Explanation: We can divide candies[1] into 2 piles of size 5 and 3, and candies[2] into 2 piles of size 5 and 1. We now have five piles of candies of sizes 5, 5, 3, 5, and 1. We can allocate the 3 piles of size 5 to 3 children. It can be proven that each child cannot receive more than 5 candies.
// Example 2:

// Input: candies = [2,5], k = 11
// Output: 0
// Explanation: There are 11 children but only 7 candies in total, so it is impossible to ensure each child receives at least one candy. Thus, each child gets no candy and the answer is 0.

// Constraints:

// 1 <= candies.length <= 105
// 1 <= candies[i] <= 107
// 1 <= k <= 1012

class Solution
{
public:
    int maximumCandies(vector<int> &candies, long long k)
    {
        long long left = 1, right = *max_element(candies.begin(), candies.end());
        int result = 0;

        while (left <= right)
        {
            long long mid = left + (right - left) / 2;
            long long children_count = 0;

            for (int pile : candies)
            {
                children_count += pile / mid;
            }

            if (children_count >= k)
            {
                result = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return result;
    }
};

/*
This code implements a binary search solution to find the maximum number of candies that can be allocated to k children.

The algorithm works as follows:
1. Initialize binary search boundaries: left = 1 and right = maximum candy pile
2. For each middle point (mid), calculate how many children can get 'mid' candies
3. If we can give 'mid' candies to >= k children, try to increase candies (left = mid + 1)
4. If we can't give 'mid' candies to k children, decrease candies (right = mid - 1)
5. Keep track of the valid result and return it

Time Complexity: O(n * log m) where n is the length of candies array and m is the maximum element in candies
Space Complexity: O(1) as we only use constant extra space
*/