class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]-'A']++;
        }
        int maxFreq=*max_element(freq.begin(),freq.end());
        int maxCount=count(freq.begin(),freq.end(),maxFreq);
        int ans=(maxFreq-1)*(n+1)+maxCount;
        ans= max(ans,int(tasks.size()));
        return ans;
    }
};