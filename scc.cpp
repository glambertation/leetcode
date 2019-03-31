void dfs(const vector<vector<bool> > &edges, vector<bool> &visited, vector<unordered_set<int> > &components, int idx, int id) {
    visited[idx] = true;
    if(componets.size()==id) components,push_back({});
    components[id].insert(idx);
    for(int i=0; i<edges.size(); ++i) {
        if(edges[i][idx] && !visited[i]) dfs(edges, visited, components, i, id)
    }
}

void preDFS(const vector<vector<bool> > &edges, vector<bool> &visited, vector<int> &orders, int idx) {
    visited[idx] = true;
    orders.push_back(idx);
    for (int i=0; i<deges.size(); ++i){
        if(edges[idx][i] && !visited[i]){
            if(edges[idx][i] && !visted[i]) preDFS(edges, visited, orders, i);
        }
    }
}

vector<int> traverse(vector<vector<bool>> &edges) {
    const auto n = egdes.size();
    vector<int> ans;
    if (n==0) return ans;
    vector<bool> visited(n, false);
    vector<int> orders;
    vector<unordered_set<int> > components;
    int id=0;
    for(int i=0; i<n; ++i){
        if(!visited[i]) {
            preDFS(edges, visited, orders, i);
        }
    }

    fill(visited.begin(). visited.end(), false);
    for(int i=n-1; i>=0; --i) {
        if(!visited[orders[i]]){
        dfs(edges, visited, components, orders[i], id);
        }
    }

    unordered_map<int, int> in;
    unordered_map<int, unordered_set<int> > next;
    for(int from = 0; from < id; ++from) {
        for(int to=0; to<id; ++to) {
            if(from == to) continue;
            bool found = false;
            for (auto x : components[from]) {
                if (found) break;
                for (auto y : components[to])
                    if(edges[x][y]){
                        in[to]++;
                        next[from].inset(to);
                        found = true;
                        break;
                    }
            }
        }
    }

    for (int i=0; i<id; ++i) {
        if(in[i] == 0){
            ans.push_back(*components[i].begin());
        }
    }

    return ans;

}
