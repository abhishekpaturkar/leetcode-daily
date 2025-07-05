// 1394. Find Lucky Integer in an Array

// Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.

// Return the largest lucky integer in the array. If there is no lucky integer return -1.

 

// Example 1:

// Input: arr = [2,2,3,4]
// Output: 2
// Explanation: The only lucky number in the array is 2 because frequency[2] == 2.
// Example 2:

// Input: arr = [1,2,2,3,3,3]
// Output: 3
// Explanation: 1, 2 and 3 are all lucky numbers, return the largest of them.
// Example 3:

// Input: arr = [2,2,2,3,3]
// Output: -1
// Explanation: There are no lucky numbers in the array.
 

// Constraints:

// 1 <= arr.length <= 500
// 1 <= arr[i] <= 500

class Solution
{
public:
    int findLucky(vector<int> &arr)
    {
        int ans = 0;
        unordered_map<int, int> mp;
        
        for(auto i : arr) {
            mp[i]++;
        }

        for(auto m : mp) {
            if(m.first == m.second) {
                ans = max(ans, m.first);
            }
        }

        return ans ? ans : -1;
    }
};

/*
Code Explanation:
This solution finds the largest lucky integer in an array where a lucky integer is defined as a number whose frequency equals its value.

1. We initialize ans = 0 to store the largest lucky number
2. Create an unordered_map 'mp' to store frequency of each number
3. First loop counts frequency of each number in array
4. Second loop checks if any number's value equals its frequency
5. If found, update ans with maximum of current ans and lucky number
6. Finally return ans if found (non-zero), else return -1

Time Complexity: O(n) where n is length of input array
- First loop takes O(n) to count frequencies
- Second loop takes O(k) where k is unique numbers in array (k ≤ n)

Space Complexity: O(n) to store the frequency map
*/