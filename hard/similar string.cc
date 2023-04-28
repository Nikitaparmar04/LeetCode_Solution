class Solution {
public:
    struct DSU
    {
        vector<int> p, rank;
        DSU(int n) : p(n + 1), rank(n + 1) { iota(p.begin(), p.end(), 0); }
        int find(int x) { return p[x] == x ? p[x] : p[x] = find(p[x]); }
        void unite(int x, int y)
        {
            x = find(x), y = find(y);
            if (rank[x] > rank[y]) swap(x, y);
            p[x] = y;
            rank[x] += rank[x] == rank[y];
        }
    };

    bool check (string& a, string& b)
    {
        int cnt = 0;
        for (int i = 0; i < a.size(); ++i)
        {
            if (a[i] != b[i]) ++cnt;
            if (cnt > 2) return false;
        }
        return cnt == 2 || cnt == 0;
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size(), res = n;
        DSU dsu(n);
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (check(strs[i], strs[j]))
                    if (dsu.find(i) != dsu.find(j))
                        dsu.unite(i, j), --res;
        return res;
    }
};