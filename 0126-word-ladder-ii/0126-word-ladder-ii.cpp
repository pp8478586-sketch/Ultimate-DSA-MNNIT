class Solution {
    void dfs(unordered_map<string,vector<string>>&parent,string curr ,string &beginWord,vector<vector<string>>&ans,vector<string>temp){
        temp.push_back(curr);
        if(curr==beginWord){
            reverse(temp.begin(),temp.end());
            ans.push_back(temp);
            return ;
        }
        for(string it:parent[curr]){
            dfs(parent,it,beginWord,ans,temp);
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<string>>parent;
        queue<string>q;
        q.push(beginWord);
        unordered_set<string>st;
        vector<vector<string>>ans;
        for(int i=0;i<wordList.size();i++){
            st.insert(wordList[i]);
        }
        if(!st.count(endWord))return ans;
        st.erase(beginWord);
        bool found =false;
        while(!q.empty()){
            int sz=q.size();
            unordered_set<string>onLevel;
            for(int i=0;i<sz;i++){
                string curr=q.front();
                q.pop();
                for(int j=0;j<beginWord.size();j++){
                    char ch=curr[j];
                    string original=curr;
                    for(char c='a';c<='z';c++){
                        curr[j]=c;
                        if(curr==endWord){
                            found=true;
                            parent[curr].push_back(original);
                        }
                        else if(st.count(curr)){
                            parent[curr].push_back(original);
                            if(!onLevel.count(curr)){
                                q.push(curr);
                                onLevel.insert(curr);
                            }
                            
                        }
                    }
                    curr[j]=ch;
                }
            }
            if(found){
                break;
            }
            for(auto &x:onLevel){
                st.erase(x);
            }
        }

        if(found){
             vector<string>temp;
             dfs(parent,endWord,beginWord,ans,temp);

        }
        return ans;
       
        
    }
};