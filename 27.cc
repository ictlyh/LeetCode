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