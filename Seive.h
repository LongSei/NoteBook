int primeFactor[MAX];
vector<int> prime;
void seive(int n) {
    for (int i = 2; i <= n; i++) {
        if (primeFactor[i] == 0) {
            primeFactor[i] = i;
            prime.push_back(i);
            int q = i + i;
            while (q <= n) {
                primeFactor[q] = i;
                q += i;
            }
        }
    }
}