/*
Problem link: https://leetcode.com/problems/inorder-successor-in-bst/
Finding inorder Successor of a Binary search tree;
*/

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* successor = nullptr;
        
        while (root) {
            if (p->val >= root->val)
                root = root -> right;
            else {
                successor = root;
                root = root -> left;
            } 
        }
        return successor;
    }
};