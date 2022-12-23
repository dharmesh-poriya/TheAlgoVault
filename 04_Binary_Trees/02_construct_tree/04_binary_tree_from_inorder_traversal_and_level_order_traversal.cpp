// 10_construct_binary_tree_from_inorder_traversal_and_level_order_traversal

// https://practice.geeksforgeeks.org/problems/construct-tree-from-inorder-and-levelorder/1


unordered_map<int,int> m;
Node *helper(int inorder[],int levelorder[],int n,int istart,int iend){
    if(istart>iend) return NULL;
    
    int inIndex = istart;
    for(int i=istart+1;i<=iend;i++){
        if(m[inorder[inIndex]] > m[inorder[i]])
            inIndex = i;
    }
    Node *root = new Node(inorder[inIndex]);
    if(istart == iend) return root;
    
    root->left = helper(inorder,levelorder,n,istart,inIndex-1);
    root->right = helper(inorder,levelorder,n,inIndex+1,iend);
    return root;
}

Node* buildTree(int inorder[], int levelorder[], int iStart, int iEnd,int n)
{
    for(int i=0;i<n;i++){
      m[levelorder[i]] = i;
    }
        
    return helper(inorder,levelorder,n,0,n-1);
}