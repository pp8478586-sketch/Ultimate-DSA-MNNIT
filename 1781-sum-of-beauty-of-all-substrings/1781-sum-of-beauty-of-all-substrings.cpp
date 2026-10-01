class Solution {
public:
    int beautySum(string s) {
        int sum=0;
        for(int i=0;i<s.size();i++){
            vector<int>map(26,0);
            for(int j=i;j<s.size();j++){
                map[s[j]-'a']++;
                int max_freq=0;
                int min_freq=INT_MAX;
                for(int k=0;k<26;k++){
                    if(map[k]>max_freq){
                        max_freq=map[k];
                    }
                    if(map[k]!=0&&map[k]<min_freq){
                        min_freq=map[k];
                    }
                }
                sum=sum+max_freq-min_freq;
            }
        }
        return sum;
    }
};