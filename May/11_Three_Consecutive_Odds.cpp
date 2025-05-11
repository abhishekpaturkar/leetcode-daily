// 1550. Three Consecutive Odds

// Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.
 

// Example 1:

// Input: arr = [2,6,4,1]
// Output: false
// Explanation: There are no three consecutive odds.
// Example 2:

// Input: arr = [1,2,34,3,4,5,7,23,12]
// Output: true
// Explanation: [5,7,23] are three consecutive odds.
 

// Constraints:

// 1 <= arr.length <= 1000
// 1 <= arr[i] <= 1000

class Solution
{
public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        int ans = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] % 2 != 0)
            {
                ans++;
                if (ans == 3)
                {
                    return true;
                }
            }
            else
            {
                ans = 0;
            }
        }
        return false;
    }
};

/*
This code checks if there are three consecutive odd numbers in the given array.
It maintains a counter 'ans' that keeps track of consecutive odd numbers encountered.
For each number in array:
- If number is odd (arr[i] % 2 != 0), increment counter
- If counter reaches 3, return true as we found 3 consecutive odds
- If number is even, reset counter to 0
If loop completes without finding 3 consecutive odds, return false

Time Complexity: O(n) where n is length of array
Space Complexity: O(1) as only constant extra space is used
*/