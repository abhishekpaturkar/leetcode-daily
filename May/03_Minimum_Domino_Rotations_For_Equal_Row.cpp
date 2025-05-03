// 1007. Minimum Domino Rotations For Equal Row
// Solved
// Medium
// Topics
// Companies
// In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino. (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

// We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.

// Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.

// If it cannot be done, return -1.

// Example 1:

// Input: tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
// Output: 2
// Explanation:
// The first figure represents the dominoes as given by tops and bottoms: before we do any rotations.
// If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.
// Example 2:

// Input: tops = [3,5,1,2,3], bottoms = [3,6,3,3,4]
// Output: -1
// Explanation:
// In this case, it is not possible to rotate the dominoes to make one row of values equal.

// Constraints:

// 2 <= tops.length <= 2 * 104
// bottoms.length == tops.length
// 1 <= tops[i], bottoms[i] <= 6

class Solution
{
public:
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
    {
        int res = INT_MAX;

        int face[7] = {};
        for (int i = 0; i < tops.size(); i++)
        {
            face[tops[i]]++;
            if (bottoms[i] != tops[i])
                face[bottoms[i]]++;
        }

        // for each possible face from 1...6
        for (int x = 1; x <= 6; x++)
        {
            if (face[x] < tops.size())
                continue; // can't fill entire row

            int maintainTop = 0, maintainBottom = 0;
            bool possible = true;

            // count flips
            for (int i = 0; i < tops.size(); i++)
            {
                if (tops[i] != x && bottoms[i] != x)
                {
                    possible = false;
                    break;
                }
                if (tops[i] != x)
                    maintainTop++;
                if (bottoms[i] != x)
                    maintainBottom++;
            }

            if (possible)
                res = min(res, min(maintainTop, maintainBottom));
        }

        return res == INT_MAX ? -1 : res;
    }
};

/*
Code Explanation:
This solution finds the minimum number of domino rotations needed to make all values in either the top or bottom row equal.

1. First, we count the frequency of each face value (1-6) appearing in both top and bottom rows
2. For each possible face value (1-6):
   - Check if that value appears enough times to potentially fill an entire row
   - Count how many rotations needed to make all top values equal to x
   - Count how many rotations needed to make all bottom values equal to x
   - Take minimum of top and bottom rotations if possible
3. Return the minimum rotations found, or -1 if impossible

Time Complexity: O(n), where n is length of input arrays
- We do two passes through the arrays: one for counting frequencies and one for checking rotations
- The loop from 1 to 6 is constant time O(1)

Space Complexity: O(1)
- We only use a fixed-size array of size 7 for counting frequencies
- All other variables use constant space
*/