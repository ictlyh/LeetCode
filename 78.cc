class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        auto n = int(pow(2, nums.size()));

        for (auto i = 0; i < n; ++i) {
            vector<int> subset;
            auto x = i, j = 0;
            while (x) {
                if (x & 1) subset.push_back(nums[j]);
                ++j;
                x >>= 1;
            }
            res.push_back(subset);
        }
        return res;
    }
};