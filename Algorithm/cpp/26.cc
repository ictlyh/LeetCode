class Solution {
  public:
    int removeDuplicates(vector<int>& nums) {
      if (nums.size() == 0) return 0;
      int i = 0;
      for (int j = 1;j < nums.size(); j++) {
        if (nums[i] != nums[j])
          nums[++i] = nums[j];
      }
      return i + 1;
    }
};

class Solution {
  public:
    int removeDuplicates(vector<int>& nums) {
      int length = nums.size();
      if (length < 2) return length;
      vector<int>::iterator curr = nums.begin();
      vector<int>::iterator next = nums.begin();
      next++;
      while (next != nums.end()) {
        if (*curr == *next) {
          next = nums.erase(next);
          length--;
        } else {
          curr++;
          next++;
        }
      }
      return length;
    }
};
