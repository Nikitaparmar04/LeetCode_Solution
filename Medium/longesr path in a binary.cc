class Solution {
public:
    int longestZigZag(TreeNode* root) {
        vector<int> res = dfs(root);
        return res[2];
    }
    
private:
    vector<int> dfs(TreeNode* node) {
        if (node == nullptr) {
            return {-1, -1, -1};
        }
        
        vector<int> leftSubtree = dfs(node->left);
        vector<int> rightSubtree = dfs(node->right);
        
        int leftLength = leftSubtree[1] + 1;
        int rightLength = rightSubtree[0] + 1;
        int maxLen = max({leftLength, rightLength, leftSubtree[2], rightSubtree[2]});
        
        return {leftLength, rightLength, maxLen};
    }
};