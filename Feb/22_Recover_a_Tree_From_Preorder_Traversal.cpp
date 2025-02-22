// 1028. Recover a Tree From Preorder Traversal

// We run a preorder depth-first search (DFS) on the root of a binary tree.

// At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.

// If a node has only one child, that child is guaranteed to be the left child.

// Given the output traversal of this traversal, recover the tree and return its root.

// Example 1:

// Input: traversal = "1-2--3--4-5--6--7"
// Output: [1,2,5,3,4,6,7]
// Example 2:

// Input: traversal = "1-2--3---4-5--6---7"
// Output: [1,2,5,3,null,6,null,4,null,7]
// Example 3:

// Input: traversal = "1-401--349---90--88"
// Output: [1,401,null,349,88,90]

// Constraints:

// The number of nodes in the original tree is in the range [1, 1000].
// 1 <= Node.val <= 109

class Solution
{
public:
    string s;
    int idx = 0, level = 0;

    TreeNode *recoverFromPreorder(string traversal)
    {
        s = traversal;
        TreeNode *node = new TreeNode(-1);
        helper(node, 0);
        return node->left;
    }

    void helper(TreeNode *parent, int lvl)
    {
        while (idx < s.length() && lvl == level)
        {
            int num = 0;
            while (idx < s.length() && isdigit(s[idx]))
            {
                num = num * 10 + (s[idx++] - '0');
            }
            TreeNode *node = new TreeNode(num);
            if (!parent->left)
                parent->left = node;
            else
                parent->right = node;
            level = 0;
            while (idx < s.length() && s[idx] == '-')
            {
                level++;
                idx++;
            }
            helper(node, lvl + 1);
        }
    }
};

// Main Function - recoverFromPreorder:
// - Creates a dummy root node with value -1
// - Calls helper function to build the tree
// - Returns the left child of dummy node (actual root)

// Helper Function - helper:
// - Takes parent node and current level as parameters
// - Works recursively to build the tree:
// - Extracts number from string by parsing digits
// - Creates new node with parsed value
// - Attaches node as left child if no left child exists, otherwise as right child
// - Counts consecutive dashes to determine next level
// - Recursively builds subtrees