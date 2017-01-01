class Solution {
  public:
    int removeDuplicates(vector<int>& nums) {
      vector<int>::iterator ite = nums.begin();
      int length = nums.size();
      int val, count;
      while (ite != nums.end()) {
        val = *ite;
        count = 1;
        while( ++ite != nums.end() && *ite == val) {
          count++;
          if (count == 3) {
            ite = nums.erase(ite);
            length--;
            ite--;
            count = 2;
          }
        }
      }
      return length;
    }
};

class Solution {
  public:
    int removeDuplicates(vector<int>& nums) {
      int size = nums.size();
      if (size < 3) return size;
      int i = 0, j = 1, count = 1;
      for (; j < size; j++) {
        if (nums[i] != nums[j]) {
          nums[++i] = nums[j];
          count = 1;
        } else if (count == 1) {
          nums[++i] = nums[j];
          count = 2;
        }
      }
      return i + 1;
    }
};
