// 2048. Next Greater Numerically Balanced Number

// An integer x is numerically balanced if for every digit d in the number x, there are exactly d occurrences of that digit in x.

// Given an integer n, return the smallest numerically balanced number strictly greater than n.

 

// Example 1:

// Input: n = 1
// Output: 22
// Explanation: 
// 22 is numerically balanced since:
// - The digit 2 occurs 2 times. 
// It is also the smallest numerically balanced number strictly greater than 1.
// Example 2:

// Input: n = 1000
// Output: 1333
// Explanation: 
// 1333 is numerically balanced since:
// - The digit 1 occurs 1 time.
// - The digit 3 occurs 3 times. 
// It is also the smallest numerically balanced number strictly greater than 1000.
// Note that 1022 cannot be the answer because 0 appeared more than 0 times.
// Example 3:

// Input: n = 3000
// Output: 3133
// Explanation: 
// 3133 is numerically balanced since:
// - The digit 1 occurs 1 time.
// - The digit 3 occurs 3 times.
// It is also the smallest numerically balanced number strictly greater than 3000.
 

// Constraints:

// 0 <= n <= 106

class Solution
{
public:
    int nextBeautifulNumber(int n)
    {
        vector<int> list;
        vector<int> count(10, 0);
        generate(0, count, list);
        sort(list.begin(), list.end());
        for (int num : list)
        {
            if (num > n)
                return num;
        }
        return -1;
    }

    void generate(long num, vector<int> &count, vector<int> &list)
    {
        if (num > 0 && isBeautiful(count))
        {
            list.push_back((int)num);
        }
        if (num > 1224444)
            return;

        for (int d = 1; d <= 7; ++d)
        {
            if (count[d] < d)
            {
                count[d]++;
                generate(num * 10 + d, count, list);
                count[d]--;
            }
        }
    }

    bool isBeautiful(const vector<int> &count)
    {
        for (int d = 1; d <= 7; ++d)
        {
            if (count[d] != 0 && count[d] != d)
                return false;
        }
        return true;
    }
};