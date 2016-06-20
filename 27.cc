class Solution {
  public:
    int removeElement(vector<int>& nums, int val) {
      int i = 0;
      for (int j = 0; j < nums.size(); j++) {
        if (nums[j] != val)
          nums[i++] = nums[j];
      }
      return i;
    }
};


class Solution {
  public:
    int removeElement(vector<int>& nums, int val) {
      int length = nums.size();
      for(int i = 0; i < length; i++) {
        if (nums[i] == val) {
          nums[i] = nums[--length];
          i--;
        }
      }
      return length;
    }
};
