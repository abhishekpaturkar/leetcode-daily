// 1534. Count Good Triplets

// Given an array of integers arr, and three integers a, b and c. You need to find the number of good triplets.

// A triplet (arr[i], arr[j], arr[k]) is good if the following conditions are true:

// 0 <= i < j < k < arr.length
// |arr[i] - arr[j]| <= a
// |arr[j] - arr[k]| <= b
// |arr[i] - arr[k]| <= c
// Where |x| denotes the absolute value of x.

// Return the number of good triplets.

// Example 1:

// Input: arr = [3,0,1,1,9,7], a = 7, b = 2, c = 3
// Output: 4
// Explanation: There are 4 good triplets: [(3,0,1), (3,0,1), (3,1,1), (0,1,1)].
// Example 2:

// Input: arr = [1,1,2,2,3], a = 0, b = 0, c = 1
// Output: 0
// Explanation: No triplet satisfies all conditions.

// Constraints:

// 3 <= arr.length <= 100
// 0 <= arr[i] <= 1000
// 0 <= a, b, c <= 1000

class Solution
{
public:
    int countGoodTriplets(vector<int> &arr, int a, int b, int c)
    {
        int good = 0;
        for (int i = 0; i < arr.size() - 2; i++)
        {
            for (int k = i + 2; k < arr.size(); k++)
            {
                if (abs(arr[k] - arr[i]) > c)
                    continue;
                for (int j = i + 1; j < k; j++)
                    if (abs(arr[i] - arr[j]) <= a &&
                        abs(arr[j] - arr[k]) <= b)
                        ++good;
            }
        }
        return good;
    }
};

/*
This solution finds good triplets by using three nested loops:
1. Outer loop (i) selects the first element
2. Middle loop (k) selects the third element
3. Inner loop (j) selects the middle element

The code optimizes by:
- Checking arr[i] and arr[k] condition first to skip unnecessary iterations
- Using continue statement to avoid deeper nesting
- Incrementing counter only when all conditions are met

Time Complexity: O(n^3) where n is the length of array
Space Complexity: O(1) as only constant extra space is used
*/