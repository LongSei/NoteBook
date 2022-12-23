// Time complexity: O(V + E)
// Tested (Articulation Point):
// - https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=251
// Tested (Bridge): 
// - https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=551

vector<int> adjlist[MAX];
int low[MAX], disc[MAX], lltimer = 0;
bool artiPoint[MAX];
vector<ii> bridge;

int dfsLowLink(int node, int parent) {
    int children = 0;
    low[node] = disc[node] = ++lltimer;
    for (int v : adjlist[node]) {
        if (v == parent) {continue;}
        if (disc[v] == 0) {
            children += 1;
            dfsLowLink(v, node);
            if (disc[node] <= low[v]) {
                artiPoint[node] = true;
            }
            if (disc[node] < low[v]) {
                bridge.pb(ii(node, v));
            }
            low[node] = min(low[node], low[v]);
        }
        else {
            low[node] = min(low[node], disc[v]);
        }
    }
    return children;
}

void processLowLink(int n) {
    lltimer = 0;
    for (int i = 1; i <= n; i++)
      if (!disc[i]) {
        if (dfsLowLink(i, i) > 1) {artiPoint[i] = true;} 
      }
}