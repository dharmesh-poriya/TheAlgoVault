int countTotalNodes(TreeNode *root)
{
    if (!root)
        return 0;
    return 1 + countTotalNodes(root->left) + countTotalNodes(root->right);
}