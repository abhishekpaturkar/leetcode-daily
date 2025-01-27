// 1462. Course Schedule IV
// Solved
// Medium
// Topics
// Companies
// Hint
// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course ai first if you want to take course bi.

// For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.
// Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a prerequisite of course c, then course a is a prerequisite of course c.

// You are also given an array queries where queries[j] = [uj, vj]. For the jth query, you should answer whether course uj is a prerequisite of course vj or not.

// Return a boolean array answer, where answer[j] is the answer to the jth query.

 

// Example 1:


// Input: numCourses = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
// Output: [false,true]
// Explanation: The pair [1, 0] indicates that you have to take course 1 before you can take course 0.
// Course 0 is not a prerequisite of course 1, but the opposite is true.
// Example 2:

// Input: numCourses = 2, prerequisites = [], queries = [[1,0],[0,1]]
// Output: [false,false]
// Explanation: There are no prerequisites, and each course is independent.
// Example 3:


// Input: numCourses = 3, prerequisites = [[1,2],[1,0],[2,0]], queries = [[1,0],[1,2]]
// Output: [true,true]
 

// Constraints:

// 2 <= numCourses <= 100
// 0 <= prerequisites.length <= (numCourses * (numCourses - 1) / 2)
// prerequisites[i].length == 2
// 0 <= ai, bi <= numCourses - 1
// ai != bi
// All the pairs [ai, bi] are unique.
// The prerequisites graph has no cycles.
// 1 <= queries.length <= 104
// 0 <= ui, vi <= numCourses - 1
// ui != vi

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // Step 1: Initialize the reachability map
        unordered_map<int, unordered_set<int>> reachable;

        // Step 2: Build direct reachability chains
        for (auto& prereq : prerequisites) {
            reachable[prereq[1]].insert(prereq[0]);
        }

        // Step 3: Propagate reachability to account for indirect prerequisites
        for (int i = 0; i < numCourses; ++i) {
            for (int j = 0; j < numCourses; ++j) {
                if (reachable[j].count(i)) {
                    reachable[j].insert(reachable[i].begin(), reachable[i].end());
                }
            }
        }

        vector<bool> result;
        for (auto& query : queries) {
            result.push_back(reachable[query[1]].count(query[0]) > 0);
        }
        return result;
    }
};

/*
This code solves the Course Schedule IV problem using a reachability approach:
1. Creates a map where each course maps to a set of its prerequisites
2. First builds direct prerequisite relationships from the input prerequisites
3. Then uses a nested loop to propagate indirect prerequisites - if course A is prerequisite of B, and B is prerequisite of C, then A becomes prerequisite of C
4. Finally processes each query by checking if the prerequisite course exists in the reachability set of the target course
5. Returns array of boolean results indicating whether each prerequisite relationship exists
*/