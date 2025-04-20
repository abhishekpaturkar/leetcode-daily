// 781. Rabbits in Forest

// There is a forest with an unknown number of rabbits. We asked n rabbits "How many rabbits have the same color as you?" and collected the answers in an integer array answers where answers[i] is the answer of the ith rabbit.

// Given the array answers, return the minimum number of rabbits that could be in the forest.

 

// Example 1:

// Input: answers = [1,1,2]
// Output: 5
// Explanation:
// The two rabbits that answered "1" could both be the same color, say red.
// The rabbit that answered "2" can't be red or the answers would be inconsistent.
// Say the rabbit that answered "2" was blue.
// Then there should be 2 other blue rabbits in the forest that didn't answer into the array.
// The smallest possible number of rabbits in the forest is therefore 5: 3 that answered plus 2 that didn't.
// Example 2:

// Input: answers = [10,10,10]
// Output: 11
 

// Constraints:

// 1 <= answers.length <= 1000
// 0 <= answers[i] < 1000

class Solution
{
public:
    int numRabbits(vector<int> &nums, int total = 0)
    {
        unordered_map<int, int> mpp;
        for (int i : nums)
            mpp[i]++;

        for (auto &p : mpp)
            total += ceil((double)p.second / (p.first + 1)) * (p.first + 1);
        return total;
    }
};

/*
Code Explanation:
This solution finds the minimum number of rabbits in a forest based on their answers about how many other rabbits share their color.

1. We use an unordered_map 'mpp' to store the frequency of each answer
2. First loop counts how many rabbits gave each answer
3. Second loop calculates minimum rabbits needed:
   - For each unique answer (p.first) and its frequency (p.second)
   - We divide frequency by (answer + 1) and round up using ceil
   - Multiply result by (answer + 1) to get total rabbits of that color
4. Sum all these values to get minimum total rabbits

Time Complexity: O(n) where n is the length of input array
Space Complexity: O(k) where k is the number of unique answers
*/