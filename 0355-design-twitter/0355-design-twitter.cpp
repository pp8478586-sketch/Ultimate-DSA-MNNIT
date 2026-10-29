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
        priority_queue<array<int,4>>pq;
        for(int x:list){
            if(mp.count(x)&&!mp[x].empty()){
                int sz=mp[x].size();
                int idx=sz-1;
                pq.push({mp[x][idx].second,mp[x][idx].first,idx,x});
            }
        }
        while(!pq.empty()&&ans.size()<10){
            auto [time,tweetId,idx,x]=pq.top();
            pq.pop();
            ans.push_back(tweetId);
            if(idx>0){
                pq.push({mp[x][idx-1].second,mp[x][idx-1].first,idx-1,x});
            }
        }
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