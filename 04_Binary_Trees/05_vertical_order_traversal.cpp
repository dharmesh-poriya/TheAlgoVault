// https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

vector<int> verticalOrder(Node *root)
{
    unordered_map<int, vector<int>> m;
    queue<pair<Node *, int>> q;
    vector<int> ans;
    int leftpoint = 0, rightpoint = 0;

    if (NULL != root)
        q.push({root, 0});

    while (!q.empty())
    {
        Node *currentNode = q.front().first;
        int pos = q.front().second;
        q.pop();
        m[pos].push_back(currentNode->data);
        if (NULL != currentNode->left)
        {
            leftpoint = min(leftpoint, pos - 1);
            q.push({currentNode->left, pos - 1});
        }
        if (NULL != currentNode->right)
        {
            rightpoint = max(rightpoint, pos + 1);
            q.push({currentNode->right, pos + 1});
        }
    }

    for (int i = leftpoint; i <= rightpoint; i++)
    {
        for (auto data : m[i])
        {
            ans.push_back(data);
        }
    }
    return ans;
}