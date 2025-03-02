// 2570. Merge Two 2D Arrays by Summing Values

// You are given two 2D integer arrays nums1 and nums2.

// nums1[i] = [idi, vali] indicate that the number with the id idi has a value equal to vali.
// nums2[i] = [idi, vali] indicate that the number with the id idi has a value equal to vali.
// Each array contains unique ids and is sorted in ascending order by id.

// Merge the two arrays into one array that is sorted in ascending order by id, respecting the following conditions:

// Only ids that appear in at least one of the two arrays should be included in the resulting array.
// Each id should be included only once and its value should be the sum of the values of this id in the two arrays. If the id does not exist in one of the two arrays, then assume its value in that array to be 0.
// Return the resulting array. The returned array must be sorted in ascending order by id.

 

// Example 1:

// Input: nums1 = [[1,2],[2,3],[4,5]], nums2 = [[1,4],[3,2],[4,1]]
// Output: [[1,6],[2,3],[3,2],[4,6]]
// Explanation: The resulting array contains the following:
// - id = 1, the value of this id is 2 + 4 = 6.
// - id = 2, the value of this id is 3.
// - id = 3, the value of this id is 2.
// - id = 4, the value of this id is 5 + 1 = 6.
// Example 2:

// Input: nums1 = [[2,4],[3,6],[5,5]], nums2 = [[1,3],[4,3]]
// Output: [[1,3],[2,4],[3,6],[4,3],[5,5]]
// Explanation: There are no common ids, so we just include each id with its value in the resulting list.
 

// Constraints:

// 1 <= nums1.length, nums2.length <= 200
// nums1[i].length == nums2[j].length == 2
// 1 <= idi, vali <= 1000
// Both arrays contain unique ids.
// Both arrays are in strictly ascending order by id.

class Solution
{
public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
    {
        int ptr1 = 0, ptr2 = 0;
        vector<vector<int>> res;

        while (ptr1 < nums1.size() && ptr2 < nums2.size())
        {
            if (nums1[ptr1][0] < nums2[ptr2][0])
            {
                res.push_back(nums1[ptr1++]);
            }
            else if (nums1[ptr1][0] > nums2[ptr2][0])
            {
                res.push_back(nums2[ptr2++]);
            }
            else
                res.push_back({nums1[ptr1][0], nums1[ptr1++][1] + nums2[ptr2++][1]});
        }

        // we still have some pairs left in nums1
        while (ptr1 < nums1.size())
        {
            res.push_back(nums1[ptr1++]);
        }

        // we still have some pairs left in nums2
        while (ptr2 < nums2.size())
        {
            res.push_back(nums2[ptr2++]);
        }

        return res;
    }
};

/*
This code merges two 2D arrays by summing values with matching IDs. Here's how it works:

1. Two pointers (ptr1 and ptr2) track positions in nums1 and nums2
2. Main while loop compares IDs from both arrays:
   - If ID from nums1 is smaller, add that pair to result
   - If ID from nums2 is smaller, add that pair to result
   - If IDs match, add pair with same ID and sum of values
3. After main loop, add any remaining pairs from either array
4. Returns merged array sorted by ID with summed values

The solution uses a two-pointer technique for O(n) time complexity where n is total length of both arrays.
*/