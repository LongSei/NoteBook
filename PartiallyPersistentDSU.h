// Partially persistent DSU
// - Version t+1 always build on top of version t
// - Query history information at version t
// Tested:
// - https://oj.vnoi.info/problem/vnoicup22_r2_c

int unite[MAX], par[MAX], siz[MAX];
void init() {
	for (int i = 1; i <= n; i++) {
		par[i] = i;
		siz[i] = 1;
		unite[i] = INF;
	}
}
int findset(int t, int node) {
	if (unite[node] > t) {
		return node;
	}
	return findset(t, par[node]);
}
bool issameset(int t, int u, int v) {
	return findset(t, u) == findset(t, v);
}
void unionset(int t, int u, int v) {
	u = findset(t, u);
	v = findset(t, v);
	if (u == v) {
		return;
	}
	if (siz[u] > siz[v]) {
		swap(u, v);
	}
	par[u] = v;
	unite[u] = t;
	siz[v] += siz[u];
}