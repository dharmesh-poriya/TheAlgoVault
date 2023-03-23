# Disjoint Set Union By maintaining rank
<!-- ### [Problem Link]() -->

## Approach : 
* create parent array and rank array.
* initialize parent array with index of each node.
* initialize rank array with 0.
* create Find function which returns the parent of the node.
* create Union function which merges two nodes.
* create isConnected function which returns true if two nodes are connected.

## Code : 
```cpp
class DSUByRank{
    private:
    int *parent;
    int *rank;
    int n;
    public:
    DSUByRank(int n){
        this->n = n;
        parent = new int[n];
        rank = new int[n]{0};
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int Find(int x){
        if(parent[x] == x) return x;
        return parent[x] = Find(parent[x]);
    }

    void Union(int x,int y){
        int x_root = Find(x);
        int y_root = Find(y);
        if(x_root == y_root) return;
        if(rank[x_root]<rank[y_root]){
            parent[x_root] = y_root;
        }else if(rank[x_root]>rank[y_root]){
            parent[y_root] = x_root;
        }else{
            parent[y_root] = x_root;
            rank[x_root]++;
        }
    }

    bool isConnected(int x,int y){
        return Find(x)==Find(y);
    }
};
```

#### Time Complexity for Find and Union (worst case) : O(log(N)) // N is # of nodes
---