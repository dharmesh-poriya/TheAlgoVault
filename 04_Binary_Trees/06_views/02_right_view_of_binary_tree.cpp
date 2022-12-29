// https://leetcode.com/problems/binary-tree-right-side-view/

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode *> q;
        if(root)
            q.push(root);
        while(!q.empty()){
            int sz = q.size();
            ans.push_back(q.front()->val);
            while(sz--){
                TreeNode *current = q.front();
                q.pop();
                if(current->right) q.push(current->right);
                if(current->left) q.push(current->left);
            }
        }
        return ans;
    }
};