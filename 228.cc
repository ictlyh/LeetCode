class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        for(int i = 0; i < nums.size(); ) {
            int j = 1;
            char tmp[10];
            sprintf(tmp, "%d", nums[i]);
            while(i + j < nums.size() && nums[i + j] - nums[i + j - 1] == 1)
                j++;
            if(j == 1) {
                string stmp(tmp);
                ans.push_back(stmp);
                i++;
            }
            else {
                strcat(tmp, "->");
                string stmp(tmp);
                sprintf(tmp, "%d", nums[i + j - 1]);
                stmp.append(tmp);
                ans.push_back(stmp);
                i = i + j;
            }
        }
        return ans;
    }
};