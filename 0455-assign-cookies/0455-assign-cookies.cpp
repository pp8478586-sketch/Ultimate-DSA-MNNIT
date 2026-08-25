class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int begin=0;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(begin<g.size()&&s[i]>=g[begin]){
                count++;
                begin++;
            }
        }
        return count;
    }
};