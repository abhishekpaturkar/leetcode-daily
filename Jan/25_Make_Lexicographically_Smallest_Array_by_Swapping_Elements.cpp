// 2948. Make Lexicographically Smallest Array by Swapping Elements
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given a 0-indexed array of positive integers nums and a positive integer limit.

// In one operation, you can choose any two indices i and j and swap nums[i] and nums[j] if |nums[i] - nums[j]| <= limit.

// Return the lexicographically smallest array that can be obtained by performing the operation any number of times.

// An array a is lexicographically smaller than an array b if in the first position where a and b differ, array a has an element that is less than the corresponding element in b. For example, the array [2,10,3] is lexicographically smaller than the array [10,2,3] because they differ at index 0 and 2 < 10.

 

// Example 1:

// Input: nums = [1,5,3,9,8], limit = 2
// Output: [1,3,5,8,9]
// Explanation: Apply the operation 2 times:
// - Swap nums[1] with nums[2]. The array becomes [1,3,5,9,8]
// - Swap nums[3] with nums[4]. The array becomes [1,3,5,8,9]
// We cannot obtain a lexicographically smaller array by applying any more operations.
// Note that it may be possible to get the same result by doing different operations.
// Example 2:

// Input: nums = [1,7,6,18,2,1], limit = 3
// Output: [1,6,7,18,1,2]
// Explanation: Apply the operation 3 times:
// - Swap nums[1] with nums[2]. The array becomes [1,6,7,18,2,1]
// - Swap nums[0] with nums[4]. The array becomes [2,6,7,18,1,1]
// - Swap nums[0] with nums[5]. The array becomes [1,6,7,18,1,2]
// We cannot obtain a lexicographically smaller array by applying any more operations.
// Example 3:

// Input: nums = [1,7,28,19,10], limit = 3
// Output: [1,7,28,19,10]
// Explanation: [1,7,28,19,10] is the lexicographically smallest array we can obtain because we cannot apply the operation on any two indices.
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 109
// 1 <= limit <= 109

class Solution
{
public:
    vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit)
    {
        vector<int> numsSorted(nums);
        sort(numsSorted.begin(), numsSorted.end());

        int currGroup = 0;
        unordered_map<int, int> numToGroup;
        numToGroup.insert(pair<int, int>(numsSorted[0], currGroup));

        unordered_map<int, list<int>> groupToList;
        groupToList.insert(
            pair<int, list<int>>(currGroup, list<int>(1, numsSorted[0])));

        for (int i = 1; i < nums.size(); i++)
        {
            if (abs(numsSorted[i] - numsSorted[i - 1]) > limit)
            {
                // new group
                currGroup++;
            }

            // assign current element to group
            numToGroup.insert(pair<int, int>(numsSorted[i], currGroup));

            // add element to sorted group list
            if (groupToList.find(currGroup) == groupToList.end())
            {
                groupToList[currGroup] = list<int>();
            }
            groupToList[currGroup].push_back(numsSorted[i]);
        }

        // iterate through input and overwrite each element with the next
        // element in its corresponding group
        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            int group = numToGroup[num];
            nums[i] = *groupToList[group].begin();
            groupToList[group].pop_front();
        }

        return nums;
    }
};

/*
This code implements a solution to make an array lexicographically smallest by swapping elements within a given limit. Here's how it works:

1. First, it creates a sorted copy of the input array.

2. It then groups numbers together based on the limit condition - if the difference between consecutive sorted numbers is within the limit, they belong to the same group.

3. It maintains two maps:
   - numToGroup: maps each number to its group ID
   - groupToList: maps each group ID to a sorted list of numbers in that group

4. The first loop creates these groups by:
   - Starting a new group when difference exceeds limit
   - Assigning numbers to groups
   - Building sorted lists for each group

5. The second loop reconstructs the array by:
   - For each original number, finding its group
   - Taking the smallest remaining number from that group
   - Replacing the original number with this smallest available number

This ensures the array becomes as lexicographically small as possible while respecting the limit constraint on swaps.
*/