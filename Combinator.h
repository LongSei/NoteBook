// Combinator Caculator
// Prepared: O(n), Calculate: O(1)
// Tested: 
// - https://codeforces.com/contest/1763/problem/D
int fact[MAX], inv[MAX];

void init(int n) {
    fact[0] = inv[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact[i] = 1LL * fact[i - 1] * i % mod;
		inv[i] = fast_pow(fact[i], mod - 2);
	}
}
int C(int k, int n) {
	if (n < k) return 0;
	return 1LL * fact[n] * inv[k] % mod * inv[n - k] % mod;
}