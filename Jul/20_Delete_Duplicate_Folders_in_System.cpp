// 1948. Delete Duplicate Folders in System

// Due to a bug, there are many duplicate folders in a file system. You are given a 2D array paths, where paths[i] is an array representing an absolute path to the ith folder in the file system.

// For example, ["one", "two", "three"] represents the path "/one/two/three".
// Two folders (not necessarily on the same level) are identical if they contain the same non-empty set of identical subfolders and underlying subfolder structure. The folders do not need to be at the root level to be identical. If two or more folders are identical, then mark the folders as well as all their subfolders.

// For example, folders "/a" and "/b" in the file structure below are identical. They (as well as their subfolders) should all be marked:
// /a
// /a/x
// /a/x/y
// /a/z
// /b
// /b/x
// /b/x/y
// /b/z
// However, if the file structure also included the path "/b/w", then the folders "/a" and "/b" would not be identical. Note that "/a/x" and "/b/x" would still be considered identical even with the added folder.
// Once all the identical folders and their subfolders have been marked, the file system will delete all of them. The file system only runs the deletion once, so any folders that become identical after the initial deletion are not deleted.

// Return the 2D array ans containing the paths of the remaining folders after deleting all the marked folders. The paths may be returned in any order.

 

// Example 1:


// Input: paths = [["a"],["c"],["d"],["a","b"],["c","b"],["d","a"]]
// Output: [["d"],["d","a"]]
// Explanation: The file structure is as shown.
// Folders "/a" and "/c" (and their subfolders) are marked for deletion because they both contain an empty
// folder named "b".
// Example 2:


// Input: paths = [["a"],["c"],["a","b"],["c","b"],["a","b","x"],["a","b","x","y"],["w"],["w","y"]]
// Output: [["c"],["c","b"],["a"],["a","b"]]
// Explanation: The file structure is as shown. 
// Folders "/a/b/x" and "/w" (and their subfolders) are marked for deletion because they both contain an empty folder named "y".
// Note that folders "/a" and "/c" are identical after the deletion, but they are not deleted because they were not marked beforehand.
// Example 3:


// Input: paths = [["a","b"],["c","d"],["c"],["a"]]
// Output: [["c"],["c","d"],["a"],["a","b"]]
// Explanation: All folders are unique in the file system.
// Note that the returned array can be in a different order as the order does not matter.
 

// Constraints:

// 1 <= paths.length <= 2 * 104
// 1 <= paths[i].length <= 500
// 1 <= paths[i][j].length <= 10
// 1 <= sum(paths[i][j].length) <= 2 * 105
// path[i][j] consists of lowercase English letters.
// No two paths lead to the same folder.
// For any folder not at the root level, its parent folder will also be in the input.

struct Trie
{
    unordered_map<string, Trie *> links;
    string id = "";
    bool mark = 0;
    Trie(string id = "") : id(id) {}

    void insert(vector<string> &path)
    {
        Trie *Node = this;
        for (string &s : path)
        {
            if (!Node->links.count(s))
                Node->links[s] = new Trie(s);
            Node = Node->links[s];
        }
    }
};

class Solution
{
public:
    Trie trie;
    unordered_map<string, Trie *> mp;
    vector<vector<string>> ans;

    string serial(Trie *Node)
    {
        if (Node->links.empty())
            return "";

        vector<pair<string, Trie *>> sorted(Node->links.begin(),
                                            Node->links.end());
        sort(sorted.begin(), sorted.end());

        string dir;
        for (auto &[id, child] : sorted)
            dir += "(" + id + serial(child) + ")";

        if (mp.count(dir))
        {
            mp[dir]->mark = 1;
            Node->mark = 1;
        }
        else
            mp[dir] = Node;
        //    cout<<dir<<endl;
        return dir;
    }

    void to_ans(Trie *Node, vector<string> &path)
    {
        for (auto &[id, child] : Node->links)
        {
            if (child->mark)
                continue;
            path.push_back(id);
            ans.push_back(path);
            to_ans(child, path);
            path.pop_back();
        }
    }

    vector<vector<string>>
    deleteDuplicateFolder(vector<vector<string>> &paths)
    {
        for (auto &path : paths)
            trie.insert(path);

        serial(&trie);
        vector<string> path;
        to_ans(&trie, path);
        return ans;
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

/*
Code Explanation:
This code implements a solution to delete duplicate folders in a file system using a Trie data structure.

1. Trie Structure:
- Uses unordered_map to store child nodes
- Each node has an ID, mark flag, and links to children
- Insert function builds the trie from given paths

2. Main Solution:
- Creates a trie from input paths
- Uses serialization to identify duplicate structures
- Marks duplicate folders for deletion
- Constructs final answer excluding marked folders

3. Key Functions:
- serial(): Creates unique string representation of folder structure
- to_ans(): Builds final answer excluding marked folders
- deleteDuplicateFolder(): Main function orchestrating the solution

Time Complexity:
- Trie Construction: O(N * L) where N = total paths, L = avg path length
- Serialization: O(M * log M) where M = number of nodes
- Overall: O(N * L + M * log M)

Space Complexity:
- Trie Storage: O(N * L)
- Hash Map: O(M)
- Overall: O(N * L)

The init lambda at the end optimizes I/O operations.
*/