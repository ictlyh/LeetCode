class Solution {
  public:
    int FindGreatestSumOfSubArray(vector<int> array) {
      if (array.size() == 0) return 0;
      int maxseq = INT_MIN;
      int sum = 0;
      for (int num : array) {
        if (sum > 0) sum += num;
        else sum = num;
        maxseq = max(sum, maxseq);
      }
      return maxseq;
    }
};
