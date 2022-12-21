// Preparing and finding "Lowest Common Ancestor"
// Time complexity: Prepare: O(NlogN), Finding: O(logN)
// Tested: 
// - https://oj.vnoi.info/problem/pwalk

int tin[MAX], tout[MAX], lcaTimer = 0, up[MAX][21];
vector<int> adjlist[MAX];
void dfs(int v, int p) {
    tin[v] = ++lcaTimer;
    up[v][0] = p;
    for (int i = 1; i <= ceil(log2(n)); ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adjlist[v]) {
        if (u != p) {
            dfs(u, v);
        }
    }
    tout[v] = ++lcaTimer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int LCA(int u, int v) {
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = ceil(log2(n)); i >= 0; --i) {
        if (!is_ancestor(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return up[u][0];
}