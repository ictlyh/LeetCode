class Solution {
  public:
    int candy(vector<int>& ratings) {
      int size = ratings.size();
      if (size < 2) return size;
      vector<int> candies(size, 1);
      for (int i = 0; i < size - 1; i++) {
        if (ratings[i + 1] > ratings[i])
          candies[i + 1] = candies[i] + 1;
      }
      for (int i = size - 1; i > 0; i--) {
        if (ratings[i - 1] > ratings[i])
          candies[i - 1] = max(candies[i - 1], candies[i] + 1);
      }
      int sum = 0;
      for (int cand : candies)
        sum += cand;
      return sum;
    }
};
