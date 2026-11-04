class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       unordered_set<string>st;
       for(int i=0;i<wordList.size();i++){
            st.insert(wordList[i]);
       }
       queue<string>q;
       q.push(beginWord);
       st.erase(beginWord);
       int step=2;
       if(!st.count(endWord))return 0;
       while(!q.empty()){
            int sz=q.size();
            for(int k=0;k<sz;k++){
                string newWord=q.front();
                q.pop();
                for(int j=0;j<beginWord.size();j++){
                    for(int s=0;s<26;s++){
                        string temp=newWord;
                        temp[j]='a'+s;
                        if(temp==endWord)return step;
                        if(st.count(temp)){
                            q.push(temp);
                            st.erase(temp);
                        }
                    }
                }
            }
            step++;
       }
       return 0;
    }
};