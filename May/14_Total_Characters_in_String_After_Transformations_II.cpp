// 3337. Total Characters in String After Transformations II

// You are given a string s consisting of lowercase English letters, an integer t representing the number of transformations to perform, and an array nums of size 26. In one transformation, every character in s is replaced according to the following rules:

// Replace s[i] with the next nums[s[i] - 'a'] consecutive characters in the alphabet. For example, if s[i] = 'a' and nums[0] = 3, the character 'a' transforms into the next 3 consecutive characters ahead of it, which results in "bcd".
// The transformation wraps around the alphabet if it exceeds 'z'. For example, if s[i] = 'y' and nums[24] = 3, the character 'y' transforms into the next 3 consecutive characters ahead of it, which results in "zab".
// Return the length of the resulting string after exactly t transformations.

// Since the answer may be very large, return it modulo 109 + 7.

 

// Example 1:

// Input: s = "abcyy", t = 2, nums = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2]

// Output: 7

// Explanation:

// First Transformation (t = 1):

// 'a' becomes 'b' as nums[0] == 1
// 'b' becomes 'c' as nums[1] == 1
// 'c' becomes 'd' as nums[2] == 1
// 'y' becomes 'z' as nums[24] == 1
// 'y' becomes 'z' as nums[24] == 1
// String after the first transformation: "bcdzz"
// Second Transformation (t = 2):

// 'b' becomes 'c' as nums[1] == 1
// 'c' becomes 'd' as nums[2] == 1
// 'd' becomes 'e' as nums[3] == 1
// 'z' becomes 'ab' as nums[25] == 2
// 'z' becomes 'ab' as nums[25] == 2
// String after the second transformation: "cdeabab"
// Final Length of the string: The string is "cdeabab", which has 7 characters.

// Example 2:

// Input: s = "azbk", t = 1, nums = [2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2]

// Output: 8

// Explanation:

// First Transformation (t = 1):

// 'a' becomes 'bc' as nums[0] == 2
// 'z' becomes 'ab' as nums[25] == 2
// 'b' becomes 'cd' as nums[1] == 2
// 'k' becomes 'lm' as nums[10] == 2
// String after the first transformation: "bcabcdlm"
// Final Length of the string: The string is "bcabcdlm", which has 8 characters.

 

// Constraints:

// 1 <= s.length <= 105
// s consists only of lowercase English letters.
// 1 <= t <= 109
// nums.length == 26
// 1 <= nums[i] <= 25

using ll = long long;

class Solution
{
public:
    const int mod = 1e9 + 7;

    vector<vector<ll>> multiplyMatrices(const vector<vector<ll>> &A, const vector<vector<ll>> &B)
    {
        int rowsA = A.size(), colsA = A[0].size(), colsB = B[0].size();
        vector<vector<__int128_t>> temp(rowsA, vector<__int128_t>(colsB, 0));
        vector<vector<ll>> result(rowsA, vector<ll>(colsB, 0));

        for (int i = 0; i < rowsA; i++)
        {
            for (int j = 0; j < colsB; j++)
            {
                for (int k = 0; k < colsA; k++)
                {
                    temp[i][j] += A[i][k] * B[k][j];
                }
                result[i][j] = temp[i][j] % mod;
            }
        }
        return result;
    }

    vector<vector<ll>> powerMatrix(vector<vector<ll>> matrix, ll exponent)
    {
        vector<vector<ll>> result(matrix.size(), vector<ll>(matrix.size(), 0));

        for (int i = 0; i < matrix.size(); i++)
            result[i][i] = 1;

        while (exponent > 0)
        {
            if (exponent % 2 == 1)
                result = multiplyMatrices(result, matrix);
            matrix = multiplyMatrices(matrix, matrix);
            exponent /= 2;
        }
        return result;
    }

    int lengthAfterTransformations(string s, int t, vector<int> &nums)
    {
        vector<vector<ll>> transform(26, vector<ll>(26, 0));

        for (int i = 0; i < 26; i++)
        {
            for (int shift = 0; shift < nums[i]; shift++)
            {
                transform[i][(i + 1 + shift) % 26]++;
            }
        }

        transform = powerMatrix(transform, t);
        vector<vector<ll>> freq(1, vector<ll>(26, 0));
        for (char ch : s)
        {
            freq[0][ch - 'a']++;
        }

        freq = multiplyMatrices(freq, transform);
        int totalLength = 0;
        for (int count : freq[0])
        {
            totalLength += count;
            if (totalLength >= mod)
                totalLength -= mod;
        }

        return totalLength;
    }
};

/*
This code solves the problem of finding the length of a string after applying a series of transformations.

The solution uses matrix exponentiation to efficiently handle large number of transformations:

1. First, it creates a transformation matrix where each cell [i][j] represents how many times character i transforms into character j.

2. The powerMatrix function uses binary exponentiation to compute the transformation matrix raised to power t efficiently.

3. For matrix multiplication, it uses __int128_t to handle intermediate calculations without overflow.

4. The frequency vector keeps track of count of each character.

5. Final result is computed by multiplying initial frequency with transformed matrix.

Time Complexity:
- Matrix multiplication: O(N^3) where N = 26 (alphabet size)
- Binary exponentiation: O(log t) where t is number of transformations
- Overall: O(N^3 * log t) = O(log t) since N is constant (26)

Space Complexity:
- O(N^2) = O(1) for transformation matrix where N = 26
*/