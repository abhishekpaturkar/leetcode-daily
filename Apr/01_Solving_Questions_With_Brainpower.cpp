// 2140. Solving Questions With Brainpower

// You are given a 0-indexed 2D integer array questions where questions[i] = [pointsi, brainpoweri].

// The array describes the questions of an exam, where you have to process the questions in order (i.e., starting from question 0) and make a decision whether to solve or skip each question. Solving question i will earn you pointsi points but you will be unable to solve each of the next brainpoweri questions. If you skip question i, you get to make the decision on the next question.

// For example, given questions = [[3, 2], [4, 3], [4, 4], [2, 5]]:
// If question 0 is solved, you will earn 3 points but you will be unable to solve questions 1 and 2.
// If instead, question 0 is skipped and question 1 is solved, you will earn 4 points but you will be unable to solve questions 2 and 3.
// Return the maximum points you can earn for the exam.

 

// Example 1:

// Input: questions = [[3,2],[4,3],[4,4],[2,5]]
// Output: 5
// Explanation: The maximum points can be earned by solving questions 0 and 3.
// - Solve question 0: Earn 3 points, will be unable to solve the next 2 questions
// - Unable to solve questions 1 and 2
// - Solve question 3: Earn 2 points
// Total points earned: 3 + 2 = 5. There is no other way to earn 5 or more points.
// Example 2:

// Input: questions = [[1,1],[2,2],[3,3],[4,4],[5,5]]
// Output: 7
// Explanation: The maximum points can be earned by solving questions 1 and 4.
// - Skip question 0
// - Solve question 1: Earn 2 points, will be unable to solve the next 2 questions
// - Unable to solve questions 2 and 3
// - Solve question 4: Earn 5 points
// Total points earned: 2 + 5 = 7. There is no other way to earn 7 or more points.
 

// Constraints:

// 1 <= questions.length <= 105
// questions[i].length == 2
// 1 <= pointsi, brainpoweri <= 105

class Solution
{
public:
    long long mostPoints(vector<vector<int>> &questions)
    {
        vector<long long> dp(questions.size(), 0);
        for (int i = questions.size() - 1; i >= 0; i--)
        {
            int index = i + questions[i][1] + 1;
            if (index < questions.size())
            {
                dp[i] = dp[index] + questions[i][0];
            }
            else
            {
                dp[i] = questions[i][0];
            }
            if (i < questions.size() - 1)
            {
                dp[i] = max(dp[i + 1], dp[i]);
            }
        }
        return dp[0];
    }
};

/*
This code solves the problem using dynamic programming with a bottom-up approach:
1. Creates a DP array to store maximum points possible starting from each index
2. Iterates from right to left (bottom-up)
3. For each question:
   - Calculates next available question index after solving current question
   - If next question exists, adds current points + max points from next available question
   - If no next question, just takes current question points
   - Takes maximum between solving current question or skipping it (using next question)
4. Returns maximum points possible from starting index (0)

Time Complexity: O(n) where n is number of questions
Space Complexity: O(n) for the DP array
*/