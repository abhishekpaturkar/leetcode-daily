// 1061. Lexicographically Smallest Equivalent String

// You are given two strings of the same length s1 and s2 and a string baseStr.

// We say s1[i] and s2[i] are equivalent characters.

// For example, if s1 = "abc" and s2 = "cde", then we have 'a' == 'c', 'b' == 'd', and 'c' == 'e'.
// Equivalent characters follow the usual rules of any equivalence relation:

// Reflexivity: 'a' == 'a'.
// Symmetry: 'a' == 'b' implies 'b' == 'a'.
// Transitivity: 'a' == 'b' and 'b' == 'c' implies 'a' == 'c'.
// For example, given the equivalency information from s1 = "abc" and s2 = "cde", "acd" and "aab" are equivalent strings of baseStr = "eed", and "aab" is the lexicographically smallest equivalent string of baseStr.

// Return the lexicographically smallest equivalent string of baseStr by using the equivalency information from s1 and s2.


// Example 1:

// Input: s1 = "parker", s2 = "morris", baseStr = "parser"
// Output: "makkek"
// Explanation: Based on the equivalency information in s1 and s2, we can group their characters as [m,p], [a,o], [k,r,s], [e,i].
// The characters in each group are equivalent and sorted in lexicographical order.
// So the answer is "makkek".
// Example 2:

// Input: s1 = "hello", s2 = "world", baseStr = "hold"
// Output: "hdld"
// Explanation: Based on the equivalency information in s1 and s2, we can group their characters as [h,w], [d,e,o], [l,r].
// So only the second letter 'o' in baseStr is changed to 'd', the answer is "hdld".
// Example 3:

// Input: s1 = "leetcode", s2 = "programs", baseStr = "sourcecode"
// Output: "aauaaaaada"
// Explanation: We group the equivalent characters in s1 and s2 as [a,o,e,r,s,c], [l,p], [g,t] and [d,m], thus all letters in baseStr except 'u' and 'd' are transformed to 'a', the answer is "aauaaaaada".
 

// Constraints:

// 1 <= s1.length, s2.length, baseStr <= 1000
// s1.length == s2.length
// s1, s2, and baseStr consist of lowercase English letters

class Solution
{
public:
    // DFS to find the smallest lex character in the component
    char dfs(unordered_map<char, vector<char>> &adj, char cur, vector<int> &vis)
    {
        vis[cur - 'a'] = 1;
        char minChar = cur;
        for (char neighbor : adj[cur])
        {
            if (vis[neighbor - 'a'] == 0)
            {
                minChar = min(minChar, dfs(adj, neighbor, vis));
            }
        }
        return minChar;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        int n = s1.length();
        unordered_map<char, vector<char>> adj;

        // Step 1: Build the equivalence graph
        for (int i = 0; i < n; ++i)
        {
            char u = s1[i];
            char v = s2[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Step 2: Replace each character in baseStr with the smallest equivalent
        string result;
        for (char ch : baseStr)
        {
            vector<int> vis(26, 0);
            char minChar = dfs(adj, ch, vis);
            result.push_back(minChar);
        }

        return result;
    }
};

/*
Code Explanation:
This solution uses a graph-based approach to find lexicographically smallest equivalent strings.

1. First, we build an undirected graph where:
   - Each character is a node
   - Edges connect equivalent characters from s1 and s2
   
2. For each character in baseStr:
   - We perform DFS starting from that character
   - During DFS, we keep track of the smallest character in the connected component
   - We replace the current character with the smallest equivalent character found

3. The DFS function:
   - Marks current character as visited
   - Explores all neighbors recursively
   - Returns the minimum character in the current component

Time Complexity: O(K * (V + E))
- K is length of baseStr
- V is number of vertices (max 26)
- E is number of edges (max n, where n is length of s1/s2)
For each character in baseStr, we do a DFS

Space Complexity: O(V + E)
- For adjacency list storage
- For visited array in DFS
- For recursion stack
*/