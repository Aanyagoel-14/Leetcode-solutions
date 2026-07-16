class Twitter {
public:
    struct Tweet {
        int id;
        int time;
        Tweet* next;

        Tweet(int tweetId, int timestamp) {
            id = tweetId;
            time = timestamp;
            next = nullptr;
        }
    };

    unordered_map<int, unordered_set<int>> followMap;
    unordered_map<int, Tweet*> tweetMap;
    int timer;

    Twitter() {
        timer = 0;
    }

    void postTweet(int userId, int tweetId) {
        Tweet* t = new Tweet(tweetId, timer++);
        t->next = tweetMap[userId];
        tweetMap[userId] = t;
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, Tweet*>> pq;

        followMap[userId].insert(userId);

        for (int user : followMap[userId]) {
            if (tweetMap.count(user))
                pq.push({tweetMap[user]->time, tweetMap[user]});
        }

        vector<int> ans;

        while (!pq.empty() && ans.size() < 10) {
            auto [time, tweet] = pq.top();
            pq.pop();

            ans.push_back(tweet->id);

            if (tweet->next)
                pq.push({tweet->next->time, tweet->next});
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId)
            followMap[followerId].erase(followeeId);
    }
};