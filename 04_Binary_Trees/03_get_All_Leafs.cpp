vector<int> getLeafs(TreeNode *root)
{
    if (!root) return {};
    if (!root->left and !root->right) return {root->val};
    vector<int> left = getLeafs(root->left);
    vector<int> right = getLeafs(root->right);
    for (auto leaf : right) left.push_back(leaf);
    return left;
}