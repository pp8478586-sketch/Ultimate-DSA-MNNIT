class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int begin=0;
        int maxFruit=0;
        unordered_map<int,int>mp;
        for (int i=0;i<fruits.size();i++){
            mp[fruits[i]]++;
            while(mp.size()>2){
                mp[fruits[begin]]--;
                if(mp[fruits[begin]]==0){
                    mp.erase(fruits[begin]);
                }
                begin++;
            }
            maxFruit=max(maxFruit,i-begin+1);
        }
        return maxFruit;
    }
};