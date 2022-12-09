vector<vector<int>> diagonalTraversal(Node* root) {
    vector<vector<int>> ans;
    queue<Node *> q;
    if(root) q.push(root);
    while(!q.empty()){
        int size = q.size();
        ans.push_back({});
        while(size--){
            Node *current = q.front();
            q.pop();
            while(current){
                ans.back().push_back(current->data);
                if(current->left) q.push(current->left);
                current = current->right;
            }
        }
    }
    return ans;
}