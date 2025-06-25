// 2040. Kth Smallest Product of Two Sorted Arrays

// Given two sorted 0-indexed integer arrays nums1 and nums2 as well as an integer k, return the kth (1-based) smallest product of nums1[i] * nums2[j] where 0 <= i < nums1.length and 0 <= j < nums2.length.
 

// Example 1:

// Input: nums1 = [2,5], nums2 = [3,4], k = 2
// Output: 8
// Explanation: The 2 smallest products are:
// - nums1[0] * nums2[0] = 2 * 3 = 6
// - nums1[0] * nums2[1] = 2 * 4 = 8
// The 2nd smallest product is 8.
// Example 2:

// Input: nums1 = [-4,-2,0,3], nums2 = [2,4], k = 6
// Output: 0
// Explanation: The 6 smallest products are:
// - nums1[0] * nums2[1] = (-4) * 4 = -16
// - nums1[0] * nums2[0] = (-4) * 2 = -8
// - nums1[1] * nums2[1] = (-2) * 4 = -8
// - nums1[1] * nums2[0] = (-2) * 2 = -4
// - nums1[2] * nums2[0] = 0 * 2 = 0
// - nums1[2] * nums2[1] = 0 * 4 = 0
// The 6th smallest product is 0.
// Example 3:

// Input: nums1 = [-2,-1,0,1,2], nums2 = [-3,-1,2,4,5], k = 3
// Output: -6
// Explanation: The 3 smallest products are:
// - nums1[0] * nums2[4] = (-2) * 5 = -10
// - nums1[0] * nums2[3] = (-2) * 4 = -8
// - nums1[4] * nums2[0] = 2 * (-3) = -6
// The 3rd smallest product is -6.
 

// Constraints:

// 1 <= nums1.length, nums2.length <= 5 * 104
// -105 <= nums1[i], nums2[j] <= 105
// 1 <= k <= nums1.length * nums2.length
// nums1 and nums2 are sorted.

class Solution
{
public:
    long long kthSmallestProduct(vector<int> &nums1, vector<int> &nums2, long long k)
    {
        // Step 1: Always use smaller array as outer loop for optimization
        if (nums1.size() > nums2.size())
        {
            return kthSmallestProduct(nums2, nums1, k);
        }

        // Step 2: Define binary search range for possible products
        long long lo = -1e10;
        long long hi = 1e10;

        // Step 3: Binary search for the smallest product such that
        // at least k pairs (nums1[i] * nums2[j]) are <= that product
        while (lo < hi)
        {
            long long mid = lo + (hi - lo) / 2;
            long long cnt = countLE(mid, nums1, nums2);

            if (cnt < k)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid;
            }
        }

        // Step 4: Return the kth smallest product
        return lo;
    }

private:
    // Count how many products nums1[i] * nums2[j] are <= x
    long long countLE(long long x, const vector<int> &A, const vector<int> &B)
    {
        long long count = 0;
        int n = B.size();

        if (x >= 0)
        {
            int jPos = n - 1;
            int jNeg = n - 1;

            for (int a : A)
            {
                if (a > 0)
                {
                    while (jPos >= 0 && 1LL * a * B[jPos] > x)
                        jPos--;
                    count += jPos + 1;
                }
                else if (a == 0)
                {
                    count += n; // zero product always <= x if x >= 0
                }
                else // a < 0
                {
                    while (jNeg >= 0 && 1LL * a * B[jNeg] <= x)
                        jNeg--;
                    count += n - 1 - jNeg;
                }
            }
        }
        else // x < 0
        {
            int jPos = 0;
            int jNeg = 0;

            for (int a : A)
            {
                if (a > 0)
                {
                    while (jPos < n && 1LL * a * B[jPos] <= x)
                        jPos++;
                    count += jPos;
                }
                else if (a == 0)
                {
                    continue; // zero products > x (x < 0)
                }
                else // a < 0
                {
                    while (jNeg < n && 1LL * a * B[jNeg] > x)
                        jNeg++;
                    count += n - jNeg;
                }
            }
        }

        return count;
    }
};

/*
This solution finds the kth smallest product of two sorted arrays using binary search.

Key points:
1. Uses binary search on the product range (-10^10 to 10^10)
2. For each mid point, counts how many products are less than or equal to it
3. Handles positive and negative numbers separately for optimization
4. Uses the smaller array as outer loop to minimize iterations

Time Complexity: O(n * log(m) * log(MAX)) where:
- n is length of smaller array
- m is length of larger array
- MAX is the maximum possible product (10^10)

Space Complexity: O(1) as only constant extra space is used

The countLE function efficiently counts products <= x by:
- For x >= 0: Uses two pointers from end of array B
- For x < 0: Uses two pointers from start of array B
- Handles positive, negative and zero elements separately
*/