class Solution {
  public:
    void reverse(vector<int>& nums, int s, int e) {
      while (s < e) {
        int tmp = nums[s];
        nums[s] = nums[e];
        nums[e] = tmp;
        s++;
        e--;
      }
    }
    void rotate(vector<int>& nums, int k) {
      reverse(nums, 0, nums.size() - k % nums.size() - 1);
      reverse(nums, nums.size() - k % nums.size(), nums.size() - 1);
      reverse(nums, 0, nums.size() - 1);
    }
};

class Solution {
  public:
    void rotate(vector<int>& nums, int k) {
      vector<int> backup(nums);
      int size = nums.size();
      for (int i = 0; i < size; i++)
        nums[(i + k) % size] = backup[i];
    }
};
