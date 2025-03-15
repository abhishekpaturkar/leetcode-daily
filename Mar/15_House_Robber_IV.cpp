// 2560. House Robber IV

// There are several consecutive houses along a street, each of which has some money inside. There is also a robber, who wants to steal money from the homes, but he refuses to steal from adjacent homes.

// The capability of the robber is the maximum amount of money he steals from one house of all the houses he robbed.

// You are given an integer array nums representing how much money is stashed in each house. More formally, the ith house from the left has nums[i] dollars.

// You are also given an integer k, representing the minimum number of houses the robber will steal from. It is always possible to steal at least k houses.

// Return the minimum capability of the robber out of all the possible ways to steal at least k houses.

 
// Example 1:

// Input: nums = [2,3,5,9], k = 2
// Output: 5
// Explanation: 
// There are three ways to rob at least 2 houses:
// - Rob the houses at indices 0 and 2. Capability is max(nums[0], nums[2]) = 5.
// - Rob the houses at indices 0 and 3. Capability is max(nums[0], nums[3]) = 9.
// - Rob the houses at indices 1 and 3. Capability is max(nums[1], nums[3]) = 9.
// Therefore, we return min(5, 9, 9) = 5.
// Example 2:

// Input: nums = [2,7,9,3,1], k = 2
// Output: 2
// Explanation: There are 7 ways to rob the houses. The way which leads to minimum capability is to rob the house at index 0 and 4. Return max(nums[0], nums[4]) = 2.
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 109
// 1 <= k <= (nums.length + 1)/2

class Solution
{
public:
    bool canRob(vector<int> &nums, int mid, int k)
    {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= mid)
            {
                count++;
                i++;
            }
        }
        return count >= k;
    }

    int minCapability(vector<int> &nums, int k)
    {
        int left = 1, right = *max_element(nums.begin(), nums.end()), ans = right;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (canRob(nums, mid, k))
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }
};

/*
This solution uses binary search to find the minimum capability needed to rob at least k houses.

The minCapability function:
- Uses binary search between 1 and the maximum element in nums
- For each mid point, checks if we can rob k houses with that capability
- If possible, tries to minimize further by searching in lower half
- If not possible, searches in upper half
- Returns the minimum valid capability found

The canRob helper function:
- Checks if we can rob k houses with given capability (mid)
- Iterates through houses, counting how many we can rob
- Can rob a house if its value <= capability
- Skips adjacent house after robbing one
- Returns true if we can rob at least k houses

Time Complexity: O(n * log M) where n is length of nums and M is maximum element
Space Complexity: O(1) as we only use constant extra space
*/