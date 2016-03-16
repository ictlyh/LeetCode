class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> nums;
        for (int i = 1; i < 10; i++)
            nums.push_back(i);
        vector<int> tmp;
        backtracking(res, tmp, nums, k, n, 0);
        return res;
    }
    void backtracking(vector<vector<int>>& res, vector<int>& tmp,
        vector<int> nums, int k, int target, int start) {
        if(target < 0) return;
        if(target == 0 && tmp.size() == k) {
            res.push_back(tmp);
            return;
        }
        for(int i = start; i < nums.size(); i++){
            tmp.push_back(nums[i]);
            backtracking(res, tmp, nums, k, target - nums[i], i + 1);
            tmp.pop_back();
        }
    }
};