class Solution {
    vector<int> parent, sz;

    int findRoot(int v) {
        if (v == parent[v]) return v;
        return parent[v] = findRoot(parent[v]);
    }

    void unite(int u, int v) {
        int pu = findRoot(u), pv = findRoot(v);
        if (pu == pv) return;
        if (sz[pu] < sz[pv]) swap(pu, pv);
        parent[pv] = pu;
        sz[pu] += sz[pv];
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        sz.assign(n, 1);

        unordered_map<string, int> owner;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                auto [it, inserted] = owner.emplace(accounts[i][j], i);
                if (!inserted) unite(i, it->second);
            }
        }

        vector<vector<string>> groups(n);
        for (int i = 0; i < n; i++) {
            int root = findRoot(i);
            for (int j = 1; j < accounts[i].size(); j++) {
                groups[root].push_back(accounts[i][j]);
            }
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (groups[i].empty()) continue;
            auto& emails = groups[i];
            sort(emails.begin(), emails.end());
            emails.erase(unique(emails.begin(), emails.end()), emails.end());
            vector<string> curr{accounts[i][0]};
            curr.insert(curr.end(), make_move_iterator(emails.begin()),
                        make_move_iterator(emails.end()));
            ans.push_back(move(curr));
        }
        return ans;
    }
};