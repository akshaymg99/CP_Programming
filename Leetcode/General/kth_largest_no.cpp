struct Node {
    Node* left;
    Node* right;
    int val;
    int cnt;
    Node(int v, int c) : left(NULL), right(NULL), val(v), cnt(c) {}
};

class KthLargest {
private:
    Node* insertNode(Node* root, int val) {
        if (!root) {
            return new Node(val, 1);       
        }
        if (val > root->val)        
            root->right = insertNode(root->right, val);
        else                        
            root->left = insertNode(root->left, val);
        
        root->cnt++;
        return root;
    }
    int search(Node* root, int k) {
        int m = root->right ? (root->right)->cnt : 0;  // size of right subtree
        
        if (k == m + 1) {
            return root->val;
        }
        else if (k <= m)
            return search(root->right, k);
        else
            return search(root->left, k - m - 1);
    }
    
    Node* root;
    int m_k;
public:
    KthLargest(int k, vector<int> nums) {
        root = NULL;
        for (int i = 0; i < nums.size(); ++i) {
            root = insertNode(root, nums[i]);
        }
        m_k = k;
    }
    
    int add(int val) {
        root = insertNode(root, val);
        return search(root, m_k);
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */