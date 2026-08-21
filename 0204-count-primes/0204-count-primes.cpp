class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) return 0;
        
        int count = 1; // account for the prime 2
        int m = n / 2; // index i represents odd number (2*i + 1), for i = 0..m-1
        vector<char> isComposite(m, 0);
        
        for (int i = 1; (long long)(2 * i + 1) * (2 * i + 1) < n; i++) {
            if (isComposite[i] == 0) {
                long long p = 2 * i + 1;
                for (long long j = (p * p - 1) / 2; j < m; j += p) {
                    isComposite[j] = 1;
                }
            }
        }
        
        for (int i = 1; i < m; i++) { // start at 1: index 0 represents "1", not prime
            if (isComposite[i] == 0) {
                count++;
            }
        }
        
        return count;
    }
};