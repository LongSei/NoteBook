// Source: https://codeforces.com/blog/entry/71146
// Time complexity: O(V + E)
// Tested: 
// - https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=251
vector<int> adjlist[MAX];
int low[MAX], disc[MAX], APtimer = 0;
bool ap[MAX];

int dfsAP(int node, int parent) {
    int children = 0;
    low[node] = disc[node] = ++APtimer;
    for (int v : adjlist[node]) {
        if (v == parent) {continue;}
        if (disc[v] == 0) {
            children += 1;
            dfsAP(v, node);
            if (disc[node] <= low[v]) {
                ap[node] = true;
            }
            low[node] = min(low[node], low[v]);
        }
        else {
            low[node] = min(low[node], disc[v]);
        }
    }
    return children;
}

void findAP() {
    APtimer = 0;
    for (int i = 1; i <= n; i++)
      if (!disc[i]) {
        ap[i] = dfsAP(i, i) > 1; 
      }
}