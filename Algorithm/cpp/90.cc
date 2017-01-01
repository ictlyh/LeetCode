class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> tmp;
        backtracking(res, tmp, nums, 0);
        return res;
    }
    void backtracking(vector<vector<int>>& res, vector<int> tmp, vector<int>& nums, int begin){
        res.push_back(tmp);
        for(int i = begin; i < nums.size(); i++){
            if(i == begin || nums[i] != nums[i - 1]){
                tmp.push_back(nums[i]);
                backtracking(res, tmp, nums, i + 1);
                tmp.pop_back();
            }
        }
    }
};