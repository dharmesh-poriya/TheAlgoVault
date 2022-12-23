// https://practice.geeksforgeeks.org/problems/construct-binary-tree-from-parent-array/1

// Construct binary tree from parent array


class Solution{
  public:
    //Function to construct binary tree from parent array.
    Node *createTree(int parent[], int N)
    {
        vector<Node *> nodes;
        Node *root;
        for(int i=0;i<N;i++){
            nodes.push_back(new Node(i));
            if(-1==parent[i]) root = nodes.back();
        }
        for(int i=0;i<N;i++){
            if(-1==parent[i]) continue;
            Node *p = nodes[parent[i]];
            if(p->left){
                nodes[parent[i]]->right = nodes[i];
            }else{
                nodes[parent[i]]->left = nodes[i];
            }
        }
        return root;
    }
};