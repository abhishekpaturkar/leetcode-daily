// 2094. Finding 3-Digit Even Numbers

// You are given an integer array digits, where each element is a digit. The array may contain duplicates.

// You need to find all the unique integers that follow the given requirements:

// The integer consists of the concatenation of three elements from digits in any arbitrary order.
// The integer does not have leading zeros.
// The integer is even.
// For example, if the given digits were [1, 2, 3], integers 132 and 312 follow the requirements.

// Return a sorted array of the unique integers.

 

// Example 1:

// Input: digits = [2,1,3,0]
// Output: [102,120,130,132,210,230,302,310,312,320]
// Explanation: All the possible integers that follow the requirements are in the output array. 
// Notice that there are no odd integers or integers with leading zeros.
// Example 2:

// Input: digits = [2,2,8,8,2]
// Output: [222,228,282,288,822,828,882]
// Explanation: The same digit can be used as many times as it appears in digits. 
// In this example, the digit 8 is used twice each time in 288, 828, and 882. 
// Example 3:

// Input: digits = [3,7,5]
// Output: []
// Explanation: No even integers can be formed using the given digits.
 

// Constraints:

// 3 <= digits.length <= 100
// 0 <= digits[i] <= 9

class Solution
{
public:
    vector<int> findEvenNumbers(vector<int> &digits)
    {
        set<int> nums;
        int n = digits.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (i == j || j == k || i == k)
                    {
                        continue;
                    }
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if (num >= 100 && num % 2 == 0)
                    {
                        nums.insert(num);
                    }
                }
            }
        }

        vector<int> ans;
        for (const int i : nums)
        {
            ans.push_back(i);
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

/*
Code Explanation:
This solution finds all possible 3-digit even numbers that can be formed using the given digits array.

1. We use a set 'nums' to store unique numbers to avoid duplicates
2. Using three nested loops (i,j,k), we try all possible combinations of digits
3. Skip if any two indices are same to avoid using same digit at same position
4. Form number by: hundreds place (i) * 100 + tens place (j) * 10 + ones place (k)
5. Check if number is >= 100 (3 digits) and even
6. Store valid numbers in set
7. Convert set to vector and sort it before returning

Time Complexity: O(n³ + klogk) where n is length of digits array, k is number of valid combinations
- n³ for three nested loops
- klogk for sorting final array

Space Complexity: O(k) where k is number of valid combinations
- Space used by set and final vector
*/