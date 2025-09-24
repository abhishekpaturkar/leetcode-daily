// 166. Fraction to Recurring Decimal

// Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

// If the fractional part is repeating, enclose the repeating part in parentheses.

// If multiple answers are possible, return any of them.

// It is guaranteed that the length of the answer string is less than 104 for all the given inputs.

 

// Example 1:

// Input: numerator = 1, denominator = 2
// Output: "0.5"
// Example 2:

// Input: numerator = 2, denominator = 1
// Output: "2"
// Example 3:

// Input: numerator = 4, denominator = 333
// Output: "0.(012)"
 

// Constraints:

// -231 <= numerator, denominator <= 231 - 1
// denominator != 0

// a variant with several considerations
// use reduced fraction
// judge if it has finitely many decimals; if yes, no need hashmap
class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        if (numerator == 0)
            return "0";

        string ans;
        // Handle sign
        if ((numerator < 0) ^ (denominator < 0))
            ans += '-';
        // Convert to long to avoid overflow (INT_MIN)
        long long num = abs((long long)numerator);
        long long den = abs((long long)denominator);

        int g = gcd(num, den);
        num /= g, den /= g; // consider reduced fraction

        long long q = num / den;
        long long r = num % den;
        ans += to_string(q);

        if (r == 0)
            return ans;

        // judge whether it has finite many decimals
        int factor_wo2_5 = den;
        int bz = __builtin_ctzll(factor_wo2_5);
        factor_wo2_5 >>= bz;
        while (factor_wo2_5 % 5 == 0)
            factor_wo2_5 /= 5;
        bool finteDecimal = factor_wo2_5 == 1;

        ans += '.';
        unordered_map<long long, int> mp;
        string frac;

        for (int i = 0; r != 0; i++)
        {
            if (!finteDecimal)
            {
                auto it = mp.find(r);
                if (it != mp.end())
                {
                    frac.insert(it->second, "(");
                    frac += ')';
                    break;
                }
                mp[r] = i;
            }
            r *= 10;
            frac += ('0' + r / den);
            r %= den;
        }

        return ans + frac;
    }
};