class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> buf(nums.begin(), nums.end());
        vector<int> result;
        int p = -1, q = -1;
        sort(buf.begin(), buf.end());
        for(int i = 0,j = buf.size() - 1; i < j;) {
            if(buf[i] + buf[j] == target) {
                p = buf[i];
                q = buf[j];
                break;
            }
            else if(buf[i] + buf[j] < target)
                i++;
            else j--;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == p || nums[i] == q)
                result.push_back(i);
        }
        return result;
    }
};