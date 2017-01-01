class Solution {
  public:
    int firstMissingPositive(vector<int>& nums) {
      vector<bool> exist(nums.size(), false);
      for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0 && nums[i] <= nums.size())
          exist[nums[i] - 1] = true;
      }
      for (int i = 0; i < nums.size(); i++)
        if (!exist[i]) return i + 1;
      return nums.size() + 1;
    }
};
int firstMissingPositive(vector<int>& nums) {
  int n = nums.size();
  int p = 0;
  int expected = 1;

  //pseudo sort
  while (p < n) {
    int pPos;
    int aux;

    if (nums[p] > 0 && nums[p] <= n) {
      pPos = nums[p] - 1;
      if (nums[pPos] != nums[p]) {
        aux = nums[p];
        nums[p] = nums[pPos];
        nums[pPos] = aux;
        p--;
      }
    }

    p++;
  }

  //Finding the answer
  for (size_t i = 0; i < n && nums[i] == expected; i++, expected++);

  return expected;
}
