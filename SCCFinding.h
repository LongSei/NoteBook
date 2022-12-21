// Finding Strongly Connected Component
// Time complexity: O(V + E)

int disc[MAX], low[MAX], tjtimer = 0;
stack<int> st; 
vector<int> adjlist[MAX];
void tarjan(int pos) {
    disc[pos] = low[pos] = ++tjtimer;
    st.push(pos);
    for (int v : adjlist[pos]) {
        if (disc[v]) {
            low[pos] = min(low[pos], disc[v]);
        }
        else {
            tarjan(v);
            low[pos] = min(low[v], low[pos]);
        }
    }
    if (low[pos] == disc[pos]) {
        int indx;
        ans++;
        do {
            indx = st.top();
            st.pop();
            disc[indx] = low[indx] = INT_MAX;
        } while (indx != pos);
    }
}