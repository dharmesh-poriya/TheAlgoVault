// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

vector<int> leftView(Node *root)
{
   vector<int> result;
   if(!root) return result;
   
   queue<Node *> q;
   q.push(root);
   while(!q.empty()){
       int count = q.size();
       result.push_back(q.front()->data);
       for(int i=0;i<count;i++){
           Node *current = q.front();
           q.pop();
           if(current->left)
               q.push(current->left);
           if(current->right)
               q.push(current->right);
       }
   }
   return result;
}