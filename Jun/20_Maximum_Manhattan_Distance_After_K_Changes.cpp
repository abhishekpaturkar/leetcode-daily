// 3443. Maximum Manhattan Distance After K Changes

// You are given a string s consisting of the characters 'N', 'S', 'E', and 'W', where s[i] indicates movements in an infinite grid:

// 'N' : Move north by 1 unit.
// 'S' : Move south by 1 unit.
// 'E' : Move east by 1 unit.
// 'W' : Move west by 1 unit.
// Initially, you are at the origin (0, 0). You can change at most k characters to any of the four directions.

// Find the maximum Manhattan distance from the origin that can be achieved at any time while performing the movements in order.

// The Manhattan Distance between two cells (xi, yi) and (xj, yj) is |xi - xj| + |yi - yj|.
 

// Example 1:

// Input: s = "NWSE", k = 1

// Output: 3

// Explanation:

// Change s[2] from 'S' to 'N'. The string s becomes "NWNE".

// Movement	Position (x, y)	Manhattan Distance	Maximum
// s[0] == 'N'	(0, 1)	0 + 1 = 1	1
// s[1] == 'W'	(-1, 1)	1 + 1 = 2	2
// s[2] == 'N'	(-1, 2)	1 + 2 = 3	3
// s[3] == 'E'	(0, 2)	0 + 2 = 2	3
// The maximum Manhattan distance from the origin that can be achieved is 3. Hence, 3 is the output.

// Example 2:

// Input: s = "NSWWEW", k = 3

// Output: 6

// Explanation:

// Change s[1] from 'S' to 'N', and s[4] from 'E' to 'W'. The string s becomes "NNWWWW".

// The maximum Manhattan distance from the origin that can be achieved is 6. Hence, 6 is the output.

 

// Constraints:

// 1 <= s.length <= 105
// 0 <= k <= s.length
// s consists of only 'N', 'S', 'E', and 'W'.

class Solution
{
public:
    int maxDistance(string s, int k)
    {
        int ans = 0;
        int north = 0, south = 0, east = 0, west = 0;

        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (c == 'N')
                north++;
            else if (c == 'S')
                south++;
            else if (c == 'E')
                east++;
            else if (c == 'W')
                west++;

            int x = abs(north - south);
            int y = abs(east - west);
            int MD = x + y;
            int dis = MD + min(2 * k, i + 1 - MD);
            ans = max(ans, dis);
        }

        return ans;
    }
};

/*
Code Explanation:
This solution finds the maximum Manhattan distance possible after making at most k changes to the input string.

1. We keep track of counts for each direction (north, south, east, west)
2. For each character in string:
   - Increment respective direction counter
   - Calculate current x-distance (|north-south|)
   - Calculate current y-distance (|east-west|)
   - Current Manhattan Distance (MD) = x + y
   - For each position, we can increase distance by either:
     * Using all k changes (2*k) 
     * Using remaining moves (i+1-MD)
   - Take maximum of current answer and new distance

Time Complexity: O(n) where n is length of string
Space Complexity: O(1) as we only use constant extra space
*/