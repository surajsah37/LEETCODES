class Twitter {
    private:
    int timeStamp; // to keep track of time for tweets
    
    // followers[followerId] = set of followees that this user is following
    unordered_map<int, unordered_set<int>> followers;
    
    // tweets[userId] = vector of {time, tweetId}
    unordered_map<int, vector<pair<int,int>>> tweets;

public:
    Twitter() {
        timeStamp=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>pq;
        // add user's own tweets into heap
        for (auto &t : tweets[userId]) {
            pq.push(t); // (time, tweetId)
        }
        
        // add all followees' tweets into heap
        for (int followeeId : followers[userId]) {
            for (auto &t : tweets[followeeId]) {
                pq.push(t);
            }
        }
         // now extract top 10 recent tweets
        vector<int> feed;
        int count = 0;
        
        while (!pq.empty() && count < 10) {
            feed.push_back(pq.top().second); 
            pq.pop();  
            count++;   
        }
        
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
         if (followerId != followeeId) 
            followers[followerId].insert(followeeId); 
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followers[followerId].count(followeeId)) 
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