/*
Problem link: https://leetcode.com/explore/learn/card/introduction-to-data-structure-binary-search-tree/141/basic-operations-in-a-bst/1003/
Insertion of new node in BST
*/

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

// Recursive solution 

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr)
            return new TreeNode(val);
        
        if (val < root -> val) {
            root -> left = insertIntoBST(root->left, val);
        }
        else {
            root -> right = insertIntoBST(root->right, val);
        }
        return root;
        
    }
};

// Iterative solution

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* cur = root;
        TreeNode* node = new TreeNode(val);
        
        while (cur) {
            if (val > cur -> val) {
                if (cur -> right)
                    cur = cur -> right;
                else {
                    cur -> right = node;
                    break;
                    }
                }
                
                if (val < cur -> val) {
                    if (cur -> left)
                        cur = cur -> left;
                    else {
                        cur -> left = node;
                        break;
                    }
                }
            }
        
        return root ? root : node; 
        }
        
};