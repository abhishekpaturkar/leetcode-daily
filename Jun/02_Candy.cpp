// 135. Candy

// There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

// You are giving candies to these children subjected to the following requirements:

// Each child must have at least one candy.
// Children with a higher rating get more candies than their neighbors.
// Return the minimum number of candies you need to have to distribute the candies to the children.

 

// Example 1:

// Input: ratings = [1,0,2]
// Output: 5
// Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
// Example 2:

// Input: ratings = [1,2,2]
// Output: 4
// Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
// The third child gets 1 candy because it satisfies the above two conditions.
 

// Constraints:

// n == ratings.length
// 1 <= n <= 2 * 104
// 0 <= ratings[i] <= 2 * 104

class Solution
{
public:
    int candy(vector<int> &ratings, int cnt = 0)
    {
        int n = ratings.size();
        vector<int> candies(n, 1);

        for (int i = 1; i < n; i++)
            if (ratings[i] > ratings[i - 1])
                candies[i] = candies[i - 1] + 1;

        for (int i = n - 1; i > 0; i--)
        {
            if (ratings[i - 1] > ratings[i])
                candies[i - 1] = max(candies[i] + 1, candies[i - 1]);
            cnt += candies[i - 1];
        }
        return cnt + candies[n - 1];
    }
};

/*
This code solves the candy distribution problem where each child must get at least one candy and children with higher ratings must get more candies than their neighbors.

The solution uses a two-pass approach:
1. First pass (left to right): Ensures children with higher ratings get more candies than their left neighbor
2. Second pass (right to left): Ensures children with higher ratings get more candies than their right neighbor

Initially, all children get 1 candy. Then we adjust based on ratings:
- If current child has higher rating than left child, they get one more candy than left child
- If left child has higher rating than current child, left child gets max of (current child's candies + 1) and their existing candies

Time Complexity: O(n) where n is the number of children
Space Complexity: O(n) for the candies array
*/