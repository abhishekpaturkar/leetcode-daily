// 3024. Type of Triangle
// 
// You are given a 0-indexed integer array nums of size 3 which can form the sides of a triangle.

// A triangle is called equilateral if it has all sides of equal length.
// A triangle is called isosceles if it has exactly two sides of equal length.
// A triangle is called scalene if all its sides are of different lengths.
// Return a string representing the type of triangle that can be formed or "none" if it cannot form a triangle.


// Example 1:

// Input: nums = [3,3,3]
// Output: "equilateral"
// Explanation: Since all the sides are of equal length, therefore, it will form an equilateral triangle.
// Example 2:

// Input: nums = [3,4,5]
// Output: "scalene"
// Explanation: 
// nums[0] + nums[1] = 3 + 4 = 7, which is greater than nums[2] = 5.
// nums[0] + nums[2] = 3 + 5 = 8, which is greater than nums[1] = 4.
// nums[1] + nums[2] = 4 + 5 = 9, which is greater than nums[0] = 3. 
// Since the sum of the two sides is greater than the third side for all three cases, therefore, it can form a triangle.
// As all the sides are of different lengths, it will form a scalene triangle.
 

// Constraints:

// nums.length == 3
// 1 <= nums[i] <= 100

class Solution
{
public:
    string triangleType(vector<int> &nums)
    {
        int a = nums[0];
        int b = nums[1];
        int c = nums[2];

        if (a == b && b == c)
        {
            return "equilateral";
        }
        else
        {
            if (a + b > c && a + c > b && b + c > a)
            {
                if (a == b || b == c || a == c)
                {
                    return "isosceles";
                }
                return "scalene";
            }
            else
            {
                return "none";
            }
        }
    }
};

/*
This code determines the type of triangle based on the lengths of its sides:
1. First checks if all sides are equal (equilateral)
2. Then verifies if sides can form a valid triangle using triangle inequality theorem
3. If valid, checks if two sides are equal (isosceles)
4. If no sides are equal, it's scalene
5. If triangle inequality fails, returns "none"

Time Complexity: O(1) - constant time operations
Space Complexity: O(1) - only uses fixed variables
*/