// 2594. Minimum Time to Repair Cars

// You are given an integer array ranks representing the ranks of some mechanics. ranksi is the rank of the ith mechanic. A mechanic with a rank r can repair n cars in r * n2 minutes.

// You are also given an integer cars representing the total number of cars waiting in the garage to be repaired.

// Return the minimum time taken to repair all the cars.

// Note: All the mechanics can repair the cars simultaneously.
 

// Example 1:

// Input: ranks = [4,2,3,1], cars = 10
// Output: 16
// Explanation: 
// - The first mechanic will repair two cars. The time required is 4 * 2 * 2 = 16 minutes.
// - The second mechanic will repair two cars. The time required is 2 * 2 * 2 = 8 minutes.
// - The third mechanic will repair two cars. The time required is 3 * 2 * 2 = 12 minutes.
// - The fourth mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
// It can be proved that the cars cannot be repaired in less than 16 minutes.​​​​​
// Example 2:

// Input: ranks = [5,1,8], cars = 6
// Output: 16
// Explanation: 
// - The first mechanic will repair one car. The time required is 5 * 1 * 1 = 5 minutes.
// - The second mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
// - The third mechanic will repair one car. The time required is 8 * 1 * 1 = 8 minutes.
// It can be proved that the cars cannot be repaired in less than 16 minutes.​​​​​
 

// Constraints:

// 1 <= ranks.length <= 105
// 1 <= ranks[i] <= 100
// 1 <= cars <= 106

class Solution
{
public:
    bool solve(long long res, vector<int> &ranks, int cars)
    {
        long long cnt = 0;
        for (int i = 0; i < ranks.size(); i++)
        {
            cnt += sqrt((res * 1.0) / ranks[i]);
        }

        return cnt >= cars * 1LL;
    }
    long long repairCars(vector<int> &ranks, int cars)
    {

        long long low = 1;
        long long high = *max_element(ranks.begin(), ranks.end()) * 1LL * cars * cars;

        long long ans = high;

        while (low <= high)
        {
            long long mid = (low + high) / 2;
            if (solve(mid, ranks, cars))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};

/*
This code implements a solution to find the minimum time required to repair all cars given mechanics with different ranks.

The solution uses binary search to find the optimal time:

1. The solve() function checks if it's possible to repair all cars within a given time:
   - For each mechanic, calculates how many cars they can repair in the given time
   - Returns true if total cars that can be repaired >= required cars

2. The repairCars() function:
   - Uses binary search between 1 and maximum possible time needed
   - For each mid point, checks if cars can be repaired in that time using solve()
   - Updates answer when a valid time is found and continues searching for minimum

Time Complexity: O(n * log(k)) where n = number of mechanics, k = cars * max_rank
Space Complexity: O(1) as only constant extra space is used
*/