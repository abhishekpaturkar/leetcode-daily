// 2099. Find Subsequence of Length K With the Largest Sum

// You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.

// Return any such subsequence as an integer array of length k.

// A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.


// Example 1:

// Input: nums = [2,1,3,3], k = 2
// Output: [3,3]
// Explanation:
// The subsequence has the largest sum of 3 + 3 = 6.
// Example 2:

// Input: nums = [-1,-2,3,4], k = 3
// Output: [-1,3,4]
// Explanation: 
// The subsequence has the largest sum of -1 + 3 + 4 = 6.
// Example 3:

// Input: nums = [3,4,3,3], k = 2
// Output: [3,4]
// Explanation:
// The subsequence has the largest sum of 3 + 4 = 7. 
// Another possible subsequence is [4, 3].
 

// Constraints:

// 1 <= nums.length <= 1000
// -105 <= nums[i] <= 105
// 1 <= k <= nums.length

class Solution
{
public:
    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        vector<pair<int, int>> numsWithIndices;
        for (int i = 0; i < nums.size(); i++)
        {
            numsWithIndices.push_back({nums[i], i});
        }

        // Sort by value descending
        sort(numsWithIndices.begin(), numsWithIndices.end(),
             [](const pair<int, int> &a, const pair<int, int> &b)
             {
                 return a.first > b.first;
             });

        // Take top k and sort by original index
        vector<pair<int, int>> topK(numsWithIndices.begin(), numsWithIndices.begin() + k);
        sort(topK.begin(), topK.end(),
             [](const pair<int, int> &a, const pair<int, int> &b)
             {
                 return a.second < b.second;
             });

        // Extract values
        vector<int> result;
        for (auto &p : topK)
        {
            result.push_back(p.first);
        }

        return result;
    }
};

/*
Code Explanation:
1. First, we create a vector of pairs where each pair contains the number and its original index.
2. Then we sort this vector in descending order based on the numbers (first element of pair).
3. We take the first k pairs which represent the k largest numbers.
4. We sort these k pairs based on their original indices to maintain the relative order.
5. Finally, we extract just the numbers from these pairs into our result vector.

Time Complexity: O(nlogn) where n is the length of input array
- Creating pairs array: O(n)
- First sort: O(nlogn)
- Taking k elements: O(k)
- Second sort: O(klogk)
- Creating result: O(k)
Overall: O(nlogn) as n > k

Space Complexity: O(n)
- numsWithIndices vector: O(n)
- topK vector: O(k)
- result vector: O(k)
Overall: O(n) as n > k
*/