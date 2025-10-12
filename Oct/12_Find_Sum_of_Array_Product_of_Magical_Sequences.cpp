// 3539. Find Sum of Array Product of Magical Sequences

// You are given two integers, m and k, and an integer array nums.

// A sequence of integers seq is called magical if:
// seq has a size of m.
// 0 <= seq[i] < nums.length
// The binary representation of 2seq[0] + 2seq[1] + ... + 2seq[m - 1] has k set bits.
// The array product of this sequence is defined as prod(seq) = (nums[seq[0]] * nums[seq[1]] * ... * nums[seq[m - 1]]).

// Return the sum of the array products for all valid magical sequences.

// Since the answer may be large, return it modulo 109 + 7.

// A set bit refers to a bit in the binary representation of a number that has a value of 1.

 

// Example 1:

// Input: m = 5, k = 5, nums = [1,10,100,10000,1000000]

// Output: 991600007

// Explanation:

// All permutations of [0, 1, 2, 3, 4] are magical sequences, each with an array product of 1013.

// Example 2:

// Input: m = 2, k = 2, nums = [5,4,3,2,1]

// Output: 170

// Explanation:

// The magical sequences are [0, 1], [0, 2], [0, 3], [0, 4], [1, 0], [1, 2], [1, 3], [1, 4], [2, 0], [2, 1], [2, 3], [2, 4], [3, 0], [3, 1], [3, 2], [3, 4], [4, 0], [4, 1], [4, 2], and [4, 3].

// Example 3:

// Input: m = 1, k = 1, nums = [28]

// Output: 28

// Explanation:

// The only magical sequence is [0].

 

// Constraints:

// 1 <= k <= m <= 30
// 1 <= nums.length <= 50
// 1 <= nums[i] <= 108

static constexpr int MOD = 1e9 + 7;
static int C[31][31] = {{0}};
class Solution
{
    int m, k, n;
    void Pascal()
    {
        if (C[0][0] == 1)
            return; // compute only once
        for (int i = 1; i <= 30; i++)
        {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j <= i / 2; j++)
            {
                const int Cij = C[i - 1][j - 1] + C[i - 1][j];
                // if (Cij>=mod) Cij-=mod;
                C[i][j] = C[i][i - j] = Cij;
                // cout<<Cij<<","; } // cout<<endl;
            }
        }
    }

    long long modPow(long long x, unsigned exp, int mod = MOD)
    {
        if (exp == 0)
            return 1;
        const int bM = 31 - countl_zero(exp);
        bitset<32> B(exp);
        long long y = x;
        for (int b = bM - 1; b >= 0; b--)
            y = (y * y % mod) * (B[b] ? x : 1) % mod;
        return y;
    }
    unordered_map<int, int> dp;
    int dfs(int m, int k, int i, unsigned flag, vector<int> &nums)
    {
        const int bz = popcount(flag);
        if (m < 0 || k < 0 || m + bz < k)
            return 0;
        if (m == 0)
            return (k == bz) ? 1 : 0;
        if (i >= n)
            return 0;

        uint64_t key = (m << 5) | (k << 10) | (i << 16) | flag;
        auto it = dp.find(key);
        if (it != dp.end())
            return it->second;

        long long ans = 0;
        for (int f = 0; f <= m; f++)
        {
            long long perm = C[m][f] * modPow(nums[i], f) % MOD;

            unsigned newFlag = flag + f;
            unsigned nextFlag = newFlag >> 1;
            bool bitContribution = newFlag & 1;

            ans = (ans + perm * dfs(m - f, k - bitContribution, i + 1, nextFlag, nums)) % MOD;
        }

        return dp[key] = ans;
    }

public:
    int magicalSum(int m, int k, vector<int> &nums)
    {
        Pascal();
        this->m = m;
        this->k = k;
        n = nums.size();

        return dfs(m, k, 0, 0, nums);
    }
};
