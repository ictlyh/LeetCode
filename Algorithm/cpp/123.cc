

// Time Limit Exceeded
class Solution {
  public:
    int maxProfitHelper(vector<int>& prices, int begin, int end) {
      int profit = 0;
      int min = INT_MAX;
      for (int i = begin; i <= end; i++) {
        min = min < prices[i] ? min : prices[i];
        profit = prices[i] - min > profit ? prices[i] - min : profit;
      }
      return profit;
    }

    int maxProfit(vector<int>& prices) {
      int size = prices.size();
      if (size < 2) return 0;
      int profit = 0;
      int minIdx = 0;
      bool calcTail = true;
      for (int i = 0; i < size - 1; i++) {
        int head = maxProfitHelper(prices, minIdx, i);
        int tail = 0;
        if (calcTail) tail = maxProfitHelper(prices, i, size - 1);
        profit = head + tail > profit ? head + tail : profit;
        if (head == 0 && tail == 0) return 0;
        if (head == 0) minIdx = i;
        if (tail == 0) calcTail = false;
      }
      return profit;
    }
};
