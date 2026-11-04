class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        vector<vector<int>>adj(wordList.size());
        map<string,int>mp;
        for(int i=0;i<wordList.size();i++){
            mp[wordList[i]]=i;
        }
        if(mp.find(endWord)==mp.end())return 0;
        int last=mp[endWord];
        int sz=beginWord.size();
        for(int i=0;i<wordList.size();i++){
            int index=mp[wordList[i]];
            for(int k=0;k<sz;k++){
                for(int j=0;j<26;j++){
                    string newWord=wordList[i];
                    newWord[k]='a'+j;
                    if(newWord == wordList[i]) continue;
                    if(mp.find(newWord)!=mp.end()){
                        adj[index].push_back(mp[newWord]);
                    }
                }
            }
        }
        queue<int>q;
        q.push(mp[beginWord]);
        int step=2;
        vector<int>visited(wordList.size(),0);
        visited[mp[beginWord]]=1;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int curr=q.front();
                q.pop();
                for(int j=0;j<adj[curr].size();j++){
                    if(adj[curr][j]==last)return step;
                    if(visited[adj[curr][j]]==0){
                        q.push(adj[curr][j]);
                        visited[adj[curr][j]]=1;
                    }
                    
                }
            }
            step++;
           
        }
        return 0;

    }
};