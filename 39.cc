class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> tmp;
        backtracking(res, tmp, candidates, target, 0);
        return res;
    }
    void backtracking(vector<vector<int>>& res, vector<int>& tmp, vector<int>& candidates,
        int target, int start){
        if(target < 0) return;
        if(target == 0) {
            res.push_back(tmp);
            return;
        }
        for(int i = start; i < candidates.size(); i++){
            tmp.push_back(candidates[i]);
            backtracking(res, tmp, candidates, target - candidates[i], i);
            tmp.pop_back();
        }
    }
};