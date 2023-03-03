class DSU{
    private:
    int *parent;
    int n;
    public:
    DSU(int n)
    {
        this->n = n;
        parent = new int[n];
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int Find(int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = Find(parent[x]);
    }
    void Union(int x,int y){
        int x_root = Find(x);
        int y_root = Find(y);
        if(x_root != y_root){
            parent[y_root] = x_root;
        }
    }
    bool isConnected(int x,int y){
        return Find(x)==Find(y);
    }
};
// worst case Time complexity for find operation is O(n) and for union operation is O(n)