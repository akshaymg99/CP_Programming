/*
Problem link: https://leetcode.com/explore/learn/card/introduction-to-data-structure-binary-search-tree/141/basic-operations-in-a-bst/1000/
Searching in BST
*/

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root) {
            if (val == root->val)
                return root;
            else if (val > root->val) {
                root = root -> right;
            }
            else if (val < root -> val) {
                root = root -> left;
            }
        }  
        
        return nullptr; 
    }
};

//Recursive Approach
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr || val == root->val) 
            return root;
        
        if (val > root->val) 
            return searchBST(root -> right, val);
        else
            return searchBST(root -> left, val);
        
        
    }
};