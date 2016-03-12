class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> backup(nums);
        int size = nums.size();
        for (int i = 0; i < size; i++)
            nums[(i + k) % size] = backup[i];
    }
};