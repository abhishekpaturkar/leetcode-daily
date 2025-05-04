// 1128. Number of Equivalent Domino Pairs

// Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a == c and b == d), or (a == d and b == c) - that is, one domino can be rotated to be equal to another domino.

// Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].


// Example 1:

// Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
// Output: 1
// Example 2:

// Input: dominoes = [[1,2],[1,2],[1,1],[1,2],[2,2]]
// Output: 3
 

// Constraints:

// 1 <= dominoes.length <= 4 * 104
// dominoes[i].length == 2
// 1 <= dominoes[i][j] <= 9

class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        int count = 0;
        unordered_map<int, int> m;
        for (auto d : dominoes)
        {
            int key = min(d[0], d[1]) * 10 + max(d[0], d[1]);
            count += m[key];
            m[key]++;
        }
        return count;
    }
};

/*
This code finds the number of equivalent domino pairs in a given array of dominoes.
For each domino [a,b], it creates a unique key by taking min(a,b)*10 + max(a,b).
This ensures that [1,2] and [2,1] will have the same key (12).
The unordered_map 'm' keeps track of frequency of each key.
For each domino, we add the current frequency of its key to count (pairs with previous dominoes)
and then increment its frequency.

Time Complexity: O(n) where n is number of dominoes
Space Complexity: O(n) for storing the frequency map
*/