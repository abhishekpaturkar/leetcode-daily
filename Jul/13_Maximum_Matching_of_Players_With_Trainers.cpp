// 2410. Maximum Matching of Players With Trainers

// You are given a 0-indexed integer array players, where players[i] represents the ability of the ith player. You are also given a 0-indexed integer array trainers, where trainers[j] represents the training capacity of the jth trainer.

// The ith player can match with the jth trainer if the player's ability is less than or equal to the trainer's training capacity. Additionally, the ith player can be matched with at most one trainer, and the jth trainer can be matched with at most one player.

// Return the maximum number of matchings between players and trainers that satisfy these conditions.

 

// Example 1:

// Input: players = [4,7,9], trainers = [8,2,5,8]
// Output: 2
// Explanation:
// One of the ways we can form two matchings is as follows:
// - players[0] can be matched with trainers[0] since 4 <= 8.
// - players[1] can be matched with trainers[3] since 7 <= 8.
// It can be proven that 2 is the maximum number of matchings that can be formed.
// Example 2:

// Input: players = [1,1,1], trainers = [10]
// Output: 1
// Explanation:
// The trainer can be matched with any of the 3 players.
// Each player can only be matched with one trainer, so the maximum answer is 1.
 

// Constraints:

// 1 <= players.length, trainers.length <= 105
// 1 <= players[i], trainers[j] <= 109

class Solution
{
public:
    static int matchPlayersAndTrainers(vector<int> &p, vector<int> &t)
    {
        const int n = p.size(), m = t.size();
        sort(p.begin(), p.end());
        sort(t.begin(), t.end());
        int match = 0;
        for (int i = 0, j = 0; i < n && j < m; i++)
        {
            const int pi = p[i];
            while (j < m && t[j] < pi)
                j++;
            if (j < m)
            {
                j++;
                match++;
            }
        }
        return match;
    }
};

/*
Code explanation:
This solution finds the maximum number of possible matches between players and trainers. Here's how it works:

1. First, we sort both arrays (players and trainers) in ascending order
2. We use two pointers i and j to iterate through players and trainers respectively
3. For each player, we find the first trainer whose capacity is >= player's ability
4. When we find a valid match, we increment both pointers and count the match
5. If no valid trainer is found for a player, we move to next player
6. Process continues until we reach end of either array

Time Complexity: O(nlogn + mlogm) where n and m are lengths of players and trainers arrays respectively
Space Complexity: O(1) as we only use constant extra space
*/