class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
            if(i == start || candidates[i] != candidates[i - 1]) {
                tmp.push_back(candidates[i]);
                backtracking(res, tmp, candidates, target - candidates[i], i + 1);
                tmp.pop_back();
            }
        }
    }
};