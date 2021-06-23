/*
Problem link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
Lowest Common ancestor of given node in BST
*/

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

// Recursive approach

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int parent_val = root -> val;
        int pval = p->val;
        int qval = q->val;
        
        if (pval > parent_val && qval > parent_val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        else if (pval < parent_val && qval < parent_val) {
            return lowestCommonAncestor(root -> left, p, q);
        }
        else 
            return root;
    }
};

// Iterative solution

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* node = root;
        int pval = p -> val;
        int qval = q -> val;
        
        while (node != nullptr) {
            int parent_val = node -> val;
            
            if (pval > parent_val && qval > parent_val) 
                node = node -> right;
            else if (pval < parent_val && qval < parent_val)
                node = node -> left;
            else
                return node;
        }
        return NULL;
        
    }
};