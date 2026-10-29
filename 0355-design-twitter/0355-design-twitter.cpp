class Twitter {
    int tweetIdCounter=0;
    unordered_map<int,vector<pair<int,int>>>mp;
    unordered_map<int,unordered_set<int>>following;
public:
    Twitter(){
        
    }
    void postTweet(int userId, int tweetId) {
        mp[userId].push_back({tweetId,tweetIdCounter++});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        unordered_set<int>list=following[userId];
        list.insert(userId);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>mostRecent;
        int i=0;
        while(i<10){
            for(int x:list){
                int sz=mp[x].size();
                if(sz-i-1>=0){
                    int tweetId=mp[x][sz-i-1].first;
                    int time=mp[x][sz-i-1].second;
                    mostRecent.push({time,tweetId});
                }
                if(mostRecent.size()>10){
                    mostRecent.pop();
                }
            }
            i++;
        }
        while(!mostRecent.empty()){
            auto curr=mostRecent.top();
            mostRecent.pop();
            ans.push_back(curr.second);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */