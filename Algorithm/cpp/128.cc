class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> record(num.begin(), num.end());
        int res = 1;
        for (int n : num) {
            if (record.find(n) == record.end()) continue;
            record.erase(n);
            int prev = n - 1, next = n + 1;
            while (record.find(prev) != record.end()) record.erase(prev--);
            while (record.find(next) != record.end()) record.erase(next++);
            res = max(res, next - prev - 1);
        }
        return res;
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
