// 869. Reordered Power of 2

// You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.

// Return true if and only if we can do this so that the resulting number is a power of two.

 

// Example 1:

// Input: n = 1
// Output: true
// Example 2:

// Input: n = 10
// Output: false
 

// Constraints:

// 1 <= n <= 109

class Solution
{
public:
    bool reorderedPowerOf2(int n)
    {

        string n1 = to_string(n);
        sort(n1.begin(), n1.end());

        for (int i = 0; i < 30; i++)
        {

            string n2 = to_string(1 << i);
            sort(n2.begin(), n2.end());

            if (n1 == n2)
                return true;
        }
        return false;
    }
};