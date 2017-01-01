class Solution {
  public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int, int> freq;
      for (auto n : nums) freq[n]++;
      vector<pair<int, int>> pairs;
      for (auto f : freq) pairs.push_back(f);
      sort(pairs.begin(), pairs.end(), [=](pair<int, int>& a, pair<int, int>& b)
          { return a.second > b.second; });
      vector<int> res;
      for (int i = 0;  i < k; i++) res.push_back(pairs[i].first);
      return res;
    }
};
