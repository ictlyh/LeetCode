

// Time Limit Exceeded
class Twitter {
  private:
    vector<pair<int, int>> posts;
    unordered_map<int, vector<int>> follows;
  public:
    /** Initialize your data structure here. */
    Twitter() {
      posts.clear();
      follows.clear();
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
      posts.push_back(make_pair(userId, tweetId));
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
      vector<int> res;
      int j = posts.size() - 1;
      for (int i = 0; i < 10; i++) {
        for (;j >= 0; j--) {
          if (posts[j].first == userId)
            res.push_back(posts[j].second);
          else if (follows.find(userId) == follows.end())
            continue;
          else {
            for (int user : follows[userId])
              if (user == posts[j].first)
                res.push_back(posts[j].second);
          }
        }
        if (j < 0) break;
      }
      return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
      if (follows.find(followerId) == follows.end())
        follows[followerId] = vector<int>(1, followeeId);
      else {
        for (int user : follows[followerId])
          if (user == followeeId) return;
        follows[followerId].push_back(followeeId);
      }
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
      if (follows.find(followerId) == follows.end())
        return;
      for (vector<int>::iterator ite = follows[followerId].begin();
          ite != follows[followerId].end(); ite++)
        if (*ite == followeeId) {
          follows[followerId].erase(ite);
          break;
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
