class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) return 0;
        
        vector<char> arr(n, 1);
        arr[0] = arr[1] = 0;
        
        for (int i = 4; i < n; i += 2) {
            arr[i] = 0;
        }
        
        for (int i = 3; (long long)i * i < n; i += 2) {
            if (arr[i]) {
                for (long long j = (long long)i * i; j < n; j += 2 * i) {
                    arr[j] = 0;
                }
            }
        }
        
        int count = 1;
        for (int i = 3; i < n; i += 2) {
            if (arr[i]) count++;
        }
        
        return count;
    }
};