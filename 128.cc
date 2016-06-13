class Solution {
  public:
    int longestConsecutive(vector<int>& nums) {
      unordered_set<int> st(nums.begin(),nums.end());
      int ret = 0;
      while (st.size()) {
        int x = st.front();
        int left = x, right = x + 1;
        while (st.count(left))
          st.erase(left--);
        while (st.count(right))
          st.erase(right++);
        ret = max(ret, right - left  - 1);
      }
      return ret;
    }
};
class Solution {
  public:
    int longestConsecutive(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      int longest = 1;
      int length = 1;
      for (int i = 1; i < nums.size(); i++) {
        if (nums[i - 1] == nums[i]) continue;
        else if (nums[i - 1] + 1 == nums[i])
          length++;
        else {
          longest = longest > length ? longest : length;
          length = 1;
        }
      }
      longest = longest > length ? longest : length;
      return longest;
    }
};
