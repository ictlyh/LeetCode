class Solution {
  public:
    void moveZeroes(vector<int>& nums) {
      int i = 0, j = 0;
      for (; j < nums.size();) {
        if (nums[j]) nums[i++] = nums[j];
        j++;
      }
      while (i < nums.size())
        nums[i++] = 0;
    }
};


class Solution {
  public:
    void moveZeroes(vector<int>& nums) {
      vector<int>::iterator begin = nums.begin();
      vector<int>::iterator end;
      while (true) {
        while (begin != nums.end() && *begin) begin++;
        if (begin == nums.end()) return;
        end = begin + 1;
        while (end != nums.end() && !*end) end++;
        if (end == nums.end()) return;
        swap(*begin, *end);
        begin++;
      }
    }
};
