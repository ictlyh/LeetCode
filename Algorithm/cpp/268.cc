class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing = 0;
        for (int i = 0; i < nums.size(); i++)
            missing ^= i ^ nums[i];
        return missing ^ nums.size();
    }
};
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += i - nums[i];
        return sum + nums.size();
    }
};
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        return nums.size() * (nums.size() + 1) / 2 - sum;
    }
};
