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
class Solution {
public:
    TreeNode* LCA(TreeNode* root, int p, int q) {
        if(root == NULL || root->val == p || root->val == q) {
            return root;
        }

        TreeNode* left = LCA(root->left,p,q);
        TreeNode* right = LCA(root->right,p,q);
        if(left == NULL) {
            return right;
        }
        else if(right == NULL) {
            return left;
        }
        else {
            return root;
        }
    }

    bool findPath(TreeNode* root, int val, string& path) {
        if(!root) {
            return false;
        }
        if(root->val == val) {
            return true;
        }
        path.push_back('L');
        if(findPath(root->left,val,path)) {
            return true;
        }
        path.pop_back();
        path.push_back('R');
        if(findPath(root->right,val,path)) {
            return true;
        }
        path.pop_back();
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        root = LCA(root,startValue,destValue); // changing root to LCA
        string startToRoot, rootToDest;
        findPath(root,startValue,startToRoot);
        findPath(root,destValue,rootToDest);
        
        for(auto &c:startToRoot) {
            c = 'U';
        }
        return startToRoot + rootToDest;
    }
};