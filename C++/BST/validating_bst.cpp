/*
Problem link: 
Validating a Binary Search Tree
*/

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 // Approach 1: Inrorder check, recursive
 
class Solution {
private:
    TreeNode* prev = nullptr;
    
public:
    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }
    
    bool inorder(TreeNode* root) {
        if (root == nullptr)
            return true;
        if (! inorder(root -> left)) 
            return false;   
        
        if (prev != nullptr && root -> val <= prev -> val) {
            return false;
        }
        prev = root;
        return inorder(root -> right);
    }
};

// Approach 2: Using stack for Iterative method

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* prev = nullptr;
        
        while ( !stk.empty() || root != nullptr) {
            while (root != nullptr) {
                stk.push(root);
                root = root -> left;
            }
            root = stk.top();
            stk.pop();
            
            if (prev != nullptr && root -> val <= prev -> val) 
                return false;
            
            prev = root;
            root = root -> right;
            
        }
        return true;
        
    }
};