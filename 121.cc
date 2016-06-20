class Solution {
  public:
    int maxProfit(vector<int>& prices) {
      int maxpro = 0;
      int minval = INT_MAX;
      for (int i = 0; i < prices.size(); i++) {
        minval = minval < prices[i] ? minval : prices[i];
        maxpro = maxpro > prices[i] - minval ? maxpro : prices[i] - minval;
      }
      return maxpro;
    }
};

class Solution {
  public:
    int maxProfit(vector<int>& prices) {
      if (prices.size() <= 1) return 0;
      vector<int> back(prices);
      int pro = 0;
      for (int i = prices.size() - 2; i >= 0; i--)
        back[i] = prices[i] < back[i + 1] ? back[i + 1] : prices[i];
      for (int i = 0; i < prices.size(); i++)
        pro = pro < back[i] - prices[i] ? back[i] - prices[i] : pro;
      return pro;
    }
};
