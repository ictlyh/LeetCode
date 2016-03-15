class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator ite = nums.begin();
        int length = nums.size();
        int val, count;
        while (ite != nums.end()) {
            val = *ite;
            count = 1;
            while( ++ite != nums.end() && *ite == val) {
                count++;
                if (count == 3) {
                    ite = nums.erase(ite);
                    length--;
                    ite--;
                    count = 2;
                }
            }
        }
        return length;
    }
};