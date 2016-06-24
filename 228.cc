class Solution {
  public:
    vector<string> summaryRanges(vector<int>& nums) {
      vector<string> ans;
      for (int i = 0; i < nums.size(); ) {
        int j = 1;
        stringstream ss;
        ss << nums[i];
        while (i + j < nums.size() && nums[i + j] - nums[i + j - 1] == 1)
          j++;
        if (j == 1) {
          ans.push_back(ss.str());
          i++;
        } else {
          ss << "->" << nums[i + j - 1];
          ans.push_back(ss.str());
          i = i + j;
        }
      }
      return ans;
    }
};
