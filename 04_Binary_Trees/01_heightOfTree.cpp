int height(TreeNode *root){
    if(root == NULL)
        return 0;
    
    int left_h = height(root->left);
    int right_h = height(root->right);
    return (max(left_h,right_h)+1);
}