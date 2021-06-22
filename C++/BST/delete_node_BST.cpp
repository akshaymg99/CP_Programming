/*
Problem link: https://leetcode.com/explore/learn/card/introduction-to-data-structure-binary-search-tree/141/basic-operations-in-a-bst/1006/
Deleting a node in BST (all cases)
*/

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    TreeNode* findSuccessor(TreeNode* root) {
        TreeNode* cur = root -> right;
        while (cur && cur->left) {
            cur = cur -> left;            
        }
        return cur;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        
        if (root -> val == key) {
            if (root -> left == nullptr)
                return root -> right;
            if (root -> right == nullptr)
                return root -> left;
            
            TreeNode* s = findSuccessor(root);
            root -> val = s -> val;
            root -> right = deleteNode(root -> right, s -> val); 
            return root;
        }
        else if (root -> val > key) {
            root -> left = deleteNode(root-> left, key);
        }
        else if(root -> val < key) {
            root -> right = deleteNode(root -> right, key);
        }
        return root;
    }
};