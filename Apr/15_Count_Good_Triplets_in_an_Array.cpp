// 2179. Count Good Triplets in an Array

// You are given two 0-indexed arrays nums1 and nums2 of length n, both of which are permutations of [0, 1, ..., n - 1].

// A good triplet is a set of 3 distinct values which are present in increasing order by position both in nums1 and nums2. In other words, if we consider pos1v as the index of the value v in nums1 and pos2v as the index of the value v in nums2, then a good triplet will be a set (x, y, z) where 0 <= x, y, z <= n - 1, such that pos1x < pos1y < pos1z and pos2x < pos2y < pos2z.

// Return the total number of good triplets.

 

// Example 1:

// Input: nums1 = [2,0,1,3], nums2 = [0,1,2,3]
// Output: 1
// Explanation: 
// There are 4 triplets (x,y,z) such that pos1x < pos1y < pos1z. They are (2,0,1), (2,0,3), (2,1,3), and (0,1,3). 
// Out of those triplets, only the triplet (0,1,3) satisfies pos2x < pos2y < pos2z. Hence, there is only 1 good triplet.
// Example 2:

// Input: nums1 = [4,0,1,3,2], nums2 = [4,1,0,2,3]
// Output: 4
// Explanation: The 4 good triplets are (4,0,3), (4,0,2), (4,1,3), and (4,1,2).
 

// Constraints:

// n == nums1.length == nums2.length
// 3 <= n <= 105
// 0 <= nums1[i], nums2[i] <= n - 1
// nums1 and nums2 are permutations of [0, 1, ..., n - 1].

class Solution
{
public:
    using ll = long long;
    vector<ll> bit1, bit2;
    int n;

    void update(vector<ll> &bit, int i, ll val)
    {
        for (++i; i <= n; i += (i & -i))
            bit[i] += val;
    }

    ll query(const vector<ll> &bit, int i)
    {
        ll res = 0;
        for (++i; i > 0; i -= (i & -i))
            res += bit[i];
        return res;
    }

    long long goodTriplets(vector<int> &nums1, vector<int> &nums2)
    {
        n = nums1.size();
        vector<int> pos(n);
        for (int i = 0; i < n; ++i)
            pos[nums2[i]] = i;
        for (int i = 0; i < n; ++i)
            nums1[i] = pos[nums1[i]];

        bit1.assign(n + 2, 0);
        bit2.assign(n + 2, 0);
        ll ans = 0;

        for (int i = n - 1; i >= 0; --i)
        {
            int x = nums1[i];
            ll val = query(bit1, n - 1) - query(bit1, x);
            ll trip = query(bit2, n - 1) - query(bit2, x);
            ans += trip;
            update(bit2, x, val);
            update(bit1, x, 1);
        }

        return ans;
    }
};

/*
This solution uses Binary Indexed Tree (BIT/Fenwick Tree) to efficiently count good triplets.

Algorithm explanation:
1. First, we create a position mapping for nums2 to convert nums1 into relative positions.
2. We use two BITs:
   - bit1: Counts elements to the right
   - bit2: Stores number of possible pairs to the right
3. We iterate from right to left:
   - For each element, we count larger elements to its right (val)
   - Count number of triplets possible with current element (trip)
   - Update BITs accordingly

Time Complexity: O(n log n) where n is the length of input arrays
- BIT operations (update and query) take O(log n)
- We perform these operations O(n) times

Space Complexity: O(n)
- Two BIT arrays of size n+2
- Position array of size n
*/