// 1261. Find Elements in a Contaminated Binary Tree

// Given a binary tree with the following rules:

// root.val == 0
// For any treeNode:
// If treeNode.val has a value x and treeNode.left != null, then treeNode.left.val == 2 * x + 1
// If treeNode.val has a value x and treeNode.right != null, then treeNode.right.val == 2 * x + 2
// Now the binary tree is contaminated, which means all treeNode.val have been changed to -1.

// Implement the FindElements class:

// FindElements(TreeNode* root) Initializes the object with a contaminated binary tree and recovers it.
// bool find(int target) Returns true if the target value exists in the recovered binary tree.
 

// Example 1:


// Input
// ["FindElements","find","find"]
// [[[-1,null,-1]],[1],[2]]
// Output
// [null,false,true]
// Explanation
// FindElements findElements = new FindElements([-1,null,-1]); 
// findElements.find(1); // return False 
// findElements.find(2); // return True 
// Example 2:


// Input
// ["FindElements","find","find","find"]
// [[[-1,-1,-1,-1,-1]],[1],[3],[5]]
// Output
// [null,true,true,false]
// Explanation
// FindElements findElements = new FindElements([-1,-1,-1,-1,-1]);
// findElements.find(1); // return True
// findElements.find(3); // return True
// findElements.find(5); // return False
// Example 3:


// Input
// ["FindElements","find","find","find","find"]
// [[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]
// Output
// [null,true,false,false,true]
// Explanation
// FindElements findElements = new FindElements([-1,null,-1,-1,null,-1]);
// findElements.find(2); // return True
// findElements.find(3); // return False
// findElements.find(4); // return False
// findElements.find(5); // return True
 

// Constraints:

// TreeNode.val == -1
// The height of the binary tree is less than or equal to 20
// The total number of nodes is between [1, 104]
// Total calls of find() is between [1, 104]
// 0 <= target <= 106

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

class FindElements
{
    unordered_set<int> recoveredValues;

    void recoverTree(TreeNode *root)
    {
        if (!root)
            return;
        recoveredValues.insert(root->val);
        if (root->left)
        {
            root->left->val = 2 * root->val + 1;
            recoverTree(root->left);
        }
        if (root->right)
        {
            root->right->val = 2 * root->val + 2;
            recoverTree(root->right);
        }
    }

public:
    FindElements(TreeNode *root)
    {
        root->val = 0;
        recoverTree(root);
    }

    bool find(int target)
    {
        return recoveredValues.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

/*
This code implements a solution for recovering and searching values in a contaminated binary tree. Here's how it works:

1. The class uses an unordered_set to store recovered values from the tree.

2. The recoverTree method:
   - Recursively traverses the tree
   - For each node, calculates its children's values using formulas:
     - Left child = 2 * parent_value + 1
     - Right child = 2 * parent_value + 2
   - Stores each recovered value in the set

3. The constructor:
   - Takes a contaminated tree (all nodes have value -1)
   - Sets root value to 0
   - Calls recoverTree to recover the entire tree

4. The find method:
   - Checks if a target value exists in the recovered tree
   - Uses the set's count method to return true if found, false otherwise

The solution has O(n) space complexity for storing values and O(1) time complexity for searching.
*/ 