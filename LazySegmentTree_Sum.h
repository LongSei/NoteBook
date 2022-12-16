// Lazy segment tree using for solve sum problems
// Tested: https://oj.vnoi.info/problem/bedao_g11_easyquery

struct Node {
    int lazy;
    int val;
} st[MAX * 4];

void push_down(int v, int tl, int tr) {
    if (st[v].lazy != 0) {
        int t = st[v].lazy;
        st[v].val += (tr - tl + 1) * t;
        st[v].lazy = 0;
        if (tl != tr) {
            st[v * 2 + 1].lazy += t;
            st[v * 2 + 2].lazy += t;
        }
    }
}

void update(int v, int tl, int tr, int l, int r, int val) {
    push_down(v, tl, tr);
    if (tl > r || tr < l) {
        return;
    }
    if (l <= tl && tr <= r) {
        st[v].val += (tr - tl + 1) * val;
        if (tl != tr) {
            st[v * 2 + 1].lazy += val;
            st[v * 2 + 2].lazy += val;
        }
        return;
    }
    int mid = (tl + tr) >> 1;
    update(v * 2 + 1, tl, mid, l, r, val);
    update(v * 2 + 2, mid + 1, tr, l, r, val);
    st[v].val = st[v * 2 + 1].val + st[v * 2 + 2].val;
}

int query(int v, int tl, int tr, int l, int r) {
    push_down(v, tl, tr);
    if (tl > r || tr < l) {
        return 0;
    }
    if (l <= tl && tr <= r) {
        return st[v].val;
    }
    int mid = (tl + tr) >> 1;
    int ll = query(v * 2 + 1, tl, mid, l, r);
    int rr = query(v * 2 + 2, mid + 1, tr, l, r);
    return (ll + rr);
}