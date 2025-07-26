class Twitter {
public:
    int time=0;
    unordered_map<int,unordered_set<int>>followers;
    unordered_map<int,vector<pair<int,int>>>db;
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        db[userId].push_back({time,tweetId});
      
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>pq;
        for(auto &it: db[userId]){
            pq.push(it);
        }
        for(int f:followers[userId]){
            if(f==userId)continue;
            for(auto &it : db[f]){
                pq.push(it);
            }
        }
        vector<int>res;
        int cnt=0;
        while(!pq.empty() && cnt<10){
            res.push_back(pq.top().second);
            pq.pop();
            cnt++;
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);

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