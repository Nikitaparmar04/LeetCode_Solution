class Solution {
public:
    int find(int x, vector<int> &parent, vector<int> &rank)
    {
        if(x==parent[x]) return x;
        return parent[x] = find(parent[x], parent, rank);
    }
    
    bool merge(int x, int y, vector<int> &parent, vector<int> &rank)
    {
        x = find(x, parent, rank); y = find(y, parent, rank);
        if(x!=y)
        {
            parent[x] = y;
            if(rank[x]<rank[y]) swap(x,y);
            rank[x] += rank[y];
            return true;
        }
        return false;
    }
    static bool comp(vector<int> &a, vector<int> &b){
        return a[0]>b[0];
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), comp);
        vector<int> parentA(n+1,-1), rankA(n+1,1), parentB(n+1,-1), rankB(n+1,1);
        for(int i=1; i<n+1; i++)
        {
            parentA[i] = i;
            parentB[i] = i;
        }
        
        int mergedA = 1, mergedB = 1;
        int removed = 0;
        
        for(auto edge:edges)
        {
            int type = edge[0], u = edge[1], v = edge[2];
            if(type == 3){
                bool tempa = merge(u,v,parentA,rankA);
                bool tempb = merge(u,v, parentB, rankB);
                if(tempa) mergedA++;
                if(tempb) mergedB++;
                if(!tempa and !tempb) removed++;
            }
            else if(type==1){
                bool tempa = merge(u,v,parentA,rankA);                
                if(tempa) mergedA++;
                else removed++;
            }
            else{
                bool tempb = merge(u,v, parentB, rankB);                
                if(tempb) mergedB++;
                else removed++;
            }
        }
        
        if(mergedA != n || mergedB != n) return -1;
        return removed;
    }
};