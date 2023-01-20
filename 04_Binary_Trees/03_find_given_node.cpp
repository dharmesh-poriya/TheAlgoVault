TreeNode *findNode(TreeNode *root, int x)
{
    if (!root)
        return nullptr;
    if (root->val == x)
        return root;
    TreeNode *left = findNode(root->left, x);
    if (left)
        return left;
    return findNode(root->right, x);
}