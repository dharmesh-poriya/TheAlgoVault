class Solution {
private:
    int dia;
int height(TreeNode *root){
    if(root == NULL){
        return 0;
    }
    int left_h = height(root->left);
    int right_h = height(root->right);
    dia = max(dia,left_h+right_h);
    return (max(left_h,right_h)+1);
}
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dia = INT_MIN;
        height(root);
        return dia;
    }
};