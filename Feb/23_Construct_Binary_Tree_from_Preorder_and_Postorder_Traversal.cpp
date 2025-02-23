// 889. Construct Binary Tree from Preorder and Postorder Traversal
// 
// Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.

// If there exist multiple answers, you can return any of them.

 

// Example 1:


// Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
// Output: [1,2,3,4,5,6,7]
// Example 2:

// Input: preorder = [1], postorder = [1]
// Output: [1]
 

// Constraints:

// 1 <= preorder.length <= 30
// 1 <= preorder[i] <= preorder.length
// All the values of preorder are unique.
// postorder.length == preorder.length
// 1 <= postorder[i] <= postorder.length
// All the values of postorder are unique.
// It is guaranteed that preorder and postorder are the preorder traversal and postorder traversal of the same binary tree.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int search(vector<int> &postorder, int start, int end, int num)
    {
        for (int i = start; i <= end; i++)
        {
            if (postorder[i] == num)
            {
                return i;
            }
        }

        return -1;
    }

    // Variable to keep track of the index in the preorder array
    int preindex = 0;
    TreeNode *solve(vector<int> &preorder, vector<int> &postorder, int start, int end)
    {
        // Base case: empty subtree
        if (start > end || preindex >= preorder.size())
            return nullptr;

        // Root value for the current subtree
        int num = preorder[preindex];
        preindex++;

        TreeNode *root = new TreeNode(num);

        // Leaf node or end of current subtree
        if (preindex >= preorder.size() || start == end)
            return root;

        // The index of the next root value in the postorder array
        int postindex = search(postorder, start, end, preorder[preindex]);

        // Recursive call for left and right subtree
        root->left = solve(preorder, postorder, start, postindex);
        // end - 1 because the root node is taken out
        root->right = solve(preorder, postorder, postindex + 1, end - 1);

        return root;
    }

    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        return solve(preorder, postorder, 0, preorder.size() - 1);
    }
};

/*
This code constructs a binary tree from its preorder and postorder traversals. Here's how it works:

1. The search function finds the index of a given number in the postorder array within a specified range.

2. The solve function is the main recursive function that:
   - Uses preindex to track current position in preorder array
   - Creates a new node with the current preorder value
   - Finds where the next preorder value appears in postorder array
   - Uses this to determine the boundaries of left and right subtrees
   - Recursively builds left and right subtrees

3. The constructFromPrePost function initiates the tree construction by calling solve
   with initial parameters.

The algorithm works because:
- In preorder traversal, we visit: root -> left -> right
- In postorder traversal, we visit: left -> right -> root
- This relationship helps us determine the boundaries of left and right subtrees
*/